///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-231-gdf7791bf6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Layout.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	MainMenuBar = new wxMenuBar( 0 );
	Menu_File = new wxMenu();
	wxMenuItem* File_ControlPanel;
	File_ControlPanel = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Control Panel") ) + wxT('\t') + wxT("F1"), wxT("Turn on dialog to control input data for a vector space."), wxITEM_CHECK );
	Menu_File->Append( File_ControlPanel );

	wxMenuItem* File_SaveAs;
	File_SaveAs = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Save As") ) + wxT('\t') + wxT("F4"), wxEmptyString, wxITEM_NORMAL );
	Menu_File->Append( File_SaveAs );

	wxMenuItem* File_Quit;
	File_Quit = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Quit") ) + wxT('\t') + wxT("F2"), wxT("Quit app"), wxITEM_NORMAL );
	Menu_File->Append( File_Quit );

	MainMenuBar->Append( Menu_File, wxT("File") );

	Menu_About = new wxMenu();
	wxMenuItem* About_Info;
	About_Info = new wxMenuItem( Menu_About, wxID_ANY, wxString( wxT("About") ) + wxT('\t') + wxT("F3"), wxEmptyString, wxITEM_NORMAL );
	Menu_About->Append( About_Info );

	wxMenuItem* About_Help;
	About_Help = new wxMenuItem( Menu_About, wxID_ANY, wxString( wxT("Help") ) + wxT('\t') + wxT("F5"), wxEmptyString, wxITEM_NORMAL );
	Menu_About->Append( About_Help );

	MainMenuBar->Append( Menu_About, wxT("About") );

	this->SetMenuBar( MainMenuBar );

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );

	DrawCanvas = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	DrawCanvas->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	DrawCanvas->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	MainSizer->Add( DrawCanvas, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( MainSizer );
	this->Layout();
	MainSizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnExit ) );
	Menu_File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_ControlPanelSelection ), this, File_ControlPanel->GetId());
	Menu_File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_QuitSelection ), this, File_Quit->GetId());
	Menu_About->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_AboutSelection ), this, About_Info->GetId());
	DrawCanvas->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::Refresh ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnExit ) );
	DrawCanvas->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::Refresh ), NULL, this );

}

