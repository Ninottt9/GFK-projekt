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
	
	Function* gravity = new Gravity_Function();
	fun_list.push_back(gravity);
	fun_list.push_back(new My_Function());
	fun_list.push_back(new My_Function2());

	current_config = new Config(&fun_list);
	current_config->SetCurrentFun(gravity);

	create_space(*current_config, data, arrow);
	current_config->SetPressed(false);
}

void MainFrame_Interface::OnExit( wxCloseEvent& event )
{
if (wxMessageDialog(NULL,"Are you sure you want to exit?", "Question", wxOK | wxCANCEL).ShowModal() == wxID_OK) Destroy();
}

void MainFrame_Interface::Refresh( wxUpdateUIEvent& event )
{
	update_space(*current_config, data, arrow);
	draw_space(*current_config, data, DrawCanvas, _pic, MyImage);
	if(Menu_File->IsChecked(Menu_File->FindItem("Control Panel")))	controldialog->SetPlane();
}

void MainFrame_Interface::m_ControlPanelSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_File->FindItem("Control Panel"))) {
		controldialog = new Dialog_Interface(current_config, this);
		controldialog->Show();
		this->SetFocus();
	}else {
		controldialog->Close();
		delete controldialog;
		controldialog = nullptr;
	}
}

void MainFrame_Interface::m_FunctionConfigSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_File->FindItem("Function Parameters"))) {
		//current_config->GetCurrentFun()->OpenDialog(this);
		OpenDialog(current_config->GetCurrentFun());
		this->SetFocus();
	}else {
		CloseDialog(current_config->GetCurrentFun());
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
	wxMessageDialog(this, "GFK - Projekt\nContributors:\n\n- Jan Bizoñ\n- Maksym Kazhaiev\n- Micha³ Rogowski\n", "", wxOK).ShowModal();
}

void MainFrame_Interface::m_HelpSelection( wxCommandEvent& event )
{
	if (Menu_About->IsChecked(Menu_About->FindItem("Help"))) {
		helpdialog = new HelpDialog_Interface(this);
		helpdialog->Show();
		this->SetFocus();
	}
	else {
		helpdialog->Destroy();
	}
}

void MainFrame_Interface::DrawCanvasOnLeftDown( wxMouseEvent& event )
{
	current_config->SetStart(event.GetY(), event.GetX());
	current_config->SetEnd(event.GetY(), event.GetX());
	current_config->SetPressed(true);
}

void MainFrame_Interface::DrawCanvasOnLeftUp( wxMouseEvent& event )
{
	double x = current_config->GetStartX();
	double y = current_config->GetStartY();
	double e_x = event.GetY();
	double e_y = event.GetX();
	double speed = 5.;

	//double new_y_rot =  speed * atan((y - e_y) / DrawCanvas->GetSize().GetHeight()) + current_config->GetViewRotY();
	//double new_x_rot = speed * atan((x - e_x) / DrawCanvas->GetSize().GetWidth()) + current_config->GetViewRotX();
	//double new_z_rot = speed * atan((y - e_y) / DrawCanvas->GetSize().GetHeight()) + current_config->GetViewRotZ();
	double new_y_rot = current_config->GetViewRotY();
	double new_x_rot = current_config->GetViewRotX();
	double new_z_rot = current_config->GetViewRotZ();
	double l_x_rot = atan((x - e_x) / DrawCanvas->GetSize().GetWidth());
	double l_y_rot = atan((y - e_y) / DrawCanvas->GetSize().GetHeight());
	local_to_global_rot(new_x_rot, new_y_rot, new_z_rot, l_x_rot, l_y_rot);

	current_config->SetViewRotZ(new_z_rot);
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
	current_config->SetScale(current_config->GetScale() + event.GetWheelRotation());
}

void MainFrame_Interface::CheckHandler(std::string name) {
	if (Menu_About->FindItem(name) != wxNOT_FOUND) {
		Menu_About->Check(Menu_About->FindItem(name), false);
	}
	else if (Menu_File->FindItem(name) != wxNOT_FOUND) {
		if (name == "Function Parameters") {
			Menu_File->Check(Menu_File->FindItem(name), false);
			//delete controlparam;
			controlparam = nullptr;
		}
		else if (name == "Control Panel") {
			Menu_File->Check(Menu_File->FindItem(name), false);
		}
	}
}


void MainFrame_Interface::OpenDialog(Function* fun) {
	CloseDialog(fun);
	
	if (fun->GetName() == "gravity")
		controlparam = new ControlParam_Interface(this, fun);
	else if (fun->GetName() == "water")
		controlparam = new ControlParam_Interface(this, fun);
	else if (fun->GetName() == "sin")
		controlparam = new ControlParam_Interface(this, fun);
	controlparam->Show();
	Menu_File->Check(Menu_File->FindItem("Function Parameters"), true);

}

void MainFrame_Interface::CloseDialog(Function* fun) {
	//ControlParam_Interface* dialog = fun->GetDialog();
	if (controlparam) {
		controlparam->Close();
		delete controlparam;
		controlparam = nullptr;
	}
}