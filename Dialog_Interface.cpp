#include "Dialog_Interface.h"

std::vector<Function*> functions;

Dialog_Interface::Dialog_Interface(wxWindow* parent)
	:
	ControlDialog(parent)
{
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);

	PlaneCtrl->SetSelection(20, 60);
	eq1.LoadFile("eq1.png", wxBITMAP_TYPE_PNG);
	DisplayEquation->SetBitmap(eq1, wxTOP);

	Function* gravity = new Function();
	functions.push_back(gravity);
	Function* fun2 = new Function();
	Function* fun3 = new Function();
	functions.push_back(fun2);
	functions.push_back(fun3);
}

void Dialog_Interface::ControlDialogOnChar( wxKeyEvent& event )
{
// TODO: Implement ControlDialogOnChar
}

void Dialog_Interface::OnExit( wxCloseEvent& event )
{
	Destroy();
	current_config->closed = true;
}

void Dialog_Interface::DisplayEquationOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement DisplayEquationOnButtonClick
}

void Dialog_Interface::ChoiceTextOnMouseEvents( wxMouseEvent& event )
{
	/*
	int selection = ChoiceList->GetSelection();
	if (selection != wxNOT_FOUND) {
		wxString str = ChoiceList->GetString(selection);
		ChoiceText->SetLabelText("Wybrano: " + str);
	}
	*/
}

void Dialog_Interface::ChoiceListOnListBox( wxCommandEvent& event )
{
	int selection = ChoiceList->GetSelection();
	if (selection != wxNOT_FOUND) {
		current_config->SetCurrentFun(functions[selection]);
		wxString str = ChoiceList->GetString(selection);
		ChoiceText->SetLabelText("Wybrano: " + str);
		//ChoiceText->Center();
	}
	//Refresh();
}

void Dialog_Interface::PlaneEnableOnToggleButton( wxCommandEvent& event )
{
// TODO: Implement PlaneEnableOnToggleButton
}

void Dialog_Interface::PlaneCtrlOnScroll( wxScrollEvent& event )
{
// TODO: Implement PlaneCtrlOnScroll
}

void Dialog_Interface::PlaneCtrlOnSlider( wxCommandEvent& event )
{
// TODO: Implement PlaneCtrlOnSlider
}

void Dialog_Interface::X_MinCtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	current_config->SetX_Min(MinCtrl->GetValue());
}

void Dialog_Interface::X_MinCtrlOnSpinCtrlText( wxCommandEvent& event )
{
	current_config->SetX_Min(MinCtrl->GetValue());
}

void Dialog_Interface::X_MaxCtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	current_config->SetX_Max(MaxCtrl->GetValue());
}

void Dialog_Interface::X_MaxCtrlOnSpinCtrlText( wxCommandEvent& event )
{
	current_config->SetX_Max(MaxCtrl->GetValue());
}

void Dialog_Interface::Y_MinCtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	current_config->SetY_Min(MinCtrl1->GetValue());
}

void Dialog_Interface::Y_MinCtrl1OnSpinCtrlText( wxCommandEvent& event )
{
	current_config->SetY_Min(MinCtrl1->GetValue());
}

void Dialog_Interface::Y__MaxCtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	current_config->SetY_Max(MaxCtrl1->GetValue());
}

void Dialog_Interface::Y_MaxCtrlOnSpinCtrlText( wxCommandEvent& event )
{
	current_config->SetY_Max(MaxCtrl1->GetValue());
}

void Dialog_Interface::Z_MinCtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	current_config->SetZ_Min(MinCtrl2->GetValue());
}

void Dialog_Interface::Z_MinCtrlOnSpinCtrlText( wxCommandEvent& event )
{
	current_config->SetZ_Min(MinCtrl2->GetValue());
}

void Dialog_Interface::Z_MaxCtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
	current_config->SetZ_Max(MaxCtrl2->GetValue());
}

void Dialog_Interface::Z_MaxCtrlOnSpinCtrlText( wxCommandEvent& event )
{
	current_config->SetZ_Max(MaxCtrl2->GetValue());
}

void Dialog_Interface::PrecisionCtrlOnScroll( wxScrollEvent& event )
{
	current_config->SetCuts(PrecisionCtrl->GetValue());
}

void Dialog_Interface::PrecisionCtrlOnSlider( wxCommandEvent& event )
{
	current_config->SetCuts(PrecisionCtrl->GetValue());
}

void Dialog_Interface::ColorRadioOnRadioButton( wxCommandEvent& event )
{
	current_config->SetPrintOption(0);
}

void Dialog_Interface::LengthRadioOnRadioButton( wxCommandEvent& event )
{
	current_config->SetPrintOption(1);
}

void Dialog_Interface::ArrowCtrlOnScroll( wxScrollEvent& event )
{
	current_config->SetArrowsLen(ArrowCtrl->GetValue());
}

void Dialog_Interface::ArrowCtrlOnSlider( wxCommandEvent& event )
{
	current_config->SetArrowsLen(ArrowCtrl->GetValue());
}

void Dialog_Interface::Refresh() {
	current_config->SetArrowsLen(50);
}