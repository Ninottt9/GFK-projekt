#include "include/Draw.h"
#include "include/MainFrame_Interface.h"
#include "include/VectorMatrix.h"
#include "include/Primitives.h"
#include <fstream>
#include <array>

void draw_space(Config& config, std::vector<Segment>& data, wxPanel* draw_canvas, wxBitmap& _pic, wxImage& MyImage) {

	wxClientDC _dc(draw_canvas);
	wxBufferedDC dc(&_dc, _pic);

	dc.SetBackground(*wxGREY_BRUSH);
	dc.Clear();


	double scl_x = config.GetScale() / 100;
	double scl_y = config.GetScale() / 100;
	double scl_z = config.GetScale() / 100;

	// rysowanie w czasie przeciagniecia myszy
	double speed = 5.;							// szybkoœæ obrotu
	double l_rot_x = 0;
	double l_rot_y = 0;
	if (config.GetPressed()) {
		l_rot_y = speed * atan((config.GetStartY() - config.GetEndY()) / draw_canvas->GetSize().GetHeight());
		l_rot_x = speed * atan((config.GetStartX() - config.GetEndX()) / draw_canvas->GetSize().GetWidth());
	}

	// transformacja obiektu aby znajdowal sie mniej wiecej w srodku ekranu
	double tr_x = 0.;
	double tr_y = 0.5;
	double tr_z = 10.;

	Multiplication_Matrix scale(scl_x, scl_y, scl_z);
	Translation_Matrix translation(tr_x, tr_y, tr_z);
	XRotate_Matrix xlocal(l_rot_x);
	YRotate_Matrix ylocal(l_rot_y);
	Matrix4 rotation = config.GetRotation();

	Matrix4 transform1 = translation * xlocal * ylocal * rotation * scale; // transformacja obiektu w przestrzeni

	Matrix4 m6;
	m6.data[0][0] = 1.0 / 2.0; 
	m6.data[1][1] = 1;
	m6.data[3][2] = 1.0 / 2.0;

	Matrix4 m7;
	m7.data[0][0] = draw_canvas->GetSize().GetWidth() / 2;
	m7.data[1][1] = -draw_canvas->GetSize().GetHeight() / 2;
	m7.data[0][3] = draw_canvas->GetSize().GetWidth() / 2;
	m7.data[1][3] = draw_canvas->GetSize().GetHeight() / 2;

	Matrix4 transform2 = m7 * m6; // transformacja obiektu na oknie - prz. swiat - okno

	// wyliczenie punktu najblizszego i najdalszego - (do celu rysowania na pasku odciecia)
	std::array<Point, 8> box = {
		Point(config.GetX_Min(), config.GetY_Min(), config.GetZ_Min()),
		Point(config.GetX_Min(), config.GetY_Max(), config.GetZ_Min()),
		Point(config.GetX_Min(), config.GetY_Min(), config.GetZ_Max()),
		Point(config.GetX_Min(), config.GetY_Max(), config.GetZ_Max()),
		Point(config.GetX_Max(), config.GetY_Min(), config.GetZ_Min()),
		Point(config.GetX_Max(), config.GetY_Max(), config.GetZ_Min()),
		Point(config.GetX_Max(), config.GetY_Min(), config.GetZ_Max()),
		Point(config.GetX_Max(), config.GetY_Max(), config.GetZ_Max()),
	};

	double max = -1000;
	double min = 1000;

	for (Point& point : box) {
		Vector4 vec, result;
		vec.Set(point.x, point.y, point.z);
		result = transform1 * vec;
		
		double dist = result.GetZ();
		if (dist < min) {
			min = dist;
		}
		else if (dist > max) {
			max = dist;
		}
	}

	//skala wprowadzona aby wszystko prawidlowo sie rysowalo
	double bar_scale = 5;
	config.SetFurthest(bar_scale * max);
	config.SetNearest(bar_scale * min);


	// rysowanie strzalek z pamieci
	for (Segment segment : data) {
		transform_line(transform1, &segment);
		Vector4 startPoint, endPoint;
		startPoint.Set(segment.begin.x, segment.begin.y, segment.begin.z);
		endPoint.Set(segment.end.x, segment.end.y, segment.end.z);
		
		// Odciecie
		if (config.isPlaneEnable() && startPoint.GetZ() > config.GetFarPlane()) {
			continue;
		}

		double r = segment.color.R;
		double g = segment.color.G;
		double b = segment.color.B;
		dc.SetPen(wxPen(wxColour(r, g, b)));

		// usuniecie strzalek spoza obszaru widocznosci i dostowanie jej dlugosci
		double clipping = -2.0;
		if ((startPoint.GetZ() > clipping && endPoint.GetZ() <= clipping) || (endPoint.GetZ() > clipping && startPoint.GetZ() <= clipping)) {
			
			Vector4 temp1 = endPoint.GetZ() <= clipping ? endPoint : startPoint;
			Vector4 temp2 = endPoint.GetZ() <= clipping ? startPoint : endPoint;
			double r = abs((clipping - temp1.data[2]) / (temp2.data[2] - temp1.data[2]));
			temp1.data[0] = (temp2.data[0] - temp1.data[0]) * r + temp1.data[0];
			temp1.data[1] = (temp2.data[1] - temp1.data[1]) * r + temp1.data[1];
			temp1.data[2] = clipping;

			startPoint = transform2 * temp1;
			endPoint = transform2 * temp2;

			startPoint.data[0] /= startPoint.data[3];
			startPoint.data[1] /= startPoint.data[3];
			startPoint.data[2] /= startPoint.data[3];

			endPoint.data[0] /= endPoint.data[3];
			endPoint.data[1] /= endPoint.data[3];
			endPoint.data[2] /= endPoint.data[3];
		
		}
		else if (startPoint.GetZ() <= clipping && endPoint.GetZ() <= clipping) {
			continue;
		}
		else {
			startPoint = transform2 * startPoint;
			endPoint = transform2 * endPoint;

			startPoint.data[0] /= startPoint.data[3];
			startPoint.data[1] /= startPoint.data[3];
			startPoint.data[2] /= startPoint.data[3];

			endPoint.data[0] /= endPoint.data[3];
			endPoint.data[1] /= endPoint.data[3];
			endPoint.data[2] /= endPoint.data[3];
		}
		// funkcja rysujaca
		dc.DrawLine(startPoint.GetX(), startPoint.GetY(), endPoint.GetX(), endPoint.GetY());
	}
}



