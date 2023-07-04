#pragma once
#include <vector>
#include <string>
#include <random>
#include <SDL.h>

class SortingAlgorithm
{
public:

	void initArray();
	void drawState(
		std::vector<int>& v,
		SDL_Renderer* renderer, 
		unsigned int red, 
		unsigned int blue);
	void killWindow();

	int arraySize;
	std::vector<int> array;
	std::string algoChoice;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};

