#include "Settings.h"
#include <string>

void Settings::setAlgo(std::string algorithm) {

	algorithmChosen = algorithm;
}

void Settings::setSpeed(int speed) {

	executionSpeed = speed;
}

void Settings::toggleAudio(bool enabled) {

	audioEnabled = enabled;
}

std::string Settings::getAlgo() {

	return algorithmChosen;
}

int Settings::getSpeed() {
	return executionSpeed;
}

bool Settings::getAudioEnabled() {
	return audioEnabled;
}