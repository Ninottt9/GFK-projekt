///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-231-gdf7791bf6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "include/Layout.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	MainMenuBar = new wxMenuBar( 0 );
	Menu_File = new wxMenu();
	wxMenuItem* File_ControlPanel;
	File_ControlPanel = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Control Panel") ) + wxT('\t') + wxT("F1"), wxT("Turn on dialog to control input data for a vector space."), wxITEM_CHECK );
	Menu_File->Append( File_ControlPanel );

	wxMenuItem* File_FunctionConfig;
	File_FunctionConfig = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Function Parameters") ) + wxT('\t') + wxT("F2"), wxT("Turn on the dialog to control function parameters."), wxITEM_CHECK );
	Menu_File->Append( File_FunctionConfig );

	wxMenuItem* File_SaveAs;
	File_SaveAs = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Save As") ) + wxT('\t') + wxT("F3"), wxT("Save screenshot of vector field."), wxITEM_NORMAL );
	Menu_File->Append( File_SaveAs );

	wxMenuItem* File_Quit;
	File_Quit = new wxMenuItem( Menu_File, wxID_ANY, wxString( wxT("Quit") ) + wxT('\t') + wxT("F4"), wxT("Quit app"), wxITEM_NORMAL );
	Menu_File->Append( File_Quit );

	MainMenuBar->Append( Menu_File, wxT("File") );

	Menu_About = new wxMenu();
	wxMenuItem* About_Info;
	About_Info = new wxMenuItem( Menu_About, wxID_ANY, wxString( wxT("About") ) + wxT('\t') + wxT("F5"), wxT("Information about the app."), wxITEM_NORMAL );
	Menu_About->Append( About_Info );

	wxMenuItem* About_Help;
	About_Help = new wxMenuItem( Menu_About, wxID_ANY, wxString( wxT("Help") ) + wxT('\t') + wxT("F6"), wxT("Information about who to control the app."), wxITEM_CHECK );
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

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnExit ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::Refresh ) );
	Menu_File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_ControlPanelSelection ), this, File_ControlPanel->GetId());
	Menu_File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_FunctionConfigSelection ), this, File_FunctionConfig->GetId());
	Menu_File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_SaveAsSelection ), this, File_SaveAs->GetId());
	Menu_File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_QuitSelection ), this, File_Quit->GetId());
	Menu_About->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_AboutSelection ), this, About_Info->GetId());
	Menu_About->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_HelpSelection ), this, About_Help->GetId());
	DrawCanvas->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MainFrame::DrawCanvasOnLeftDown ), NULL, this );
	DrawCanvas->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::DrawCanvasOnLeftUp ), NULL, this );
	DrawCanvas->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::DrawCanvasOnMotion ), NULL, this );
	DrawCanvas->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( MainFrame::DrawCanvasOnMouseWheel ), NULL, this );
	DrawCanvas->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::Refresh ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnExit ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::Refresh ) );
	DrawCanvas->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MainFrame::DrawCanvasOnLeftDown ), NULL, this );
	DrawCanvas->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrame::DrawCanvasOnLeftUp ), NULL, this );
	DrawCanvas->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::DrawCanvasOnMotion ), NULL, this );
	DrawCanvas->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( MainFrame::DrawCanvasOnMouseWheel ), NULL, this );
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

	ChoiceText = new wxStaticText( this, wxID_ANY, wxT("Wybrano: -"), wxDefaultPosition, wxDefaultSize, 0 );
	ChoiceText->Wrap( -1 );
	DialogSizer->Add( ChoiceText, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	ChoiceList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	ChoiceList->Append( wxT("Function1") );
	ChoiceList->Append( wxT("Function2") );
	ChoiceList->Append( wxT("Function3") );
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

	MinCtrl = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 10000, 0, 1 );
	MinCtrl->SetDigits( 0 );
	X_MinMaxSizer->Add( MinCtrl, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	X_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MaxText = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	MaxText->Wrap( -1 );
	X_MinMaxSizer->Add( MaxText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MaxCtrl = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 10000, 0, 1 );
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

	MinCtrl1 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 10000, 0, 1 );
	MinCtrl1->SetDigits( 0 );
	Y_MinMaxSizer->Add( MinCtrl1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	Y_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MaxText1 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	MaxText1->Wrap( -1 );
	Y_MinMaxSizer->Add( MaxText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MaxCtrl1 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 10000, 0, 1 );
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

	MinCtrl2 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 10000, 0, 1 );
	MinCtrl2->SetDigits( 0 );
	Z_MinMaxSizer->Add( MinCtrl2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	Z_MinMaxSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	MaxText2 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	MaxText2->Wrap( -1 );
	Z_MinMaxSizer->Add( MaxText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	MaxCtrl2 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 10000, 0, 1 );
	MaxCtrl2->SetDigits( 0 );
	Z_MinMaxSizer->Add( MaxCtrl2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	MinMaxSizer->Add( Z_MinMaxSizer, 1, wxEXPAND, 5 );


	DialogVerticalSizer->Add( MinMaxSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* PrecisionSizer;
	PrecisionSizer = new wxBoxSizer( wxHORIZONTAL );

	PrecisionText = new wxStaticText( this, wxID_ANY, wxT("Dokladnosc : "), wxDefaultPosition, wxDefaultSize, 0 );
	PrecisionText->Wrap( -1 );
	PrecisionSizer->Add( PrecisionText, 0, wxALL, 5 );

	PrecisionCtrl = new wxSlider( this, wxID_ANY, 5, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
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
	this->Connect( wxEVT_CHAR, wxKeyEventHandler( ControlDialog::ControlDialogOnChar ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlDialog::OnExit ) );
	DisplayEquation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ControlDialog::DisplayEquationOnButtonClick ), NULL, this );
	ChoiceText->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_AUX1_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_AUX1_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_AUX2_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_AUX1_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_MOTION, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_AUX1_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_AUX2_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ControlDialog::ChoiceListOnListBox ), NULL, this );
	PlaneEnable->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( ControlDialog::PlaneEnableOnToggleButton ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Connect( wxEVT_SLIDER, wxCommandEventHandler( ControlDialog::PlaneCtrlOnSlider ), NULL, this );
	MinCtrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::X_MinCtrlOnSpinCtrlDouble ), NULL, this );
	MinCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::X_MinCtrlOnSpinCtrlText ), NULL, this );
	MaxCtrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::X_MaxCtrlOnSpinCtrlDouble ), NULL, this );
	MaxCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::X_MaxCtrlOnSpinCtrlText ), NULL, this );
	MinCtrl1->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Y_MinCtrlOnSpinCtrlDouble ), NULL, this );
	MinCtrl1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Y_MinCtrl1OnSpinCtrlText ), NULL, this );
	MaxCtrl1->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Y__MaxCtrlOnSpinCtrlDouble ), NULL, this );
	MaxCtrl1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Y_MaxCtrlOnSpinCtrlText ), NULL, this );
	MinCtrl2->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Z_MinCtrlOnSpinCtrlDouble ), NULL, this );
	MinCtrl2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Z_MinCtrlOnSpinCtrlText ), NULL, this );
	MaxCtrl2->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Z_MaxCtrlOnSpinCtrlDouble ), NULL, this );
	MaxCtrl2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Z_MaxCtrlOnSpinCtrlText ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Connect( wxEVT_SLIDER, wxCommandEventHandler( ControlDialog::PrecisionCtrlOnSlider ), NULL, this );
	ColorRadio->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ControlDialog::ColorRadioOnRadioButton ), NULL, this );
	LengthRadio->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ControlDialog::LengthRadioOnRadioButton ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Connect( wxEVT_SLIDER, wxCommandEventHandler( ControlDialog::ArrowCtrlOnSlider ), NULL, this );
}

