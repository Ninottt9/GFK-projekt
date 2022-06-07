#include "Draw.h"
#include "MainFrame_Interface.h"
#include "VectorMatrix.h"
#include "Primitives.h"
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

	/*
	double speed = 5.;
	double rot_y = config.GetPressed() ? speed * atan((config.GetStartY() - config.GetEndY()) / draw_canvas->GetSize().GetHeight()) + config.GetViewRotY() : config.GetViewRotY();
	double rot_x = config.GetPressed() ? speed * atan((config.GetStartX() - config.GetEndX()) / draw_canvas->GetSize().GetWidth()) + config.GetViewRotX() : config.GetViewRotX();
	double rot_z = config.GetPressed() ? speed * atan((config.GetStartY() - config.GetEndY()) / draw_canvas->GetSize().GetHeight()) + config.GetViewRotZ() : config.GetViewRotZ();
	*/
	double rot_x = config.GetViewRotX();
	double rot_y = config.GetViewRotY();
	double rot_z = config.GetViewRotZ();
	double l_rot_y = atan((config.GetStartY() - config.GetEndY()) / draw_canvas->GetSize().GetHeight());
	double l_rot_x = atan((config.GetStartX() - config.GetEndX()) / draw_canvas->GetSize().GetWidth());
	if(config.GetPressed())	local_to_global_rot(rot_x, rot_y, rot_z, l_rot_x, l_rot_y);

	double tr_x = 0.;
	double tr_y = 0.5;
	double tr_z = 10.;

	double max = -1000;
	double min = 1000;

	Multiplication_Matrix scale(scl_x, scl_y, scl_z);
	XRotate_Matrix xrotation(rot_x);
	YRotate_Matrix yrotation(rot_y);
	ZRotate_Matrix zrotation(rot_z);
	Translation_Matrix translation(tr_x, tr_y, tr_z);

	double x_shift = 0;// (config.GetX_Max() - config.GetX_Min()) / 2;
	double y_shift = 0; // (config.GetY_Max() - config.GetY_Min()) / 2;
	double z_shift = 0; // (config.GetZ_Max() - config.GetZ_Min()) / 2;
	Translation_Matrix tomiddle(-x_shift, -y_shift, -z_shift);
	Translation_Matrix frommiddle(x_shift, y_shift, z_shift);

	Matrix4 transform1 = translation * frommiddle * zrotation * yrotation * xrotation * scale * tomiddle;

	Matrix4 m6;
	m6.data[0][0] = 1.0 / 2.0; // ?
	m6.data[1][1] = 1;
	m6.data[3][2] = 1.0 / 2.0;

	Matrix4 m7;
	m7.data[0][0] = draw_canvas->GetSize().GetWidth() / 2;
	m7.data[1][1] = -draw_canvas->GetSize().GetHeight() / 2;
	m7.data[0][3] = draw_canvas->GetSize().GetWidth() / 2;
	m7.data[1][3] = draw_canvas->GetSize().GetHeight() / 2;

	Matrix4 transform2 = m7 * m6;

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
	for (Point& point : box) {
		Vector4 vec, result;
		vec.Set(point.x, point.y, point.z);
		result = transform1 * vec;
		
		//double dist = result.GetX() * result.GetX() + result.GetY() * result.GetY() + result.GetZ() * result.GetZ();
		double dist = result.GetZ();
		if (dist < min) {
			min = dist;
		}
		else if (dist > max) {
			max = dist;
		}
	}
	double bar_scale = 5;
	config.SetFurthest(bar_scale * max);
	config.SetNearest(bar_scale * min);


	for (Segment segment : data) {

		transform_line(transform1, &segment);
		Vector4 startPoint, endPoint;
		startPoint.Set(segment.begin.x, segment.begin.y, segment.begin.z);
		endPoint.Set(segment.end.x, segment.end.y, segment.end.z);


		double r = segment.color.R;
		double g = segment.color.G;
		double b = segment.color.B;
		dc.SetPen(wxPen(wxColour(r, g, b)));

		// Odciecie
		if (config.isPlaneEnable() && startPoint.GetZ() > config.GetFarPlane()) {
			continue;
		}


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

		dc.DrawLine(startPoint.GetX(), startPoint.GetY(), endPoint.GetX(), endPoint.GetY());
	}
}




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

