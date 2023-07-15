#pragma once
#include <vector>
#include <string>
#include <random>
#include <SDL.h>

class SortingAlgorithm
{
public:
	// Sorting algorithms extracted from geeksforgeeks.org

	void initArray();
	void drawState(
		std::vector<int>& v,
		SDL_Renderer* renderer, 
		unsigned int red, 
		unsigned int blue);
	void killWindow();
	void prepareDraw(int red, int blue);

	int arraySize;
	int speed;
	std::vector<int> array;
	std::string algoChoice;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};

