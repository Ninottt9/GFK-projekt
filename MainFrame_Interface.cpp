#include "MainFrame_Interface.h"

MainFrame_Interface::MainFrame_Interface( wxWindow* parent )
:
MainFrame( parent )
{
	SetTitle(_("GFK-Projekt"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 1200, 600);
	Center();
	controldialog = nullptr;
	if (!load_model("arrow1.geo", *this)) wxMessageBox("Failed to load");
	current_config = new Config();
	create_space(*current_config, data, arrow);

	current_config->SetPressed(false);
}

void MainFrame_Interface::OnExit( wxCloseEvent& event )
{
if (
wxMessageDialog(NULL,
"Are you sure you want to exit?", "Question", wxOK | wxCANCEL
).ShowModal() == wxID_OK)
Destroy();
}

void MainFrame_Interface::MainFrameOnLeftDown( wxMouseEvent& event )
{
	current_config->SetStart(event.GetX(), event.GetY());
}

void MainFrame_Interface::MainFrameOnLeftUp( wxMouseEvent& event )
{
	double x = current_config->GetStartX();
	double y = current_config->GetStartY();

	current_config->SetViewRotZ(0);
	current_config->SetViewRotX(x - event.GetX());
	current_config->SetViewRotY(y - event.GetY());
	current_config->SetPressed(false);
}

void MainFrame_Interface::MainFrameOnMotion( wxMouseEvent& event )
{
/*
double x = current_config->GetStartX();
double y = current_config->GetStartY();

current_config->SetViewRotZ(0);
current_config->SetViewRotX(x - event.GetX());
current_config->SetViewRotY(y - event.GetY());
*/

}

void MainFrame_Interface::Refresh( wxUpdateUIEvent& event )
{
	update_space(*current_config, data, arrow);
	draw_space(*current_config, data, DrawCanvas, _pic, MyImage);
}

void MainFrame_Interface::m_ControlPanelSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_File->FindItem("Control Panel"))) {
		controldialog = new Dialog_Interface(this);
		controldialog->Show();
		controldialog->current_config = current_config;
		this->SetFocus();
		current_config->closed = false;
	}
	else {
		if (!current_config->closed) {
			controldialog->Destroy();
			controldialog = nullptr;
		}
	}
}

void MainFrame_Interface::m_FunctionConfigSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_File->FindItem("Function Parameters"))) {
		controlparam = new ControlParam_Interface(this);
		controlparam->Show();
		this->SetFocus();
	}
	else {
		delete controlparam;
	}
	
}

void MainFrame_Interface::m_SaveAsSelection( wxCommandEvent& event )
{
	wxFileDialog fileDialog(this, "", "", "", "PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (fileDialog.ShowModal() == wxID_CANCEL)
		return;
	MyImage = _pic.ConvertToImage();
	MyImage.SaveFile(fileDialog.GetPath());
	return;
}

void MainFrame_Interface::m_QuitSelection( wxCommandEvent& event )
{
	if (
	wxMessageDialog(NULL,
	"Are you sure you want to exit?", "Question", wxOK | wxCANCEL
	).ShowModal() == wxID_OK)
	Destroy();
}

void MainFrame_Interface::m_AboutSelection( wxCommandEvent& event )
{
wxMessageDialog(this, "GFK - Projekt\nContributors:\n", "", wxOK).ShowModal();
}

void MainFrame_Interface::m_HelpSelection( wxCommandEvent& event )
{
	//if (Menu_File->IsChecked(Menu_About->FindItem("Help"))) {
		helpdialog = new HelpDialog_Interface(this);
		helpdialog->Show();
		this->SetFocus();
	//}
	//else {
//			delete helpdialog;
	//}
}

void MainFrame_Interface::DrawCanvasOnChar( wxKeyEvent& event )
{
// TODO: Implement DrawCanvasOnChar
}

void MainFrame_Interface::DrawCanvasOnLeftDown( wxMouseEvent& event )
{
	current_config->SetStart(event.GetX(), event.GetY());
	current_config->SetPressed(true);
}

void MainFrame_Interface::DrawCanvasOnLeftUp( wxMouseEvent& event )
{
	double x = current_config->GetStartX();
	double y = current_config->GetStartY();
	double e_x = current_config->GetEndX();
	double e_y = current_config->GetEndY();

	double new_x_rot = atan((e_x - x) / DrawCanvas->GetSize().GetWidth());
	double new_y_rot = atan((e_y - y) / DrawCanvas->GetSize().GetHeight());
	//new_x_rot = new_x_rot > 6.28 ? new_x_rot -  6.28 : new_x_rot;
	//new_y_rot = new_y_rot > 6.28 ? new_y_rot - 6.28 : new_y_rot;
	//new_x_rot = new_x_rot < 0 ? new_x_rot + 6.28 : new_x_rot;
	//new_y_rot = new_y_rot < 0 ? new_y_rot + 6.28 : new_y_rot;

	current_config->SetViewRotZ(0);
	//current_config->SetViewRotX(new_x_rot);
	//current_config->SetViewRotY(new_y_rot);
	current_config->SetViewRotX(new_x_rot + current_config->GetViewRotX());
	current_config->SetViewRotY(new_y_rot + current_config->GetViewRotY());
	current_config->SetPressed(false);
}

void MainFrame_Interface::DrawCanvasOnMotion( wxMouseEvent& event )
{
	bool pressed = current_config->GetPressed();
	if (pressed) {
		/*
		double x = current_config->GetStartX();
		double y = current_config->GetStartY();
	
		double new_x_rot = atan((event.GetX() - x) / DrawCanvas->GetSize().GetWidth());
		double new_y_rot = atan((event.GetY() - y) / DrawCanvas->GetSize().GetHeight());
		*/
		/*
		current_config->SetViewRotZ(0);
		current_config->SetViewRotX(x - event.GetX());
		current_config->SetViewRotY(y - event.GetY());
		*/
		//double new_x_rot = (current_config->GetViewRotX() + (x - event.GetX()));
		//double new_y_rot = (current_config->GetViewRotY() + (y - event.GetY()));
		//new_x_rot = new_x_rot > 6.28 ? new_x_rot - 6.28 : new_x_rot;
		//new_y_rot = new_y_rot > 6.28 ? new_y_rot - 6.28 : new_y_rot;
		//new_x_rot = new_x_rot < 0 ? new_x_rot + 6.28 : new_x_rot;
		//new_y_rot = new_y_rot < 0 ? new_y_rot + 6.28 : new_y_rot;

		//current_config->SetViewRotZ(0);
		//current_config->SetViewRotX(new_x_rot + current_config->GetViewRotX());
		//current_config->SetViewRotY(new_y_rot + current_config->GetViewRotY());
		current_config->SetEnd(event.GetX(), event.GetY());
	}
}

void MainFrame_Interface::DrawCanvasOnMouseWheel( wxMouseEvent& event )
{
}

void MainFrame_Interface::DrawCanvasOnRightDown( wxMouseEvent& event )
{
// TODO: Implement DrawCanvasOnRightDown
}

void MainFrame_Interface::DrawCanvasOnRightUp( wxMouseEvent& event )
{
// TODO: Implement DrawCanvasOnRightUp
}
