#include "Dialog_Interface.h"

Dialog_Interface::Dialog_Interface(wxWindow* parent)
	:
	ControlDialog(parent)
{
}

Dialog_Interface::Dialog_Interface(Config* config, wxWindow* parent)
	:current_config(config), ControlDialog(parent)
{
	PlaneCtrl->SetSelection(20, 60);
	DisplayEquation->SetBitmap(current_config->GetCurrentFun()->GetBitmap(), wxTOP);
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
		if (!current_config->GetControl()) {
			current_config->GetFunction(selection)->OpenDialog(current_config->GetControl());
			current_config->SetControl(true);
		}
	}
}

void Dialog_Interface::ChoiceTextOnMouseEvents( wxMouseEvent& event )
{
}

void Dialog_Interface::ChoiceListOnListBox( wxCommandEvent& event )
{
	int selection = ChoiceList->GetSelection();
	if (selection != wxNOT_FOUND) {
		current_config->SetCurrentFun(current_config->GetFunction(selection));
		wxString str = ChoiceList->GetString(selection);
		ChoiceText->SetLabelText("Wybrano: " + str);
		DisplayEquation->SetBitmap(current_config->GetFunction(selection)->GetBitmap(), wxTOP);
	}
}

void Dialog_Interface::PlaneEnableOnToggleButton( wxCommandEvent& event )
{
// TODO: Implement PlaneEnableOnToggleButton
}

void Dialog_Interface::PlaneCtrlOnScroll( wxScrollEvent& event )
{
	current_config->SetFarPlane(-PlaneCtrl->GetValue()/50);
}

void Dialog_Interface::PlaneCtrlOnSlider( wxCommandEvent& event )
{
	current_config->SetFarPlane(-PlaneCtrl->GetValue() / 50);
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
	current_config->SetCutLen(11 - PrecisionCtrl->GetValue() / 10);
}

void Dialog_Interface::PrecisionCtrlOnSlider( wxCommandEvent& event )
{
	current_config->SetCutLen(11 - PrecisionCtrl->GetValue()/10);
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
	PrecisionCtrl->SetValue((11 - current_config->GetCutLen()) * 10);
	PrecisionCtrl->SetTick((11 - current_config->GetCutLen()) * 10);
	PlaneCtrl->SetValue(current_config->GetFarPlane());
}