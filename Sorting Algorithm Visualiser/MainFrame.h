#pragma once
#include <wx/wx.h>
#include "Settings.h"

class MainFrame : public wxFrame
{
public:

	MainFrame(const wxString& title);
private:

	//Add Controls for array init size
	void createGUI();
	void bindEventHandlers();

	void initState();
	void startState();

	wxPanel* panel;

	wxStaticText* algorithmText;
	wxChoice* algoChoice;
	wxArrayString sarr;

	wxStaticText* speedText;
	wxSlider* speedSlider;

	wxStaticText* sizeText;
	wxSlider* sizeSlider;

	wxButton* startButton;

	wxCheckBox* soundOption;

	void startClicked(wxCommandEvent& evt);
	void inline chooseAlgo(wxCommandEvent& evt);
	void inline changeSpeed(wxCommandEvent& evt);
	void inline changeSize(wxCommandEvent& evt);
	void inline toggleAudio(wxCommandEvent& evt);

	bool paused = false;
	bool running;

	Settings settings;
};
