#pragma once
#include <string>
#include <wx/bitmap.h>
#include <wx/gdicmn.h>
#include "ControlParam_Interface.h"

class MainFrame_Interface;

class Function {
public:
	Function(std::string bitmap_url, std::string name, wxPoint min = wxPoint(0,0));
	virtual void calc(double& x, double& y, double& z);
	const wxBitmap& GetBitmap() const;
	void SetName(std::string new_name);
	const std::string& GetName() const;
	ControlParam_Interface* GetDialog() const;
	virtual double GetMax() const { return 1.; }
private:
	wxBitmap picture;
	wxPoint min;
	std::string name;
	ControlParam_Interface* dialog;
};

class Gravity_Function : public Function {
public:
	Gravity_Function() : Function("eq1.png", "Central"), a{ 1 }, b{ 1 }, c{ 1 } {}
	void calc(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		x *= a * b * c /(r*r);
		y *= a * b * c /(r*r);
		z *= a * b * c /(r*r);
	}
	void Set1(double a) {
		this->a = a;
	}
	void Set2(double b) {
		this->b = b;
	}
	void Set3(double c) {
		this->c= c;
	}
private:
	double a, b, c;
};

class My_Function : public Function {
public:
	My_Function() : a(1), b(1), c(1), max(-2000), Function("eq2.png", "Sinusoidal") {}
	void calc(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		double buff_x = x;
		x *= a * (sin(x) + sin(y));
		y *= b * (sin(buff_x) - sin(y));
		z *= c;
		if (r > max) max = r;
	}
	double GetMax() const{
		return max;
	}
	void Set1(double a) {
		this->a = a;
	}
	void Set2(double b) {
		this->b = b;
	}
	void Set3(double c) {
		this->c = c;
	}
private:
	double a, b, c;
	double max;
};

class My_Function2 : public Function {
public:
	My_Function2() : a(1), b(1), c(1), max(-2000), Function("eq3.png", "Local Vortex") {}
	void calc(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		double x_buff = x; 
		double y_buff = y;
		
		x *= a * sin(y_buff);
		y *= b * cos(x_buff);
		z *= c;
		if (r > max) max = r;
	}
	double GetMax() const {
		return max;
	}
	void Set1(double a) {
		this->a = a;
	}
	void Set2(double b) {
		this->b = b;
	}
	void Set3(double c) {
		this->c = c;
	}
private:
	double a, b, c;
	double max;
};