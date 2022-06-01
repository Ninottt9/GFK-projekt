#include "Dialog_Interface.h"

Dialog_Interface::Dialog_Interface(wxWindow* parent)
	:
	ControlDialog(parent)
{
	//wxPNGHandler* handler = new wxPNGHandler;
	//wxImage::AddHandler(handler);

	PlaneCtrl->SetSelection(20, 60);

	Function* gravity = new Gravity_Function();
	fun_list.push_back(gravity);

	Function* fun2 = new My_Function();
	fun_list.push_back(fun2);

	Function* fun3 = new My_Function2();
	fun_list.push_back(fun3);


	DisplayEquation->SetBitmap(gravity->GetBitmap(), wxTOP);
}

Dialog_Interface::Dialog_Interface(Config* config, wxWindow* parent)
	: Dialog_Interface(parent)
{
	current_config = config;
	Setup();
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
	int selection = ChoiceList->GetSelection();
	if (selection != wxNOT_FOUND) {
		fun_list[selection]->OpenDialog();
	}
}

void Dialog_Interface::ChoiceTextOnMouseEvents( wxMouseEvent& event )
{
}

void Dialog_Interface::ChoiceListOnListBox( wxCommandEvent& event )
{
	int selection = ChoiceList->GetSelection();
	if (selection != wxNOT_FOUND) {
		current_config->SetFunction(fun_list[selection]);
		wxString str = ChoiceList->GetString(selection);
		ChoiceText->SetLabelText("Wybrano: " + str);
		DisplayEquation->SetBitmap(current_config->GetFunction().GetBitmap(), wxTOP);
	}
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
	current_config->SetArrowsLen(50); // ?
}



void Dialog_Interface::Setup() {
	MinCtrl->SetValue(current_config->GetX_Min());
	MaxCtrl->SetValue(current_config->GetX_Max());
	MinCtrl1->SetValue(current_config->GetY_Min());
	MaxCtrl1->SetValue(current_config->GetY_Max());
	MinCtrl2->SetValue(current_config->GetZ_Min());
	MaxCtrl2->SetValue(current_config->GetZ_Max());
	ArrowCtrl->SetValue(current_config->GetArrowsLen());
	PrecisionCtrl->SetValue(current_config->GetCuts());
	PlaneCtrl->SetValue(current_config->GetFarPlane());
}