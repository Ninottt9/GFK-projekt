#include "include/MainFrame_Interface.h"
#include "include/VectorMatrix.h"

MainFrame_Interface::MainFrame_Interface( wxWindow* parent )
:
MainFrame( parent )
{
	SetTitle(_("35.Wizualizacja pola wektorowego"));
	wxIcon icon = wxIcon(wxIconLocation((std::string)wxGetCwd() + "\\..\\res\\favicon.ico"));
	SetIcon(icon);
	SetSize(8, 8, 1200, 600);
	Center();

	_pic = wxBitmap(DrawCanvas->GetSize().GetWidth(), DrawCanvas->GetSize().GetHeight());
	MyImage.AddHandler(new wxPNGHandler);

	controldialog = nullptr;
	if (!load_model((std::string)wxGetCwd() + "\\..\\res\\arrow1.geo", *this)) wxMessageBox("Failed to load");
	
	fun_list.push_back(new Central_Field());
	fun_list.push_back(new Sinusoidal_Field());
	fun_list.push_back(new Vortex_Field());

	current_config = new Config(&fun_list);
}

MainFrame_Interface::~MainFrame_Interface() {
	if (current_config) delete current_config;
	for (auto& fun : fun_list) {
		delete fun;
	}
}

void MainFrame_Interface::OnExit( wxCloseEvent& event )
{
	if (wxMessageDialog(NULL,"Are you sure you want to exit?", "Question",
		wxOK | wxCANCEL).ShowModal() == wxID_OK) Destroy();
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
}

void MainFrame_Interface::m_QuitSelection( wxCommandEvent& event )
{
	if (wxMessageDialog(NULL,"Are you sure you want to exit?", "Question",
		wxOK | wxCANCEL).ShowModal() == wxID_OK)
	Destroy();
}

void MainFrame_Interface::m_AboutSelection( wxCommandEvent& event )
{
	wxMessageDialog(this, "GFK - Projekt\nAuthors:\n\n- Jan Bizoñ\n- Maksym Kazhaiev\n- Micha³ Rogowski\n", "", wxOK).ShowModal();
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

// Funkcja ustawiajaca rotacje po upuszczeniu przycisku
void MainFrame_Interface::DrawCanvasOnLeftUp( wxMouseEvent& event )
{
	double x = current_config->GetStartX();
	double y = current_config->GetStartY();
	double e_x = event.GetY();
	double e_y = event.GetX();
	double speed = 5.;

	double l_x_rot = speed * atan((x - e_x) / DrawCanvas->GetSize().GetWidth());
	double l_y_rot = speed * atan((y - e_y) / DrawCanvas->GetSize().GetHeight());
	XRotate_Matrix l_x(l_x_rot);
	YRotate_Matrix l_y(l_y_rot);
	current_config->SetRotation(current_config->GetRotation(), l_x, l_y);

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
			controlparam = nullptr;
		}
		else if (name == "Control Panel") {
			Menu_File->Check(Menu_File->FindItem(name), false);
		}
	}
}

// Niestety trzeba recznie podac nazwy funkcji w tym miejscu ( == ".....")
void MainFrame_Interface::OpenDialog(Function* fun) {
	CloseDialog(fun);
	
	if (fun->GetName() == "Central")
		controlparam = new ControlParam_Interface(this, fun);
	else if (fun->GetName() == "Sinusoidal")
		controlparam = new ControlParam_Interface(this, fun);
	else if (fun->GetName() == "Vortex")
		controlparam = new ControlParam_Interface(this, fun);
	controlparam->Show();
	Menu_File->Check(Menu_File->FindItem("Function Parameters"), true);

}

void MainFrame_Interface::CloseDialog(Function* fun) {
	if (controlparam) {
		controlparam->Close();
		delete controlparam;
		controlparam = nullptr;
	}
}