ControlDialog::ControlDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* DialogSizer;
	DialogSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* DisplaySizer;
	DisplaySizer = new wxBoxSizer( wxVERTICAL );

	DisplayEquation = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 400,100 ), wxBU_AUTODRAW|0 );
	DisplaySizer->Add( DisplayEquation, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	DialogSizer->Add( DisplaySizer, 1, wxEXPAND, 5 );

	ChoiceText = new wxStaticText( this, wxID_ANY, wxT("Wybrano: Funkcja1"), wxDefaultPosition, wxDefaultSize, 0 );
	ChoiceText->Wrap( -1 );
	DialogSizer->Add( ChoiceText, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	ChoiceList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	ChoiceList->Append( wxT("Funkcja eksponencjalna") );
	ChoiceList->Append( wxT("Funkcja wykladnicza") );
	ChoiceList->Append( wxT("Funkcja trygonometryczna") );
	DialogSizer->Add( ChoiceList, 0, wxALL|wxEXPAND, 5 );

	Separator = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	DialogSizer->Add( Separator, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* DialogVerticalSizer;
	DialogVerticalSizer = new wxBoxSizer( wxVERTICAL );

	PlaneText = new wxStaticText( this, wxID_ANY, wxT("Plaszczyzna"), wxDefaultPosition, wxDefaultSize, 0 );
	PlaneText->Wrap( -1 );
	DialogVerticalSizer->Add( PlaneText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	PlaneEnable = new wxToggleButton( this, wxID_ANY, wxT("Enable"), wxDefaultPosition, wxDefaultSize, 0 );
	DialogVerticalSizer->Add( PlaneEnable, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	PlaneCtrl = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_MIN_MAX_LABELS|wxSL_SELRANGE );
	DialogVerticalSizer->Add( PlaneCtrl, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* MinMaxSizer;
	MinMaxSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* X_MinMaxSizer;
	X_MinMaxSizer = new wxBoxSizer( wxHORIZONTAL );

	XLabel = new wxStaticText( this, wxID_ANY, wxT("X :"), wxDefaultPosition, wxDefaultSize, 0 );
	XLabel->Wrap( -1 );
	X_MinMaxSizer->Add( XLabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	X_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MinText = new wxStaticText( this, wxID_ANY, wxT("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	MinText->Wrap( -1 );
	X_MinMaxSizer->Add( MinText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MinCtrl = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0, 1 );
	MinCtrl->SetDigits( 0 );
	X_MinMaxSizer->Add( MinCtrl, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	X_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MaxText = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	MaxText->Wrap( -1 );
	X_MinMaxSizer->Add( MaxText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MaxCtrl = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0, 1 );
	MaxCtrl->SetDigits( 0 );
	X_MinMaxSizer->Add( MaxCtrl, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	MinMaxSizer->Add( X_MinMaxSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* Y_MinMaxSizer;
	Y_MinMaxSizer = new wxBoxSizer( wxHORIZONTAL );

	YLabel = new wxStaticText( this, wxID_ANY, wxT("Y :"), wxDefaultPosition, wxDefaultSize, 0 );
	YLabel->Wrap( -1 );
	Y_MinMaxSizer->Add( YLabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	Y_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MinText1 = new wxStaticText( this, wxID_ANY, wxT("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	MinText1->Wrap( -1 );
	Y_MinMaxSizer->Add( MinText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MinCtrl1 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0, 1 );
	MinCtrl1->SetDigits( 0 );
	Y_MinMaxSizer->Add( MinCtrl1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	Y_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MaxText1 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	MaxText1->Wrap( -1 );
	Y_MinMaxSizer->Add( MaxText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MaxCtrl1 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0, 1 );
	MaxCtrl1->SetDigits( 0 );
	Y_MinMaxSizer->Add( MaxCtrl1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	MinMaxSizer->Add( Y_MinMaxSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* Z_MinMaxSizer;
	Z_MinMaxSizer = new wxBoxSizer( wxHORIZONTAL );

	ZLabel = new wxStaticText( this, wxID_ANY, wxT("Z :"), wxDefaultPosition, wxDefaultSize, 0 );
	ZLabel->Wrap( -1 );
	Z_MinMaxSizer->Add( ZLabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	Z_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MinText2 = new wxStaticText( this, wxID_ANY, wxT("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	MinText2->Wrap( -1 );
	Z_MinMaxSizer->Add( MinText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MinCtrl2 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0, 1 );
	MinCtrl2->SetDigits( 0 );
	Z_MinMaxSizer->Add( MinCtrl2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	Z_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MaxText2 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	MaxText2->Wrap( -1 );
	Z_MinMaxSizer->Add( MaxText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MaxCtrl2 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0, 1 );
	MaxCtrl2->SetDigits( 0 );
	Z_MinMaxSizer->Add( MaxCtrl2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	MinMaxSizer->Add( Z_MinMaxSizer, 1, wxEXPAND, 5 );


	DialogVerticalSizer->Add( MinMaxSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* PrecisionSizer;
	PrecisionSizer = new wxBoxSizer( wxHORIZONTAL );

	PrecisionText = new wxStaticText( this, wxID_ANY, wxT("Dokladnosc : "), wxDefaultPosition, wxDefaultSize, 0 );
	PrecisionText->Wrap( -1 );
	PrecisionSizer->Add( PrecisionText, 0, wxALL, 5 );

	PrecisionCtrl = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
	PrecisionSizer->Add( PrecisionCtrl, 1, wxALL, 5 );


	DialogVerticalSizer->Add( PrecisionSizer, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	DialogVerticalSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* PrintingSizer;
	PrintingSizer = new wxBoxSizer( wxHORIZONTAL );

	PrintingText = new wxStaticText( this, wxID_ANY, wxT("Sposob wyswietlania: "), wxDefaultPosition, wxDefaultSize, 0 );
	PrintingText->Wrap( -1 );
	PrintingSizer->Add( PrintingText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	PrintingSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	ColorRadio = new wxRadioButton( this, wxID_ANY, wxT("Kolor"), wxDefaultPosition, wxDefaultSize, 0 );
	ColorRadio->SetValue( true );
	PrintingSizer->Add( ColorRadio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	LengthRadio = new wxRadioButton( this, wxID_ANY, wxT("Dlugosc"), wxDefaultPosition, wxDefaultSize, 0 );
	PrintingSizer->Add( LengthRadio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	DialogVerticalSizer->Add( PrintingSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* ArrowSizer;
	ArrowSizer = new wxBoxSizer( wxHORIZONTAL );

	ArrowText = new wxStaticText( this, wxID_ANY, wxT("Dlugosc strzalek : "), wxDefaultPosition, wxDefaultSize, 0 );
	ArrowText->Wrap( -1 );
	ArrowSizer->Add( ArrowText, 0, wxALL, 5 );

	ArrowCtrl = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
	ArrowSizer->Add( ArrowCtrl, 1, wxALL, 5 );


	DialogVerticalSizer->Add( ArrowSizer, 1, wxEXPAND, 5 );


	DialogSizer->Add( DialogVerticalSizer, 1, wxEXPAND, 5 );


	this->SetSizer( DialogSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlDialog::OnExit ) );
}

ControlDialog::~ControlDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlDialog::OnExit ) );

}