ControlDialog::~ControlDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CHAR, wxKeyEventHandler( ControlDialog::ControlDialogOnChar ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlDialog::OnExit ) );
	DisplayEquation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ControlDialog::DisplayEquationOnButtonClick ), NULL, this );
	ChoiceText->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_AUX1_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_AUX1_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_AUX2_DOWN, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_AUX1_UP, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_MOTION, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_AUX1_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_AUX2_DCLICK, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceText->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( ControlDialog::ChoiceTextOnMouseEvents ), NULL, this );
	ChoiceList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ControlDialog::ChoiceListOnListBox ), NULL, this );
	PlaneEnable->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( ControlDialog::PlaneEnableOnToggleButton ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ControlDialog::PlaneCtrlOnScroll ), NULL, this );
	PlaneCtrl->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( ControlDialog::PlaneCtrlOnSlider ), NULL, this );
	MinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::X_MinCtrlOnSpinCtrlDouble ), NULL, this );
	MinCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::X_MinCtrlOnSpinCtrlText ), NULL, this );
	MaxCtrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::X_MaxCtrlOnSpinCtrlDouble ), NULL, this );
	MaxCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::X_MaxCtrlOnSpinCtrlText ), NULL, this );
	MinCtrl1->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Y_MinCtrlOnSpinCtrlDouble ), NULL, this );
	MinCtrl1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Y_MinCtrl1OnSpinCtrlText ), NULL, this );
	MaxCtrl1->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Y__MaxCtrlOnSpinCtrlDouble ), NULL, this );
	MaxCtrl1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Y_MaxCtrlOnSpinCtrlText ), NULL, this );
	MinCtrl2->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Z_MinCtrlOnSpinCtrlDouble ), NULL, this );
	MinCtrl2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Z_MinCtrlOnSpinCtrlText ), NULL, this );
	MaxCtrl2->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlDialog::Z_MaxCtrlOnSpinCtrlDouble ), NULL, this );
	MaxCtrl2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlDialog::Z_MaxCtrlOnSpinCtrlText ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ControlDialog::PrecisionCtrlOnScroll ), NULL, this );
	PrecisionCtrl->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( ControlDialog::PrecisionCtrlOnSlider ), NULL, this );
	ColorRadio->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ControlDialog::ColorRadioOnRadioButton ), NULL, this );
	LengthRadio->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ControlDialog::LengthRadioOnRadioButton ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ControlDialog::ArrowCtrlOnScroll ), NULL, this );
	ArrowCtrl->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( ControlDialog::ArrowCtrlOnSlider ), NULL, this );

}

