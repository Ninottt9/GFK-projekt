#include "MainFrame_Interface.h"
#include <wx/msgdlg.h>

MainFrame_Interface::MainFrame_Interface( wxWindow* parent )
:
MainFrame( parent )
{
	SetTitle(_("GFK-Projekt"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 1200, 600);
	Center();
	controldialog = nullptr;
}

void MainFrame_Interface::OnExit( wxCloseEvent& event )
{
	if (
		wxMessageDialog(NULL,
			"Are you sure you want to exit?", "Question", wxOK | wxCANCEL
		).ShowModal() == wxID_OK)
		Destroy();
}

void MainFrame_Interface::m_ControlPanelSelection( wxCommandEvent& event )
{
	if (Menu_File->IsChecked(Menu_File->FindItem("Control Panel"))) {
		controldialog = new Dialog_Interface(this);
		controldialog->Show();
	}
	else {
		if (controldialog) {
			delete controldialog;
			controldialog = nullptr;
		}
	}
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
// TODO: Implement m_AboutSelection
}

void MainFrame_Interface::Refresh( wxUpdateUIEvent& event )
{
// TODO: Implement Refresh
}
