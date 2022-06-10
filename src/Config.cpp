#include "include/Config.h"

Config::Config(std::vector<Function*>* function_ptr)
	: function_ptr(function_ptr)
{	
	SetX_Min(-4);
	SetX_Max(5);
	SetY_Min(-4);
	SetY_Max(5);
	SetZ_Min(0);
	SetZ_Max(1);

	SetCutLen(1. / 4);
	SetCurrentFun((*function_ptr)[2]);
	SetPrintOption(0);
	SetArrowsLen(25);
	SetFarPlane(100);
	SetPressed(false);

	SetScale(100);
	PlaneEnabled(false);
	rotation = XRotate_Matrix(40 * 3.14 / 180) * ZRotate_Matrix(20 * 3.14 / 180);
}


double Config::GetX_Min() const{
	return x_min;
}
double Config::GetX_Max() const{
	return x_max;
}
double Config::GetY_Min() const{
	return y_min;
}
double Config::GetY_Max() const{
	return y_max;
}
double Config::GetZ_Min() const{
	return z_min;
}
double Config::GetZ_Max() const{
	return z_max;
}



double Config::GetCutLen() const{
	return lenght_of_cut;
}
Function* Config::GetCurrentFun(){
	return current_function;
}
unsigned int Config::GetPrintOption() const{
	return print_option;
}
double Config::GetArrowsLen() const{
	return length_of_arrows;
}

void Config::SetX_Min(double x){
	 x_min = x;
}
void Config::SetX_Max(double x){
	 x_max = x;
}
void Config::SetY_Min(double x){
	 y_min = x;
}
void Config::SetY_Max(double x){
	 y_max = x;
}
void Config::SetZ_Min(double x){
	 z_min = x;
}
void Config::SetZ_Max(double x){
	 z_max = x;
}
void Config::SetCutLen(double x){
	 lenght_of_cut = x;
}
void Config::SetCurrentFun(Function* fun){
	current_function = fun;
}
void Config::SetPrintOption(unsigned int x){
	 print_option = x;
}
void Config::SetArrowsLen(double x){
	 length_of_arrows = x;
}

/* ================================================================ */

double Config::GetFarPlane() const{
	return far_plane *2 /5;

}
double Config::GetNearest() const{
	return nearest_point;

}
double Config::GetFurthest() const{
	return furthest_point;

}
double Config::GetStartX() const{
	return start_swipe_x;

}
double Config::GetStartY() const{
	return start_swipe_y;

}


void Config::SetFarPlane(double x){
	 far_plane = x;

}
void Config::SetNearest(double x){
	 nearest_point = x;

}
void Config::SetFurthest(double x){
	 furthest_point = x;

}
void Config::SetStart(double x, double y){
	start_swipe_x = x;
	start_swipe_y = y;
	 start_swipe_x;

}



bool Config::GetPressed() const {
	return pressed;
}
void Config::SetPressed(bool x) {
	pressed = x;
}

double Config::GetEndX() const{
	return end_swipe_x;
}
double Config::GetEndY() const{
	return end_swipe_y;
}
void Config::SetEnd(double x, double y){
	end_swipe_x = x;
	end_swipe_y = y;
}

Function* Config::GetFunction(int id) const {
	return (*function_ptr)[id];
}


double Config::GetScale() const {
	return scale;
}

double Config::SetScale(double x) {
	return scale = x;
}

void Config::PlaneEnabled(bool x) {
	plane_enable = x;
}
bool Config::isPlaneEnable() const {
	return plane_enable;
}

Matrix4 Config::GetRotation() const {
	return rotation;
}

void Config::SetRotation(Matrix4 rot, XRotate_Matrix l_x, YRotate_Matrix l_y) {
	rotation = l_x * l_y * rot;
}