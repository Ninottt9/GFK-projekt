#include "Dialog_Interface.h"

Dialog_Interface::Dialog_Interface( wxWindow* parent )
:
ControlDialog( parent )
{
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);

	PlaneCtrl->SetSelection(20, 60);
	eq1.LoadFile("eq1.png", wxBITMAP_TYPE_PNG);
	DisplayEquation->SetBitmap(eq1, wxTOP);
}

void Dialog_Interface::OnExit( wxCloseEvent& event )
{
// TODO: Implement OnExit
}
