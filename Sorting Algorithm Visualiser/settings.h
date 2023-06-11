#pragma once
#include <string>

class Settings
{
public:

	void setAlgo(std::string algorithm);
	void setSpeed(int speed);
	void setSize(int size);
	void toggleAudio(bool enabled);
	std::string getAlgo();
	int getSpeed();
	bool getAudioEnabled();
	int getSize();
private:

	std::string algorithmChosen;
	int executionSpeed;
	int arraySize;
	bool audioEnabled;
};
