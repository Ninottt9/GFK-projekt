#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "include/Function.h"
#include "include/VectorMatrix.h"

/**
*	@brief Klasa przechowujaca aktualna konfiguracje
*/
class Config {
public:
	/**
	* @brief WskaŸnik do zbioru dostêpnych funkcji
	*/
	Config(std::vector<Function*>* function_ptr);

	/**
	* @brief Zwraca doln¹ granicê przestrzeni wektorowej w osi X
	*/ 
	double GetX_Min() const;
	/**
	* @brief Zwraca górn¹ granicê przestrzeni wektorowej w osi X
	*/
	double GetX_Max() const;
	/**
	* @brief Zwraca doln¹ granicê przestrzeni wektorowej w osi Y
	*/
	double GetY_Min() const;
	/**
	* @brief Zwraca górn¹ granicê przestrzeni wektorowej w osi Y
	*/
	double GetY_Max() const;
	/**
	* @brief Zwraca doln¹ granicê przestrzeni wektorowej w osi Z
	*/
	double GetZ_Min() const;
	/**
	* @brief Zwraca górn¹ granicê przestrzeni wektorowej w osi Z
	*/
	double GetZ_Max() const;
	/**
	* @brief Dlugosc jaka ma zostaæ dodana w petli rysujacej
	*/
	double GetCutLen() const; 
	/**
	* @brief Aktualnie wyswietlana funkcja
	*/
	Function* GetCurrentFun();
	/**
	* @brief Zwraca tryb wyœwietlania pola wektorowego - Kolor / Dlugosc
	*/
	unsigned int GetPrintOption() const;
	/**
	* @brief Zwraca dlugosc strzalki
	*/
	double GetArrowsLen() const;
	/**
	* @brief Odleglosc do ktorej mamy wyswietlac - ustawienie Z-buffer-a
	*/
	double GetFarPlane() const;
	/**
	* @brief Informacja wyswietlana na pasku postepu - pocz¹tek. Infrormuje o najbli¿ej po³o¿onym punkcie obiektu.
	*/
	double GetNearest() const;
	/**
	* @brief Informacja wyswietlana na pasku postepu - koniec. Infrormuje o najdalej po³o¿onym punkcie obiektu.
	*/
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