// Transformowanie odcinka za pomoca macierzy
void transform_line(const Matrix4& transform, Segment* seg) {
	Vector4 vec, result, result2;

	vec.Set(seg->begin.x, seg->begin.y, seg->begin.z);

	result = transform * vec;
	seg->begin.x = result.GetX() / result.data[3];
	seg->begin.y = result.GetY() / result.data[3];
	seg->begin.z = result.GetZ() / result.data[3];

	vec.Set(seg->end.x, seg->end.y, seg->end.z);
	result2 = transform * vec;
	seg->end.x = result2.GetX() / result.data[3];
	seg->end.y = result2.GetY() / result.data[3];
	seg->end.z = result2.GetZ() / result.data[3];
}



/* ======================================================================================= */

// Wczytanie ksztaltu strzalki - format geo
bool load_model(std::string str, MainFrame_Interface& mainframe) {
	double x1, y1, z1, x2, y2, z2;
	int r, g, b;

	std::ifstream in(str);
	if (in.is_open())
	{
		mainframe.data.clear();
		while (!in.eof())
		{
			in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
			mainframe.arrow.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
		}
		in.close();
		return true;
	}
	else {
		return false;
	}
}

// uzupelnienie pamieci strzalkami wedlug parametrow
void create_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow) {
	double min_size = 2000;
	double max_size = 0;
	for(double z = config.GetZ_Min(); z < config.GetZ_Max(); z += config.GetCutLen())
		for(double x = config.GetX_Min(); x < config.GetX_Max(); x += config.GetCutLen())
			for (double y = config.GetY_Min(); y < config.GetY_Max(); y += config.GetCutLen()) {
				double dir_x, dir_y, dir_z;
				dir_x = x, dir_y = y, dir_z = z;

				if (config.GetCurrentFun()) {
					config.GetCurrentFun()->Transform(dir_x, dir_y, dir_z); // Wyliczenie d³ugosci strza³ki w danym kierunku (x,y,z)->(v_x, v_y, v_z)
					double r = sqrt(dir_x * dir_x + dir_y * dir_y + dir_z * dir_z);
					if (r == NAN || r > 5.) r = 0.0; // pozbycie sie artefaktow (przy m.in. dzieleniu przez zero)
					if (r < min_size) min_size = r; // wartoœci niezbêdne w momencie wyliczania koloru
					if (r > max_size) max_size = r;

					add_arrow(config, Point(x, y, z), Point(dir_x, dir_y, dir_z), arrow, data); // transformacja strza³ki i dodanie jej do przestrzeni 
				}
			}
	// ustalanie koloru - (....color.R = r_danej_strzalki  w tym momencie)
	if (config.GetPrintOption() == 0) {
		for (auto& point : data) {
			point.color.R = (point.color.R - min_size) <= ((max_size - min_size)/2.) ?
				 255. * 2. * ((point.color.R - min_size) / (max_size - min_size)) : 255;
			point.color.B = (point.color.B - min_size) > ((max_size - min_size) / 2.) ?
				255. * 2 * (1. - (point.color.B - min_size) / (max_size - min_size)) : 255;
		}
	}
}

