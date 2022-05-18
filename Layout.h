///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-231-gdf7791bf6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/tglbtn.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/radiobut.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* MainMenuBar;
		wxMenu* Menu_File;
		wxMenu* Menu_About;
		wxPanel* DrawCanvas;

		// Virtual event handlers, override them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void m_ControlPanelSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_QuitSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_AboutSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void Refresh( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxPoint( -1,-1 ), const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ControlDialog
///////////////////////////////////////////////////////////////////////////////
class ControlDialog : public wxDialog
{
	private:

	protected:
		wxBitmapButton* DisplayEquation;
		wxStaticText* ChoiceText;
		wxListBox* ChoiceList;
		wxStaticLine* Separator;
		wxStaticText* PlaneText;
		wxToggleButton* PlaneEnable;
		wxSlider* PlaneCtrl;
		wxStaticText* XLabel;
		wxStaticText* MinText;
		wxSpinCtrlDouble* MinCtrl;
		wxStaticText* MaxText;
		wxSpinCtrlDouble* MaxCtrl;
		wxStaticText* YLabel;
		wxStaticText* MinText1;
		wxSpinCtrlDouble* MinCtrl1;
		wxStaticText* MaxText1;
		wxSpinCtrlDouble* MaxCtrl1;
		wxStaticText* ZLabel;
		wxStaticText* MinText2;
		wxSpinCtrlDouble* MinCtrl2;
		wxStaticText* MaxText2;
		wxSpinCtrlDouble* MaxCtrl2;
		wxStaticText* PrecisionText;
		wxSlider* PrecisionCtrl;
		wxStaticLine* m_staticline2;
		wxStaticText* PrintingText;
		wxRadioButton* ColorRadio;
		wxRadioButton* LengthRadio;
		wxStaticText* ArrowText;
		wxSlider* ArrowCtrl;

		// Virtual event handlers, override them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }


	public:

		ControlDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Control"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,600 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );

		~ControlDialog();

};