ControlParam::ControlParam( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ParamSizer;
	ParamSizer = new wxBoxSizer( wxVERTICAL );


	ParamSizer->Add( 0, 40, 0, wxEXPAND, 5 );

	DesciptionText = new wxStaticText( this, wxID_ANY, wxT("Function: -"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	DesciptionText->Wrap( -1 );
	ParamSizer->Add( DesciptionText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ParamSizer->Add( 0, 20, 0, wxEXPAND, 5 );

	wxBoxSizer* ControlSizer;
	ControlSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* Param1Sizer;
	Param1Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param1Text = new wxStaticText( this, wxID_ANY, wxT("a :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param1Text->Wrap( -1 );
	Param1Sizer->Add( Param1Text, 0, wxALL, 5 );


	Param1Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param1Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1.000000, 0.01 );
	Param1Ctrl->SetDigits( 2 );
	Param1Sizer->Add( Param1Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param1Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* Param2Sizer;
	Param2Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param2Text = new wxStaticText( this, wxID_ANY, wxT("b :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param2Text->Wrap( -1 );
	Param2Sizer->Add( Param2Text, 0, wxALL, 5 );


	Param2Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param2Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1, 0.01 );
	Param2Ctrl->SetDigits( 2 );
	Param2Sizer->Add( Param2Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param2Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* Param3Sizer;
	Param3Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param3Text = new wxStaticText( this, wxID_ANY, wxT("c :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param3Text->Wrap( -1 );
	Param3Sizer->Add( Param3Text, 0, wxALL, 5 );


	Param3Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param3Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1, 0.01 );
	Param3Ctrl->SetDigits( 2 );
	Param3Sizer->Add( Param3Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param3Sizer, 1, wxEXPAND, 5 );


	ParamSizer->Add( ControlSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( ParamSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlParam::OnExit ) );
	Param1Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam::Param1CtrlOnSpinCtrlDouble ), NULL, this );
	Param1Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam::Param1CtrlOnSpinCtrlText ), NULL, this );
	Param2Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam::Param2CtrlOnSpinCtrlDouble ), NULL, this );
	Param2Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam::Param2CtrlOnSpinCtrlText ), NULL, this );
	Param3Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam::Param3CtrlOnSpinCtrlDouble ), NULL, this );
	Param3Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam::Param3CtrlOnSpinCtrlText ), NULL, this );
}

