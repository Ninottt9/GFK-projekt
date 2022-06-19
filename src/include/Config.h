#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "include/Function.h"
#include "include/VectorMatrix.h"

/**
* @mainpage Wizualizacja pola wektorowego
* @author Jan Bizoñ
* @author Maksym Kazhaiev
* @author Micha³ Rogowski
* 
* @details
* Wizualizacja pola wektorowego
===================================

### Opis projektu

Celem projektu jest napisanie programu, który pozwala wizualizowaæ funkcjê V = f(r) , gdzie V oraz r to wektory w przestrzeni 3D. Oczywiœcie program nie musi umieæ interpretowaæ ¿adnych funkcji wpisywanych przez u¿ytkownika. Zestaw kilku przyk³adowych funkcji powinien zostaæ wpisany na sta³e do kodu programu, a u¿ytkownik powinien mieæ mo¿liwoœæ wyboru jednej z nich i ewentualnie zmiany jej parametrów.

### Wymagania podstawowe

Program pozwala na wizualizacjê funkcji pola poprzez rysowanie **strza³ek**, które maj¹ pocz¹tek w **punktach wêz³owych**. Przedzia³ zmiennoœci argumentów X,Y,Z jak i to na ile odcinków dzielimy te przedzia³y podaje u¿ytkownik. Wspó³czynnik skalowania okreœlaj¹cy jak d³ugie s¹ strza³ki u¿ytkownik mo¿e zmieniaæ przy u¿yciu suwaka. Oczywiœcie ca³oœæ mo¿na dowolnie **obracaæ**. Program posiada tak¿e kilka funkcji do wyboru. Funkcje te maj¹ wstawione parametry swobodne, które u¿ytkownik mo¿e zmieniaæ w trakcie pracy programu.

### Wymagania rozszerzone

W tej wersji program potrafi sam dobraæ d³ugoœæ strza³ek tak, aby najd³u¿sza nie by³a wiêksza ni¿ odleg³oœci wêze³-wêze³. Oczywiœcie u¿ytkownik w dalszym ci¹gu posiada mo¿liwoœæ zmiany skali rêcznie. Istnieje tryb wyœwietlania, w którym d³ugoœci strza³ek s¹ sta³e, a o wartoœci funkcji w wêŸle informuje nas kolor strza³ki (standardowa skala – **niebieski** dla minimum – **czerwony** dla maksimum). U¿ytkownik ma mo¿liwoœæ zapisania wyniku na dysk w postaci pliku graficznego o zadanym. Program powinien mieæ równie¿ mo¿liwoœæ „odciêcia” czêœci wêz³ów poprzez wprowadzenie dodatkowej p³aszczyzny. Wszystkie strza³ki wychodz¹ce z wêz³ów po wybranej stronie p³aszczyzny nie bêd¹ rysowane.



### Plan:
+ Funkcje pola wektorowego wybierane z listy (mo¿liwoœæ manipulacji parametrami funkcji).
+ Wizualizacja pola poprzez rysowanie strza³ek
+ Mo¿liwoœæ okreœlenia przedzia³u zmiennnoœci oraz iloœci odcinków na ile dzielimy ten przedzia³
+ Mo¿liwoœæ zmianny d³ugoœci strza³ek za pomoc¹ suwaka
+ (Rozszerzenie) Automatyczny dobór d³ugoœci strza³ek
+ (Rozszerzenie) Alternatywny sposób wyœwietlania strza³ek - sta³a d³ugoœæ + kolor
+ (Rozszerzenie) Mo¿liwoœæ zapisu wyniku na dysku w postaci bit mapy
+ (Rozszerzenie) Odciêcie czêœci pola za pomoc¹ p³aszczyzny


### Inspiracje:
+ https://www.geogebra.org/m/u3xregNW
+ https://www.geogebra.org/m/KKB2Ndez
+ https://glennmarshall.wordpress.com/2014/10/31/3d-neon-vector-fields/
+ https://chart-studio.plotly.com/~empet/14971.embed
+ https://forum.dynamobim.com/t/vector-field-visualization/26862

===============================================================================
![image](../doc.png)

- Jako Init() - nale¿y rozumieæ konstruktor MainFrame_Interface
- Jako Refresh() - nale¿y rozumieæ funkcje rysuj¹c¹
- Jako Menu Item() - nale¿y rozumieæ konkretny wybór z paska menu.

# Uwaga:
Czêœæ klas nie zosta³a opisana - zosta³y one wygenerowane automatycznie, 
aby poznaæ ich stukturê i funkcjê które pe³ni¹ nale¿y zainstalowaæ wxFormBuilder
i uruchomiæ plik Layout.fbp.
*/ 


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
	* @brief Zwraca d³ugoœæ jaka ma zostaæ dodana w pêtli rysujacej
	*/
	double GetCutLen() const; 
	/**
	* @brief Zwraca aktualnie wyœwietlan¹ funkcje
	*/
	Function* GetCurrentFun();
	/**
	* @brief Zwraca tryb wyœwietlania pola wektorowego - (0) Kolor /  (1) Dlugosc ??
	*/
	unsigned int GetPrintOption() const;
	/**
	* @brief Zwraca dlugoœæ strza³ki
	*/
	double GetArrowsLen() const;
	/**
	* @brief Zwraca odleg³oœæ do której mamy wyœwietlaæ - ustawienie Z-buffer-a
	*/
	double GetFarPlane() const;
	/**
	* @brief Informacja wyswietlana na pasku postepu - pocz¹tek. Infrormuje o najbli¿ej po³o¿onym punkcie obiektu.
	*/
	double GetNearest() const;
	/**
	* @brief Informacja wyœwietlana na pasku postepu - koniec. Infrormuje o najdalej po³o¿onym punkcie obiektu.
	*/
	double GetFurthest() const;

	// Ruch myszki na ekranie
	/**
	* @brief Wspó³rzêdna x wciœniêtej myszy
	*/
	double GetStartX() const;
	/**
	* @brief Wspó³rzêdna y wciœniêtej myszy
	*/
	double GetStartY() const;
	/**
	* @brief Wspó³rzêdna x po upuszczeniu klawisza myszy
	*/
	double GetEndX() const;
	/**
	* @brief Wspó³rzêdna y po upuszczeniu klawisza myszy
	*/
	double GetEndY() const;
	/**
	* @brief Czy mysz jest wcisnieta
	*/
	bool GetPressed() const;
	/**
	* @brief Ustawienie aktualnego stanu wciœniêcia myszy
	*/
	void SetPressed(bool x);


	/**
	* @brief Ustawia doln¹ granicê przestrzeni wektorowej w osi X
	*/
	void SetX_Min(double x);
	/**
	* @brief Ustawia górn¹ granicê przestrzeni wektorowej w osi X
	*/
	void SetX_Max(double x);
	/**
	* @brief Ustawia doln¹ granicê przestrzeni wektorowej w osi Y
	*/
	void SetY_Min(double x);
	/**
	* @brief Ustawia górn¹ granicê przestrzeni wektorowej w osi Y
	*/
	void SetY_Max(double x);
	/**
	* @brief Ustawia doln¹ granicê przestrzeni wektorowej w osi Z
	*/
	void SetZ_Min(double x);
	/**
	* @brief Ustawia górn¹ granicê przestrzeni wektorowej w osi Z
	*/
	void SetZ_Max(double x);
	/**
	* @brief Ustawia d³ugoœæ jaka ma zostaæ dodana w pêtli rysujacej
	*/
	void SetCutLen(double x);
	/**
	* @brief Ustawia aktualnie wyœwietlan¹ funkcje
	*/
	void SetCurrentFun(Function* fun); 
	/**
	* @brief Informacja wyswietlana na pasku postepu - koniec. Infrormuje o najdalej po³o¿onym punkcie obiektu.
	*/
	Function* GetFunction(int id) const;
	/**
	* @brief Ustawia tryb wyœwietlania pola wektorowego - (0) Kolor / (1) Dlugosc ???
	*/
	void SetPrintOption(unsigned int x);
	/**
	* @brief Ustawia dlugoœæ strza³ki
	*/
	void SetArrowsLen(double x);
	/**
	* @brief Ustawia odleg³oœæ do której mamy wyœwietlaæ - ustawienie Z-buffer-a
	*/
	void SetFarPlane(double x);
	/**
	* @brief Ustawai informacjê wyœwietlan¹ na pasku postepu - pocz¹tek. Infrormuje o najbli¿ej po³o¿onym punkcie obiektu.
	*/
	void SetNearest(double x);
	/**
	* @brief Informacja wyswietlana na pasku postepu - koniec. Infrormuje o najdalej po³o¿onym punkcie obiektu.
	*/
	void SetFurthest(double x);
	/**
	* @brief Ustawienie pozycji myszy - pozycja start
	*/
	void SetStart(double x, double y);
	/**
	* @brief Ustawienie pozycji myszy - pozycja end
	*/
	void SetEnd(double x, double y);


	/**
	* @brief Zwraca aktualnie ustawion¹ skalê przestrzeni.
	*/
	double GetScale() const;
	/**
	* @brief Ustawia skalê przestrzeni.
	*/
	double SetScale(double x);
	/**
	* @brief Ustawia informacjê o tym czy odciêcie czêœci danych ma zostaæ zrealizowane.
	*/
	void PlaneEnabled(bool x);
	/**
	* @brief Zwraca informacjê o tym czy odciêcie czêœci danych ma zostaæ zrealizowane.
	*/
	bool isPlaneEnable() const;
	/**
	* @brief Zwraca aktualn¹ rotacjê przestrzeni
	*/
	Matrix4 GetRotation() const;
	/**
	* @brief Ustawia aktualn¹ rotacjê przestrzeni
	*/
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

	std::vector<Function*>* function_ptr;
};