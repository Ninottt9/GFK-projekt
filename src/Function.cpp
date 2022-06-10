#include "include/Function.h"
#include "include/MainFrame_Interface.h"

Function::Function(std::string bitmap_url, std::string name)
	: name(name), dialog(nullptr), max(-2000)
{
	picture.LoadFile(bitmap_url, wxBITMAP_TYPE_PNG);
}
void Function::Transform(double& x, double& y, double& z)
{}
const wxBitmap& Function::GetBitmap() const 
{
	return picture;
}
const std::string& Function::GetName() const
{
	return name;
}