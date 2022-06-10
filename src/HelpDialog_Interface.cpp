#include "include/HelpDialog_Interface.h"
#include "include/MainFrame_Interface.h"

HelpDialog_Interface::HelpDialog_Interface(MainFrame_Interface* parent )
: parent(parent), HelpDialog( parent )
{}

void HelpDialog_Interface::OnExit( wxCloseEvent& event )
{
	parent->CheckHandler("Help");
	this->Destroy();
}
