#include "Function.h"
#include "MainFrame_Interface.h"

Function::Function(std::string bitmap_url, std::string name, wxPoint min) : name(name), min(min) {
	picture.LoadFile(bitmap_url, wxBITMAP_TYPE_PNG);
}
void Function::calc(double& x, double& y, double& z){}
const wxBitmap& Function::GetBitmap() const {
	return picture;
}
void Function::SetName(std::string new_name) {
	name = new_name;
}
const std::string& Function::GetName() const {
	return name;
}

ControlParam_Interface* Function::GetDialog() const {
	return dialog;
}
