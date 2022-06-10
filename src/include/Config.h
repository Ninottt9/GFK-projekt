#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "include/Function.h"
#include "include/VectorMatrix.h"

// Klasa przechowujaca aktualna konfiguracje
class Config {
public:
	Config(std::vector<Function*>* function_ptr);

	// Ograniczenia przestrzeni
	double GetX_Min() const;
	double GetX_Max() const;
	double GetY_Min() const;
	double GetY_Max() const;
	double GetZ_Min() const;
	double GetZ_Max() const;
	// Dlugosc jaka ma dodawac w petli rysujacej
	double GetCutLen() const;
	// Aktualnie wyswietlana funkcja
	Function* GetCurrentFun();
	// Kolor / Dlugosc
	unsigned int GetPrintOption() const;
	// Dlugosc strzalki
	double GetArrowsLen() const;
	// Odleglosc do ktorej mamy wyswietlac
	double GetFarPlane() const;

	// Informacje do wyswietlenia na pasku postepu
	double GetNearest() const;
	double GetFurthest() const;

	// Ruch myszki na ekranie
	double GetStartX() const;
	double GetStartY() const;
	double GetEndX() const;
	double GetEndY() const;
	// Czy mysz jest wcisnieta
	bool GetPressed() const;
	void SetPressed(bool x);

	// To samo tylko ustawianie
	void SetX_Min(double x);
	void SetX_Max(double x);
	void SetY_Min(double x);
	void SetY_Max(double x);
	void SetZ_Min(double x);
	void SetZ_Max(double x);
	void SetCutLen(double x);
	void SetCurrentFun(Function* fun); 
	Function* GetFunction(int id) const;
	void SetPrintOption(unsigned int x);
	void SetArrowsLen(double x);
	void SetFarPlane(double x);
	void SetNearest(double x);
	void SetFurthest(double x);
	void SetStart(double x, double y);
	void SetEnd(double x, double y);

	// Przyblizenie
	double GetScale() const;
	double SetScale(double x);
	// Czy ma odcinac
	void PlaneEnabled(bool x);
	bool isPlaneEnable() const;
	// Aktualna rotacja przestrzeni
	Matrix4 GetRotation() const;
	void SetRotation(Matrix4 rot, XRotate_Matrix l_x, YRotate_Matrix l_y);

private:
	double x_min, x_max;
	double y_min, y_max;
	double z_min, z_max;
	double lenght_of_cut;
	Function* current_function;
	unsigned int print_option;
	double length_of_arrows;

	double far_plane;
	double nearest_point;
	double furthest_point;

	double start_swipe_x;
	double start_swipe_y;
	double end_swipe_x;
	double end_swipe_y;

	bool pressed;
	double scale;
	bool plane_enable;
	Matrix4 rotation;

	// Tablica z dostepnymi funkcjami
	std::vector<Function*>* function_ptr;
};