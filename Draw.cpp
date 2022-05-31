#include "Draw.h"
#include "MainFrame_Interface.h"
#include "VectorMatrix.h"
#include "Primitives.h"
#include <fstream>

//std::vector<Segment> data;



void draw_space(Config& config, std::vector<Segment>& data, wxPanel* draw_canvas, wxBitmap _pic, wxImage MyImage) {
	
	_pic = wxBitmap(draw_canvas->GetSize().GetWidth(), draw_canvas->GetSize().GetHeight());
	MyImage = _pic.ConvertToImage();

	wxClientDC _dc(draw_canvas);
	wxBufferedDC dc(&_dc, _pic);

	
	dc.SetBackground(*wxGREY_BRUSH);
	dc.Clear();


	double scl_x = config.GetArrowsLen() / 100.0;
	double scl_y = config.GetArrowsLen() / 100.0;
	double scl_z = config.GetArrowsLen() / 100.0;

	// W radianach
	double rot_x = config.GetPressed() ?  atan((config.GetEndX() - config.GetStartX()) / draw_canvas->GetSize().GetWidth()) + config.GetViewRotX() : config.GetViewRotX();//atan(config.GetViewRotX()/ draw_canvas->GetSize().GetWidth()); 
	double rot_y = config.GetPressed() ?  atan((config.GetEndY() - config.GetStartY()) / draw_canvas->GetSize().GetWidth()) + config.GetViewRotY() : config.GetViewRotY();//atan(config.GetViewRotY()/ draw_canvas->GetSize().GetHeight());
	double rot_z = config.GetPressed() ?  0 : config.GetViewRotZ();//atan(config.GetViewRotZ()/2)*2;

	double tr_x = (100 - 100.0) / 50.0;
	double tr_y = (200 - 100.0) / 50.0;
	double tr_z = (400 - 100.0) / 50.0;

	double max = -1000;
	double min = 1000;

	Multiplication_Matrix scale(scl_x, scl_y, scl_z);
	XRotate_Matrix xrotation(rot_x);
	YRotate_Matrix yrotation(rot_y);
	ZRotate_Matrix zrotation(rot_z); /* * 6.28 / 360 */
	Translation_Matrix translation(tr_x, tr_y, tr_z);

	Matrix4 transform1 = translation * zrotation * yrotation * xrotation * scale;

	Matrix4 m6;
	m6.data[0][0] = 1;
	m6.data[1][1] = 1;
	m6.data[3][2] = 1.0 / 2.0;

	Matrix4 m7;
	m7.data[0][0] = draw_canvas->GetSize().GetWidth() / 2;
	m7.data[1][1] = -draw_canvas->GetSize().GetHeight() / 2;
	m7.data[0][3] = draw_canvas->GetSize().GetWidth() / 2;
	m7.data[1][3] = draw_canvas->GetSize().GetHeight() / 2;

	Matrix4 transform2 = m7 * m6;



	for (Segment& segment : data) {
		double middle = (segment.begin.y + segment.end.y) / 2;
		if (middle < min) {
			min = middle;
		}
		else if (middle > max) {
			max = middle;
		}
	}
	for (Segment segment : data) {

		transform_line(transform1, &segment);
		Vector4 startPoint, endPoint;
		startPoint.Set(segment.begin.x, segment.begin.y, segment.begin.z);
		endPoint.Set(segment.end.x, segment.end.y, segment.end.z);


		double r = segment.color.R;
		double g = segment.color.G;
		double b = segment.color.B;
		dc.SetPen(wxPen(wxColour(r, g, b)));



		if ((startPoint.GetZ() > -2.0 && endPoint.GetZ() <= -2.0) || (endPoint.GetZ() > -2.0 && startPoint.GetZ() <= -2.0)) {
			Vector4 temp1 = endPoint.GetZ() <= -2.0 ? endPoint : startPoint;
			Vector4 temp2 = endPoint.GetZ() <= -2.0 ? startPoint : endPoint;
			double r = abs((-2.0 - temp1.data[2]) / (temp2.data[2] - temp1.data[2]));
			temp1.data[0] = (temp2.data[0] - temp1.data[0]) * r + temp1.data[0];
			temp1.data[1] = (temp2.data[1] - temp1.data[1]) * r + temp1.data[1];
			temp1.data[2] = -2.0;

			startPoint = transform2 * temp1;
			endPoint = transform2 * temp2;

			startPoint.data[0] /= startPoint.data[3];
			startPoint.data[1] /= startPoint.data[3];
			startPoint.data[2] /= startPoint.data[3];

			endPoint.data[0] /= endPoint.data[3];
			endPoint.data[1] /= endPoint.data[3];
			endPoint.data[2] /= endPoint.data[3];
		}
		else if (startPoint.GetZ() <= -2.0 && endPoint.GetZ() <= -2.0) {
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
	for(int z = config.GetZ_Min(); z < config.GetZ_Max(); z += 2)
	for(int x = config.GetX_Min(); x < config.GetX_Max(); x += 2)
		for (int y = config.GetY_Min(); y < config.GetY_Max(); y += 2) {
			/*
			int r, g, b;
			double x1, x2, y1, y2, z1, z2;
			r = g = b = 0;
			z1 = z+0;
			z2 = z+1;

			x1 = x2 = x;
			y1 = y2 = y;

			data.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
			*/
			add_arrow(Point(x, y, z), arrow, data);
		}
}

void add_arrow(Point& position, std::vector<Segment>& arrow, std::vector<Segment>& data) {
	int r, g, b;
	r = g = b = 0;
	double x1, x2, y1, y2, z1, z2;
	for (auto point : arrow) {
		point += position;
		data.push_back(point);
	}
}

void update_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow) {
	data.clear();
	create_space(config, data, arrow);
}