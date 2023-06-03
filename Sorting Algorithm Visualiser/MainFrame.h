#pragma once
#include <wx/wx.h>
class MainFrame : public wxFrame
{
public:

	MainFrame(const wxString& title);
private:

	void createGUI();
	void bindEventHandlers();

	void initState();
	void startState();
	void pauseState();

	wxPanel* panel;

	wxStaticText* algorithmText;
	wxChoice* algoChoice;

	wxStaticText* speedText;
	wxSlider* speedSlider;

	wxButton* startButton;
	wxButton* pauseButton;
	wxButton* stopButton;

	wxCheckBox* soundOption;

	void startClicked(wxCommandEvent& evt);
	void pauseClicked(wxCommandEvent& evt);
	void stopClicked(wxCommandEvent& evt);
	void chooseAlgo(wxCommandEvent& evt);
	void changeSpeed(wxCommandEvent& evt);
	void toggleAudio(wxCommandEvent& evt);

	bool paused = false;
	bool running = false;

};

