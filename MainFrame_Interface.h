#ifndef __MainFrame_Interface__
#define __MainFrame_Interface__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "Layout.h"

//// end generated include

#include "Dialog_Interface.h"

/** Implementing MainFrame */
class MainFrame_Interface : public MainFrame
{
	protected:
		// Handlers for MainFrame events.
		void OnExit( wxCloseEvent& event );
		void m_ControlPanelSelection( wxCommandEvent& event );
		void m_QuitSelection( wxCommandEvent& event );
		void m_AboutSelection( wxCommandEvent& event );
		void Refresh( wxUpdateUIEvent& event );
	public:
		/** Constructor */
		MainFrame_Interface( wxWindow* parent );
	//// end generated class members

		Dialog_Interface* controldialog;
};

#endif // __MainFrame_Interface__
