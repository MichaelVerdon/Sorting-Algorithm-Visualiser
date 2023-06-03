#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App); //Generate main function

//Entry point of app
bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("Sorting Algorithm Visualiser");
	//Resize window
	mainFrame->SetClientSize(500, 250);
	mainFrame->Center();
	mainFrame->Show();
	return true; //Tells wxwidgets processing continues, false is closes
}

