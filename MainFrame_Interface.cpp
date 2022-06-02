#include "MainFrame_Interface.h"

MainFrame_Interface::MainFrame_Interface( wxWindow* parent )
:
MainFrame( parent )
{
	SetTitle(_("GFK-Projekt"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 1200, 600);
	Center();

	_pic = wxBitmap(DrawCanvas->GetSize().GetWidth(), DrawCanvas->GetSize().GetHeight());
	MyImage.AddHandler(new wxPNGHandler);

	controldialog = nullptr;
	if (!load_model("arrow1.geo", *this)) wxMessageBox("Failed to load");
	current_config = new Config(&fun_list);
	
	Function* gravity = new Gravity_Function();
	fun_list.push_back(gravity);

	Function* fun2 = new My_Function();
	fun_list.push_back(fun2);

	Function* fun3 = new My_Function2();
	fun_list.push_back(fun3);


	create_space(*current_config, data, arrow);
	current_config->SetPressed(false);
	current_config->SetCurrentFun(gravity);
}

void MainFrame_Interface::OnExit( wxCloseEvent& event )
{
if (wxMessageDialog(NULL,"Are you sure you want to exit?", "Question", wxOK | wxCANCEL).ShowModal() == wxID_OK) Destroy();
}

void MainFrame_Interface::Refresh( wxUpdateUIEvent& event )
{
	update_space(*current_config, data, arrow);
	draw_space(*current_config, data, DrawCanvas, _pic, MyImage);
}

void MainFrame_Interface::m_ControlPanelSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_File->FindItem("Control Panel"))) {
		controldialog = new Dialog_Interface(current_config, this);
		controldialog->Show();
		//controldialog->current_config = current_config;
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
		current_config->GetCurrentFun()->OpenDialog(current_config->GetControl());
		//controlparam->Show();
		this->SetFocus();
		current_config->SetControl(true);
	}
	else {
		current_config->GetCurrentFun()->CloseDialog(current_config->GetControl());
		current_config->SetControl(false);
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
	if (wxMessageDialog(NULL,"Are you sure you want to exit?", "Question", wxOK | wxCANCEL).ShowModal() == wxID_OK)
	Destroy();
}

void MainFrame_Interface::m_AboutSelection( wxCommandEvent& event )
{
wxMessageDialog(this, "GFK - Projekt\nContributors:\n", "", wxOK).ShowModal();
}

void MainFrame_Interface::m_HelpSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_About->FindItem("Help"))) {
		helpdialog = new HelpDialog_Interface(this);
		helpdialog->Show();
		this->SetFocus();
	}
	else {
			delete helpdialog;
	}
}

void MainFrame_Interface::DrawCanvasOnLeftDown( wxMouseEvent& event )
{
	current_config->SetStart(event.GetY(), event.GetX());
	current_config->SetPressed(true);
}

void MainFrame_Interface::DrawCanvasOnLeftUp( wxMouseEvent& event )
{
	double x = current_config->GetStartX();
	double y = current_config->GetStartY();
	double e_x = event.GetY();
	double e_y = event.GetX();
	double speed = 5.;

	double new_x_rot = speed * atan((x - e_x) / DrawCanvas->GetSize().GetWidth()) + current_config->GetViewRotX();
	double new_y_rot =  speed * atan((y - e_y) / DrawCanvas->GetSize().GetHeight()) + current_config->GetViewRotY();

	current_config->SetViewRotZ(0);
	current_config->SetViewRotX(new_x_rot);
	current_config->SetViewRotY(new_y_rot);
	current_config->SetPressed(false);
}

void MainFrame_Interface::DrawCanvasOnMotion( wxMouseEvent& event )
{
	bool pressed = current_config->GetPressed();
	if (pressed) {
		current_config->SetEnd(event.GetY(), event.GetX());
	}
}

void MainFrame_Interface::DrawCanvasOnMouseWheel( wxMouseEvent& event )
{
	current_config->SetArrowsLen(current_config->GetArrowsLen() + event.GetWheelRotation()/10);
}