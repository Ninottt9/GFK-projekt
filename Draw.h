#pragma once


#include <string>
#include <vector>

class Matrix4;
class MainFrame_Interface;
class Segment;
class Config;
class wxPanel;
class Point;
class wxBitmap;
class wxImage;

void transform_line(const Matrix4& transform, Segment* seg);
bool load_model(std::string str, MainFrame_Interface& mainframe);
void create_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow);
void draw_space(Config& config, std::vector<Segment>& data, wxPanel* draw_canvas, wxBitmap& _pic, wxImage& MyImage);
void add_arrow(Config& config, Point& position, Point& direction, std::vector<Segment>& arrow, std::vector<Segment>& data);
void update_space(Config& config, std::vector<Segment>& data, std::vector<Segment>& arrow);