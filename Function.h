#pragma once
#include <string>
#include <wx/bitmap.h>
#include <wx/gdicmn.h>
#include "ControlParam_Interface.h"

class MainFrame_Interface;

class Function {
public:
	Function();
	Function(std::string bitmap_url);
	Function(std::string bitmap_url, std::string name, wxPoint min = wxPoint(0,0));
	virtual void calc(double& x, double& y, double& z);
	void find_min();
	const wxBitmap& GetBitmap() const;
	void SetName(std::string new_name);
	const std::string& GetName() const;
	ControlParam_Interface* GetDialog() const;
private:
	wxBitmap picture;
	wxPoint min;
	std::string name;
	ControlParam_Interface* dialog;
};

class Gravity_Function : public Function {
public:
	Gravity_Function() : Function("eq1.png", "gravity"), G{1}, M{1}, m{1} {}
	void calc(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		x *= G*m*M/(r*r);
		y *= G*m*M/(r*r);
		z *= G*m*m/(r*r);
	}
	void Set1(double G) {
		this->G = G;
	}
	void Set2(double m) {
		this->m = m;
	}
	void Set3(double M) {
		this->M = M;
	}
private:
	double G;
	double m, M;
};

class My_Function : public Function {
public:
	My_Function() : a(1), b(1), c(1), Function("eq2.png", "water") {}
	void calc(double& x, double& y, double& z) {
		double r = 1. / sqrt(x * x + y * y + z * z);
		double buff_x = x;
		x *= a* (sin(x) + sin(y));
		y *= b *( sin(buff_x) - sin(y));
		z *= c;
	}
private:
	double a, b, c;
};

class My_Function2 : public Function {
public:
	My_Function2() : a(1), b(1), c(1), Function("eq3.png", "sin") {}
	void calc(double& x, double& y, double& z) {
		double r = 1. / sqrt(x * x + y * y + z * z);
		double x_buff = x; 
		double y_buff = y;
		
		x *= a* sin(y_buff) / r;
		y *= b* cos(x_buff) / r;
		z *= c / r;
	}
private:
	double a, b, c;
};