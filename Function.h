#pragma once
#include <string>
#include <wx/bitmap.h>
#include <wx/gdicmn.h>
#include "ControlParam_Interface.h"

//class ControlParam_Interface;


class Function {
public:
	Function(){}
	Function(std::string bitmap_url) {
		//dialog = new ControlParam_Interface(NULL);
		picture.LoadFile(bitmap_url, wxBITMAP_TYPE_PNG);
	}
	Function(std::string bitmap_url, std::string name, wxPoint min): name(name), min(min) {
		picture.LoadFile(bitmap_url, wxBITMAP_TYPE_PNG);
	}
	virtual void calc(double& x, double& y, double& z) { }
	void find_min(){}
	const wxBitmap& GetBitmap() const {
		return picture;
	}
	void SetName(std::string new_name) {
		name = new_name;
	}
	const std::string& GetName() const {
		return name;
	}
	void OpenDialog(bool control_open) {
		if (!control_open) {
			dialog = new ControlParam_Interface(NULL);
			dialog->Show();
		}
	}
	void CloseDialog(bool control_open) {
		if (!control_open){
			delete dialog;
		}
	}
private:
	wxBitmap picture;
	wxPoint min;
	std::string name;
	ControlParam_Interface* dialog;
};

class Gravity_Function : public Function {
public:
	Gravity_Function() : Function("eq1.png"), G{1}, M{1}, m{1} {}
	void calc(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		//double p1 = x*y > 0 ? atan2(x, y) : atan2(x, y); // ?
		//double p2 = x*z > 0 ? atan2(x, z) : atan2(x, z); // ?
		x *= G*m*M/r;
		y *= G*m*M/r;
		z *= G*m*m/r;
	}
private:
	double G;
	double m, M;
};

class My_Function : public Function {
public:
	My_Function() : Function("eq2.png") {}
	void calc(double& x, double& y, double& z) {
		double r = 1. / sqrt(x * x + y * y + z * z);
		//double p1 = x*y > 0 ? atan2(x, y) : atan2(x, y); // ?
		//double p2 = x*z > 0 ? atan2(x, z) : atan2(x, z); // ?
		x *= G * m * M / r;
		y *= G * m * M / r;
		z *= G * m * m / r;
	}
private:
	double G;
	double m, M;
};

class My_Function2 : public Function {
public:
	My_Function2() : Function("eq3.png") {}
	void calc(double& x, double& y, double& z) {
		double r = 1. / sqrt(x * x + y * y + z * z);
		//double p1 = x*y > 0 ? atan2(x, y) : atan2(x, y); // ?
		//double p2 = x*z > 0 ? atan2(x, z) : atan2(x, z); // ?
		double x_buff = x; 
		double y_buff = y;
		
		x *= a* sin(y_buff) / r;
		y *= b* cos(x_buff) / r;
		z *= c / r;
	}
private:
	double a, b, c;
};