// Odpowiednie przetransformowanie strzalki i dodanie do pamieci
void add_arrow(Config& config, Point& position, Point& direction, std::vector<Segment>& arrow, std::vector<Segment>& data) {
	double eps = 1e-5;
	double min_size = 2000;
	double max_size = 0;

	double r = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
	double p1 = direction.x > 0 ? asin(direction.y / r) : -asin(direction.y / r) + 3.14;	// k¹t 1
	double p2 = direction.x > 0 ? -asin(direction.z / r) : asin(direction.z / r);			// k¹t 2
	double cut_len = config.GetCutLen();													// odleg³oœæ miêdzy dwiema przedzia³kami
	double max_len = config.GetCurrentFun()->GetMax();										// d³ugoœæ najd³u¿szego wektora
	double scale = cut_len * r / max_len;													// skala strza³ki
	p2 = fabs(direction.x) < eps ? atan(direction.z/ direction.x) : p2;						// korekta k¹ta w zerze
	p2 = fabs(direction.z) < eps ? -asin(direction.z / r) : p2;

	for (int i = 0; i < arrow.size(); i++) {
		Segment point = arrow[i];

		Multiplication_Matrix leng = Multiplication_Matrix(config.GetArrowsLen() / 100.0, config.GetArrowsLen() / 100.0, config.GetArrowsLen() / 100.0);
		ZRotate_Matrix z_rotate = p1;
		YRotate_Matrix y_rotate = p2;
		transform_line(leng, &point); // mnozenie segmentu przez macierz transformacji

		if (config.GetPrintOption() == 1) {
			Multiplication_Matrix arr_leng = Multiplication_Matrix(scale, scale, scale);
			transform_line(arr_leng, &point);
		}
		else if (config.GetPrintOption() == 0) {
			Color color(r, 0, r);			// ustawienie koloru jako dlugosc wektora - (przygotowanie do dalszego wyliczenia).
			point.color = color;
		}

		// odpowiednie ustawienie strzalki - kierunek i polozenie punktu startowego
		transform_line(z_rotate, &point);
		transform_line(y_rotate, &point);
		point += position;
		data.push_back(point); // dodanie do tablicy przechowujacej wszystkie strzalki
	}
}

// Aktualizacja obrazu
void update_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow) {
	data.clear();
	create_space(config, data, arrow);
}