
#include "ControlParam_Interface.h"
#include "MainFrame_Interface.h"
#include "Function.h"

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
	static_cast<Gravity_Function*>(function)->Set1(event.GetValue());
}

void ControlParam_Interface::Param1CtrlOnSpinCtrlText( wxCommandEvent& event )
{
}

void ControlParam_Interface::Param2CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	static_cast<Gravity_Function*>(function)->Set2(event.GetValue());
}

void ControlParam_Interface::Param2CtrlOnSpinCtrlText( wxCommandEvent& event )
{
}

void ControlParam_Interface::Param3CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	static_cast<Gravity_Function*>(function)->Set3(event.GetValue());
}

void ControlParam_Interface::Param3CtrlOnSpinCtrlText( wxCommandEvent& event )
{
// TODO: Implement Param3CtrlOnSpinCtrlText
}

