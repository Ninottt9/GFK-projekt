#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <wx/bitmap.h>
#include <wx/gdicmn.h>
#include <wx/filename.h>
#include "ControlParam_Interface.h"

class MainFrame_Interface;

// klasa opisujaca funkcje wektorowa - do przeciazenia
class Function {
public:
	Function(std::string bitmap_url, std::string name);
	// Funkcja wyliczajaca
	virtual void Transform(double& x, double& y, double& z);
	// Wyciagniecie bitmapy zwiazanej z dana funkcja
	const wxBitmap& GetBitmap() const;
	// Wyciagniecie nazwy funkcji
	const std::string& GetName() const;
	// Funkcja zwracajaca najwieksza dlugosc wektora - sluzy do pozniejszej normalizacji
	virtual double GetMax() const { return 1.; }
protected:
	double max;
private:
	wxBitmap picture;
	std::string name;
	// dialog do kontrolowania parametrow - kazda funkcja moze miec swoja
	ControlParam_Interface* dialog;
};

class Central_Field : public Function {
public:
	Central_Field() : Function((std::string) wxGetCwd() + "\\..\\res\\eq1.png", "Central"), a{1}, b{1}, c{1} {}
	void Transform(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		x *= a * b * c /(r*r);
		y *= a * b * c /(r*r);
		z *= a * b * c /(r*r);
	}
	// Ilosc funkcji set zalezy od nas i tego jakie okno od parametrow wygenerujemy
	void SetA(double a) {
		this->a = a;
	}
	void SetB(double b) {
		this->b = b;
	}
	void SetC(double c) {
		this->c= c;
	}
private:
	double a, b, c;
};

class Sinusoidal_Field : public Function {
public:
	Sinusoidal_Field() : a{ 1 }, b{ 1 }, c{ 1 }, Function((std::string)wxGetCwd() + "\\..\\res\\eq2.png", "Sinusoidal") {}
	void Transform(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		double buff_x = x;
		x *= c * (sin(a * x) + sin(a * y));
		y *= c * (sin(b * buff_x) - sin(b * y));
		z *= c;
		if (r > max) max = r;
	}
	double GetMax() const override{
		return max;
	}
	void SetA(double a) {
		this->a = a;
	}
	void SetB(double b) {
		this->b = b;
	}
	void SetC(double c) {
		this->c = c;
	}
private:
	double a, b, c;
};

class Vortex_Field : public Function {
public:
	Vortex_Field() : a{ 1 }, b{ 1 }, c{ 1 }, Function((std::string)wxGetCwd() + "\\..\\res\\eq3.png", "Vortex") {}
	void Transform(double& x, double& y, double& z) {
		double r = sqrt(x * x + y * y + z * z);
		double x_buff = x; 
		double y_buff = y;
		
		x *= c * sin(a * y_buff);
		y *= c * cos(b * x_buff);
		z *= c;
		if (r > max) max = r;
	}
	double GetMax() const override{
		return max;
	}
	void SetA(double a) {
		this->a = a;
	}
	void SetB(double b) {
		this->b = b;
	}
	void SetC(double c) {
		this->c = c;
	}
private:
	double a, b, c;
};