void create_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow) {
	float z_m = config.GetCutLen() / (config.GetZ_Max() - config.GetZ_Min());
	float y_m = config.GetCutLen() / (config.GetY_Max() - config.GetY_Min());
	float x_m = config.GetCutLen() / (config.GetX_Max() - config.GetX_Min()); // to jest chyba nie potrzebne
	double min_size = 2000;
	double max_size = 0;
	for(double z = config.GetZ_Min(); z < config.GetZ_Max(); z += config.GetCutLen())
		for(double x = config.GetX_Min(); x < config.GetX_Max(); x += config.GetCutLen())
			for (double y = config.GetY_Min(); y < config.GetY_Max(); y += config.GetCutLen()) {
				double dir_x, dir_y, dir_z;
				//dir_x = x*0.1, dir_y = y*0.1, dir_z = z*0.1;
				//dir_x = x * x_m, dir_y = y * y_m, dir_z = z * z_m;
				dir_x = x, dir_y = y, dir_z = z;

				if (config.GetCurrentFun()) {
					double l = sqrt(x * x + y * y + z * z);
					//int r = 255. * ((l - min_size) / (max_size-min_size));
					//int b = 255. * (1 - (l - min_size) / (max_size - min_size));
					//Color color(r, 0, b);
					config.GetCurrentFun()->calc(dir_x, dir_y, dir_z);
					double r = sqrt(dir_x * dir_x + dir_y * dir_y + dir_z + dir_z);
					if (r < min_size) min_size = r;
					if (r > max_size) max_size = r;

					add_arrow(config, Point(x, y, z), Point(dir_x, dir_y, dir_z), arrow, data);
				}
			}
	for (auto& point : data) {
		point.color.R = 255. * ((point.color.R - min_size) / (max_size - min_size));
		point.color.B = 255. * (1 - (point.color.B - min_size) / (max_size - min_size));
	}
}

//#include <string>

void add_arrow(Config& config, Point& position, Point& direction, std::vector<Segment>& arrow, std::vector<Segment>& data) {
	double eps = 1e-5;
	double min_size = 2000;
	double max_size = 0;
	for (int i = 0; i < arrow.size(); i++) {
		Segment point = arrow[i];
		// przeliczenie na uklad r p
		double r = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z); // to mozna wyciagnac z petli
		double p1 = direction.x > 0 ? asin(direction.y/ r) : -asin(direction.y/ r) + 3.14; 
		double p2 = direction.x > 0 ? -asin(direction.z/ r) : asin(direction.z/ r);
		p1 = fabs(direction.x) < eps ? asin(direction.y / r) : p1; // poprawic
		p2 = fabs(direction.x) < eps ? -asin(direction.z / r) : p2;

		// Drugi sposob
		Color color(r, 0, r);
		point.color = color;


		// to chyba nie tutaj
		//Multiplication_Matrix arr_leng = Multiplication_Matrix(r, r, r); // pierwszy sposob wyswietlania
		// nie dzial jeszcze dal wszystkich

		Multiplication_Matrix leng = Multiplication_Matrix(config.GetArrowsLen() / 100.0, config.GetArrowsLen() / 100.0, config.GetArrowsLen() / 100.0);
		ZRotate_Matrix z_rotate = p1;
		YRotate_Matrix y_rotate = p2;
		transform_line(leng, &point);
		//transform_line(arr_leng, &point); // pierwszy sposob wyswietlania 

		transform_line(z_rotate, &point);
		transform_line(y_rotate, &point);

		//przesuniecie w ukladzie wspolrzednych
		point += position;

		data.push_back(point);
	}
}

void update_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow) {
	data.clear();
	create_space(config, data, arrow);
}

void change_arrow_len(std::vector<Segment>& arrow, Point& direction) {
	for (int i = 1; i < arrow.size(); i++) {
		arrow[i] += direction;
	}
	//arrow[0].end += direction;
} // niepotrzebne


void local_to_global_rot(double& g_x_rot, double& g_y_rot, double& g_z_rot, double l_x_rot, double l_y_rot) {
	double speed = 5.;
	double buff_x = speed * sin(l_x_rot)* cos(g_z_rot)* cos(g_y_rot); // sin(l_x_rot)* cos(g_y_rot) - sin(l_y_rot) * cos(g_z_rot);
	double buff_y = speed * sin(l_y_rot)* cos(g_x_rot)* cos(g_z_rot);// sin(l_x_rot)* cos(g_z_rot) + sin(l_y_rot) * cos(g_x_rot);
	double buff_z = speed * sin(l_x_rot) * cos(g_x_rot) * sin(g_y_rot);// +sin(g_x_rot) * sin(l_y_rot));// sin(l_x_rot)* cos(g_y_rot) + sin(l_y_rot) * cos(g_x_rot); // tutaj chyba cos zle
	g_x_rot += buff_x;
	g_y_rot += buff_y;
	g_z_rot += buff_z;
}