ControlParam::~ControlParam()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlParam::OnExit ) );
	Param1Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam::Param1CtrlOnSpinCtrlDouble ), NULL, this );
	Param1Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam::Param1CtrlOnSpinCtrlText ), NULL, this );
	Param2Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam::Param2CtrlOnSpinCtrlDouble ), NULL, this );
	Param2Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam::Param2CtrlOnSpinCtrlText ), NULL, this );
	Param3Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam::Param3CtrlOnSpinCtrlDouble ), NULL, this );
	Param3Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam::Param3CtrlOnSpinCtrlText ), NULL, this );

}

ControlParam2::ControlParam2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ParamSizer;
	ParamSizer = new wxBoxSizer( wxVERTICAL );


	ParamSizer->Add( 0, 40, 0, wxEXPAND, 5 );

	DesciptionText = new wxStaticText( this, wxID_ANY, wxT("Function: -"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	DesciptionText->Wrap( -1 );
	ParamSizer->Add( DesciptionText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ParamSizer->Add( 0, 20, 0, wxEXPAND, 5 );

	wxBoxSizer* ControlSizer;
	ControlSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* Param1Sizer;
	Param1Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param1Text = new wxStaticText( this, wxID_ANY, wxT("a :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param1Text->Wrap( -1 );
	Param1Sizer->Add( Param1Text, 0, wxALL, 5 );


	Param1Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param1Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1.000000, 0.01 );
	Param1Ctrl->SetDigits( 2 );
	Param1Sizer->Add( Param1Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param1Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* Param2Sizer;
	Param2Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param2Text = new wxStaticText( this, wxID_ANY, wxT("b :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param2Text->Wrap( -1 );
	Param2Sizer->Add( Param2Text, 0, wxALL, 5 );


	Param2Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param2Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1, 0.01 );
	Param2Ctrl->SetDigits( 2 );
	Param2Sizer->Add( Param2Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param2Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* Param3Sizer;
	Param3Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param3Text = new wxStaticText( this, wxID_ANY, wxT("c :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param3Text->Wrap( -1 );
	Param3Sizer->Add( Param3Text, 0, wxALL, 5 );


	Param3Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param3Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1, 0.01 );
	Param3Ctrl->SetDigits( 2 );
	Param3Sizer->Add( Param3Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param3Sizer, 1, wxEXPAND, 5 );


	ParamSizer->Add( ControlSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( ParamSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlParam2::OnExit ) );
	Param1Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam2::Param1CtrlOnSpinCtrlDouble ), NULL, this );
	Param1Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam2::Param1CtrlOnSpinCtrlText ), NULL, this );
	Param2Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam2::Param2CtrlOnSpinCtrlDouble ), NULL, this );
	Param2Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam2::Param2CtrlOnSpinCtrlText ), NULL, this );
	Param3Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam2::Param3CtrlOnSpinCtrlDouble ), NULL, this );
	Param3Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam2::Param3CtrlOnSpinCtrlText ), NULL, this );
}

ControlParam2::~ControlParam2()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlParam2::OnExit ) );
	Param1Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam2::Param1CtrlOnSpinCtrlDouble ), NULL, this );
	Param1Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam2::Param1CtrlOnSpinCtrlText ), NULL, this );
	Param2Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam2::Param2CtrlOnSpinCtrlDouble ), NULL, this );
	Param2Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam2::Param2CtrlOnSpinCtrlText ), NULL, this );
	Param3Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam2::Param3CtrlOnSpinCtrlDouble ), NULL, this );
	Param3Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam2::Param3CtrlOnSpinCtrlText ), NULL, this );

}

