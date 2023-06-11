#include "Settings.h"
#include <string>

void Settings::setAlgo(std::string algorithm) {algorithmChosen = algorithm;}

void Settings::setSpeed(int speed) {executionSpeed = speed;}

void Settings::setSize(int size) {arraySize = size;}

void Settings::toggleAudio(bool enabled) {audioEnabled = enabled;}

std::string Settings::getAlgo() {return algorithmChosen;}

int Settings::getSpeed() {return executionSpeed;}

int Settings::getSize() {return arraySize;}

bool Settings::getAudioEnabled() {return audioEnabled;}