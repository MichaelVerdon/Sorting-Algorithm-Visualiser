#include "MainFrame.h"
#include <wx/wx.h>
#include <SDL.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	createGUI();
	bindEventHandlers();
}

void MainFrame::createGUI() {

	panel = new wxPanel(this);

	wxArrayString sarr;
	sarr.Add("Bubble Sort");

	algorithmText = new wxStaticText(panel, wxID_ANY, "Sorting Algorithm", wxPoint(90, 30), wxSize(-1, -1));
	algoChoice = new wxChoice(panel, wxID_ANY, wxPoint(50, 50), wxSize(200, 100), sarr);
	algoChoice->SetSelection(0);

	speedText = new wxStaticText(panel, wxID_ANY, "Animation Speed (%)", wxPoint(80, 140), wxSize(-1, -1));
	speedSlider = new wxSlider(panel, wxID_ANY, 100, 10, 100, wxPoint(50, 100), wxSize(200, 100), wxSL_VALUE_LABEL);

	soundOption = new wxCheckBox(panel, wxID_ANY, "Audio", wxPoint(120, 190), wxSize(-1, -1));

	startButton = new wxButton(panel, wxID_ANY, "Start", wxPoint(350, 50), wxSize(100, -1));
	pauseButton = new wxButton(panel, wxID_ANY, "Pause", wxPoint(350, 80), wxSize(100, -1));
	stopButton = new wxButton(panel, wxID_ANY, "Stop", wxPoint(350, 110), wxSize(100, -1));

	CreateStatusBar();

	initState();
}

void MainFrame::bindEventHandlers() {

	startButton->Bind(wxEVT_BUTTON, &MainFrame::startClicked, this);
	pauseButton->Bind(wxEVT_BUTTON, &MainFrame::pauseClicked, this);
	stopButton->Bind(wxEVT_BUTTON, &MainFrame::stopClicked, this);

	algoChoice->Bind(wxEVT_CHOICE, &MainFrame::chooseAlgo, this);
	speedSlider->Bind(wxEVT_SLIDER, &MainFrame::changeSpeed, this);
	soundOption->Bind(wxEVT_CHECKBOX, &MainFrame::toggleAudio, this);
}

void MainFrame::startClicked(wxCommandEvent& evt) {
	
	running = true;
	startState();
	wxLogStatus("Running");
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Starting", "Worked", NULL);
}

void MainFrame::pauseClicked(wxCommandEvent& evt) {

	pauseState();
}

void MainFrame::stopClicked(wxCommandEvent& evt) {

	running = false;
	initState();
}

void MainFrame::chooseAlgo(wxCommandEvent& evt) {

}

void MainFrame::changeSpeed(wxCommandEvent& evt) {

}

void MainFrame::toggleAudio(wxCommandEvent& evt) {

}

void MainFrame::initState() {

	algoChoice->Enable();
	speedSlider->Enable();
	soundOption->Enable();
	startButton->Enable();
	pauseButton->Disable();
	pauseButton->SetLabel("Pause");
	stopButton->Disable();
	wxLogStatus("Not Running");
}

void MainFrame::startState() {

	running = true;

	algoChoice->Disable();
	speedSlider->Disable();
	soundOption->Disable();
	startButton->Disable();
	pauseButton->Enable();
	stopButton->Enable();
}

void MainFrame::pauseState() {

	paused = !paused;

	if (paused && running) {

		pauseButton->SetLabel("Resume");
		wxLogStatus("Paused");
	}
	else if (running) {

		pauseButton->SetLabel("Pause");
		wxLogStatus("Running");
	}
}