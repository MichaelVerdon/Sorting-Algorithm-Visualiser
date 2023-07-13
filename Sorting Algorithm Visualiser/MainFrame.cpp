#include "MainFrame.h"
#include <wx/wx.h>
#include "Settings.h"
#include <SDL.h>
#include "SortingAlgorithm.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include <thread>
#include "MergeSort.h"
#include "QuickSort.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	createGUI();
	bindEventHandlers();
}

void MainFrame::createGUI() {

	panel = new wxPanel(this);

	sarr.Add("Bubble Sort"); sarr.Add("Selection Sort"); sarr.Add("Insertion Sort");
	sarr.Add("Merge Sort"); sarr.Add("Quick Sort"); sarr.Add("Heap Sort");
	sarr.Add("Radix Sort");

	algorithmText = new wxStaticText(panel, wxID_ANY, "Sorting Algorithm", wxPoint(90, 10), wxSize(-1, -1));
	algoChoice = new wxChoice(panel, wxID_ANY, wxPoint(50, 30), wxSize(200, 100), sarr);
	algoChoice->SetSelection(0);

	speedText = new wxStaticText(panel, wxID_ANY, "Animation Speed (%)", wxPoint(80, 110), wxSize(-1, -1));
	speedSlider = new wxSlider(panel, wxID_ANY, 100, 10, 100, wxPoint(50, 70), wxSize(200, 100), wxSL_VALUE_LABEL);

	sizeText = new wxStaticText(panel, wxID_ANY, "Array Size", wxPoint(120, 180), wxSize(-1, -1));
	sizeSlider = new wxSlider(panel, wxID_ANY, 200, 50, 200, wxPoint(50, 140), wxSize(200, 100), wxSL_VALUE_LABEL);

	soundOption = new wxCheckBox(panel, wxID_ANY, "Audio", wxPoint(120, 210), wxSize(-1, -1));

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
	sizeSlider->Bind(wxEVT_SLIDER, &MainFrame::changeSize, this);
	soundOption->Bind(wxEVT_CHECKBOX, &MainFrame::toggleAudio, this);
}

void MainFrame::startClicked(wxCommandEvent& evt) {
	
	running = true;
	startState();
	std::thread sortThread([&]() {
		switch (algoChoice->GetSelection()) {
		case 0: {
			BubbleSort BubbleSort(100);
			break;
		}
		case 1: {
			SelectionSort SelectionSort(100);
			break;
		}
		case 2: {
			InsertionSort InsertionSort(100);
			break;
		}
		case 3: {
			MergeSort MergeSort(100);
		}
		case 4: {
			QuickSort QuickSort(100);
		}
	}
});

	sortThread.detach();
	
}

void MainFrame::pauseClicked(wxCommandEvent& evt) {

	pauseState();
}

void MainFrame::stopClicked(wxCommandEvent& evt) {

	initState();
}

void inline MainFrame::chooseAlgo(wxCommandEvent& evt) {

	int choiceIndex = algoChoice->GetSelection();
	// Convert to std::string
	settings.setAlgo(std::string(sarr[choiceIndex].mb_str()));
}

void inline MainFrame::changeSpeed(wxCommandEvent& evt) {

	settings.setSpeed(speedSlider->GetValue());
}

void inline MainFrame::changeSize(wxCommandEvent& evt) {

	settings.setSize(sizeSlider->GetValue());
}

void inline MainFrame::toggleAudio(wxCommandEvent& evt) {

	settings.toggleAudio(soundOption->GetValue());
}

void MainFrame::initState() {

	running = false;

	algoChoice->Enable();
	speedSlider->Enable();
	sizeSlider->Enable();
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
	sizeSlider->Disable();
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