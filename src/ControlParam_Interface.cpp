
#include "include/ControlParam_Interface.h"
#include "include/MainFrame_Interface.h"
#include "include/Function.h"

/*
ControlParam_Interface::ControlParam_Interface( wxWindow* parent )
: parent(static_cast<MainFrame_Interface*>(parent)), ControlParam(parent)
{

}
*/

ControlParam_Interface::ControlParam_Interface(wxWindow * parent, Function * fun)
	: parent(static_cast<MainFrame_Interface*>(parent)), function(fun), ControlParam(parent)
{
	DesciptionText->SetLabel("Wybrano: " + fun->GetName());
}

void ControlParam_Interface::OnExit( wxCloseEvent& event )
{
	Destroy();
	parent->CheckHandler("Function Parameters");
}

void ControlParam_Interface::Param1CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	if(function->GetName() == "Central")
		static_cast<Central_Field*>(function)->SetA(event.GetValue());
	else if(function->GetName() == "Sinusoidal")
		static_cast<Sinusoidal_Field*>(function)->SetA(event.GetValue());
	else if (function->GetName() == "Vortex")
		static_cast<Vortex_Field*>(function)->SetA(event.GetValue());
}

void ControlParam_Interface::Param2CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	if (function->GetName() == "Central")
		static_cast<Central_Field*>(function)->SetB(event.GetValue());
	else if (function->GetName() == "Sinusoidal")
		static_cast<Sinusoidal_Field*>(function)->SetB(event.GetValue());
	else if (function->GetName() == "Vortex")
		static_cast<Vortex_Field*>(function)->SetB(event.GetValue());
}

void ControlParam_Interface::Param3CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	if (function->GetName() == "Central")
		static_cast<Central_Field*>(function)->SetC(event.GetValue());
	else if (function->GetName() == "Sinusoidal")
		static_cast<Sinusoidal_Field*>(function)->SetC(event.GetValue());
	else if (function->GetName() == "Vortex")
		static_cast<Vortex_Field*>(function)->SetC(event.GetValue());
}