ControlParam3::ControlParam3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ParamSizer;
	ParamSizer = new wxBoxSizer( wxVERTICAL );


	ParamSizer->Add( 0, 40, 0, wxEXPAND, 5 );

	DesciptionText = new wxStaticText( this, wxID_ANY, wxT("Function: -"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	DesciptionText->Wrap( -1 );
	ParamSizer->Add( DesciptionText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ParamSizer->Add( 0, 20, 0, wxEXPAND, 5 );

	wxBoxSizer* ControlSizer;
	ControlSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* Param1Sizer;
	Param1Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param1Text = new wxStaticText( this, wxID_ANY, wxT("a :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param1Text->Wrap( -1 );
	Param1Sizer->Add( Param1Text, 0, wxALL, 5 );


	Param1Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param1Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1.000000, 0.01 );
	Param1Ctrl->SetDigits( 2 );
	Param1Sizer->Add( Param1Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param1Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* Param2Sizer;
	Param2Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param2Text = new wxStaticText( this, wxID_ANY, wxT("b :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param2Text->Wrap( -1 );
	Param2Sizer->Add( Param2Text, 0, wxALL, 5 );


	Param2Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param2Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1, 0.01 );
	Param2Ctrl->SetDigits( 2 );
	Param2Sizer->Add( Param2Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param2Sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* Param3Sizer;
	Param3Sizer = new wxBoxSizer( wxHORIZONTAL );

	Param3Text = new wxStaticText( this, wxID_ANY, wxT("c :"), wxDefaultPosition, wxDefaultSize, 0 );
	Param3Text->Wrap( -1 );
	Param3Sizer->Add( Param3Text, 0, wxALL, 5 );


	Param3Sizer->Add( 100, 0, 0, wxEXPAND, 5 );

	Param3Ctrl = new wxSpinCtrlDouble( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, -100, 100, 1, 0.01 );
	Param3Ctrl->SetDigits( 2 );
	Param3Sizer->Add( Param3Ctrl, 0, wxALL, 5 );


	ControlSizer->Add( Param3Sizer, 1, wxEXPAND, 5 );


	ParamSizer->Add( ControlSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( ParamSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlParam3::OnExit ) );
	Param1Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam3::Param1CtrlOnSpinCtrlDouble ), NULL, this );
	Param1Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam3::Param1CtrlOnSpinCtrlText ), NULL, this );
	Param2Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam3::Param2CtrlOnSpinCtrlDouble ), NULL, this );
	Param2Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam3::Param2CtrlOnSpinCtrlText ), NULL, this );
	Param3Ctrl->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam3::Param3CtrlOnSpinCtrlDouble ), NULL, this );
	Param3Ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam3::Param3CtrlOnSpinCtrlText ), NULL, this );
}

ControlParam3::~ControlParam3()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ControlParam3::OnExit ) );
	Param1Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam3::Param1CtrlOnSpinCtrlDouble ), NULL, this );
	Param1Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam3::Param1CtrlOnSpinCtrlText ), NULL, this );
	Param2Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam3::Param2CtrlOnSpinCtrlDouble ), NULL, this );
	Param2Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam3::Param2CtrlOnSpinCtrlText ), NULL, this );
	Param3Ctrl->Disconnect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( ControlParam3::Param3CtrlOnSpinCtrlDouble ), NULL, this );
	Param3Ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ControlParam3::Param3CtrlOnSpinCtrlText ), NULL, this );

}

HelpDialog::HelpDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxStaticBoxSizer* HelpSizer;
	HelpSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Help") ), wxVERTICAL );

	HelpText = new wxStaticText( HelpSizer->GetStaticBox(), wxID_ANY, wxT("Obrot - LPM\nPrzyblizenie - Scroll\n\nOdciecie wykresu odbywa sie przez plaszczyzne rownolegla do widoku.\nNa pasku postepu wyswitlany jest zakres ( przedstawia najbardziej oddalony punkt oraz punkt najblizszy).\nSuwakiem kontrolujemy plaszczyzne odcinajaca strzalki.\n\nAplikacja posiada dwa dialogi : \n- Jeden do kontroli wyswietlanego obszaru\n- Drugi do kontroli parametrow swobodnych\n\n"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	HelpText->Wrap( -1 );
	HelpSizer->Add( HelpText, 0, wxALL, 5 );


	this->SetSizer( HelpSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HelpDialog::OnExit ) );
}

HelpDialog::~HelpDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HelpDialog::OnExit ) );

}
