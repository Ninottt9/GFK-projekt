#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>

struct Matrix4;
class MainFrame_Interface;
struct Segment;
class Config;
class wxPanel;
struct Point;
class wxBitmap;
class wxImage;

// przeksztalcenie odcinka za pomoca macierzy
void transform_line(const Matrix4& transform, Segment* seg);
// wczytanie strzalki
bool load_model(std::string str, MainFrame_Interface& mainframe);
// generacja przestrzeni - wpisuje strzalki do data
void create_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow);
// rysuje zawartosc data
void draw_space(Config& config, std::vector<Segment>& data, wxPanel* draw_canvas, wxBitmap& _pic, wxImage& MyImage);
// dodanie strzalki do przestrzeni - wykorzystana przy generacji prz.
void add_arrow(Config& config, Point& position, Point& direction, std::vector<Segment>& arrow, std::vector<Segment>& data);
// wyczyszczenie data , generacja nowego
void update_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow);