#pragma once
#include <string>

class Settings
{
public:

	void setAlgo(std::string algorithm);
	void setSpeed(int speed);
	void toggleAudio(bool enabled);
	std::string getAlgo();
	int getSpeed();
	bool getAudioEnabled();
private:

	std::string algorithmChosen;
	int executionSpeed;
	bool audioEnabled;
};
