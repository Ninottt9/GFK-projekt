#include <wx/wxprec.h>
#include "include/MainFrame_Interface.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

bool MyApp::OnInit()
{
	MainFrame_Interface* frame = new MainFrame_Interface(nullptr);
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(MyApp);