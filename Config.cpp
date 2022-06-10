#include "Config.h"

Config::Config(std::vector<Function*>* function_ptr) : function_ptr(function_ptr)
{
	closed = true;
	x_min = -4;
	x_max = 5;
	y_min = -4;
	y_max = 5;
	z_min = -4;
	z_max = 5;
	length_of_arrows = 50;
	view_rot_x = 0;
	view_rot_y = 0;
	view_rot_z = 0;
	lenght_of_cut = 1;
	control = false;
	far_plane = 100.0;
	scale = 100;
	plane_enable = false;
	rotation = XRotate_Matrix(0);
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
double Config::GetBufferZ() const{
	return bufferZ;
}
unsigned int Config::GetCuts() const{
	return number_of_cuts;
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

double& Config::SetX_Min(double x){
	return x_min = x;
}
double& Config::SetX_Max(double x){
	return x_max = x;
}
double& Config::SetY_Min(double x){
	return y_min = x;
}
double& Config::SetY_Max(double x){
	return y_max = x;
}
double& Config::SetZ_Min(double x){
	return z_min = x;
}
double& Config::SetZ_Max(double x){
	return z_max = x;
}
double& Config::SetBufferZ(double x){
	return bufferZ = x;
}
unsigned int& Config::SetCuts(unsigned int x){
	return number_of_cuts = x;
}
double& Config::SetCutLen(double x){
	return lenght_of_cut = x;
}
Function* Config::SetCurrentFun(Function* fun){
	current_function = fun;
	return current_function;
}
unsigned int& Config::SetPrintOption(unsigned int x){
	return print_option = x;
}
double& Config::SetArrowsLen(double x){
	return length_of_arrows = x;
}

/* ================================================================ */

double Config::GetNearPlane() const{
	return 1.;
}
double Config::GetFarPlane() const{
	return far_plane *2 /5;

}
double Config::GetNearest() const{
	return nearest_point;

}
double Config::GetFurthest() const{
	return furthest_point;

}
unsigned int Config::GetListId() const{
	return 1;

}
double Config::GetStartX() const{
	return start_swipe_x;

}
double Config::GetStartY() const{
	return start_swipe_y;

}
double Config::GetSwipe() const{
	return 1.;

}

double& Config::SetNearPlane(double x){
	return near_plane;

}
double& Config::SetFarPlane(double x){
	return far_plane = x;

}
double& Config::SetNearest(double x){
	return nearest_point = x;

}
double& Config::SetFurthest(double x){
	return furthest_point = x;

}
unsigned int& Config::SetListId(unsigned int x){
	return id;

}
double& Config::SetStart(double x, double y){
	start_swipe_x = x;
	start_swipe_y = y;
	return start_swipe_x;

}



double Config::GetViewRotX() const {
	return view_rot_x;
}
double Config::GetViewRotY() const {
	return view_rot_y;
}
double Config::GetViewRotZ() const {
	return view_rot_z;
}



double& Config::SetViewRotX(double x) {
	return view_rot_x = x;
}
double& Config::SetViewRotY(double x) {
	return view_rot_y = x;
}
double& Config::SetViewRotZ(double x) {
	return view_rot_z = x;
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
double& Config::SetEnd(double x, double y){
	end_swipe_x = x;
	end_swipe_y = y;
	return end_swipe_x;
}

Function* Config::GetFunction(int id) const {
	return (*function_ptr)[id];
}

void Config::SetFunction(int id){
	this->id = id;
}

bool Config::GetControl() const {
	return control;
}

void Config::SetControl(bool x) {
	control = x;
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
void Config::SetRotation(XRotate_Matrix x, YRotate_Matrix y, ZRotate_Matrix z, XRotate_Matrix l_x, YRotate_Matrix l_y) {
	rotation =  l_x * l_y * z * y * x;
}

void Config::SetRotation(Matrix4 rot, XRotate_Matrix l_x, YRotate_Matrix l_y) {
	rotation = l_x * l_y * rot;
}