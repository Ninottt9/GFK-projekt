#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/dcbuffer.h>
#include <wx/filefn.h> 

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame();
private:
	void OnExit(wxCloseEvent& event);
};


wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo01")
{
	SetTitle(_("Demo"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 570, 360);
	Center();

	Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnExit, this);
		//Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCloseEvent& event)
{
	if (
		wxMessageDialog(NULL, 
		"Are you sure you want to exit?", "Question", wxOK | wxCANCEL
	).ShowModal() == wxID_OK)
		Destroy();
}