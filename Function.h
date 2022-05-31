#pragma once
#include <string>
#include <wx/bitmap.h>
#include <wx/gdicmn.h>

class Function {
public:
	Function(){}
	Function(std::string pic_url){}
	virtual void calc(double& x, double& y, double& z) { }
	void find_min(){}
private:
	wxBitmap* picture;
	wxPoint min;
};

class Gravity_Function : public Function {
public:
	Gravity_Function(): Function("eq1.png") {}
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