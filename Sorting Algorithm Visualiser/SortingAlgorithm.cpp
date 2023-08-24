#include "SortingAlgorithm.h"


void SortingAlgorithm::initArray() {

	std::random_device rd;
	std::uniform_int_distribution<> distrib(1, 100);

	for (int i = 0; i < arraySize; i++) {

		array.push_back(distrib(rd));
	}
}

void SortingAlgorithm::drawState(

	std::vector<int>& vector, 
	SDL_Renderer* renderer, 
	unsigned int red, 
	unsigned int blue) {

	int index = 0;
	int offset = 0;

	for (int i : vector) {

		if (index == red) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		}
		else if (index == blue) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
		}
		SDL_RenderDrawLine(renderer, offset, 99, offset, i);
		index += 1;
		offset += 2;
	}
}

void SortingAlgorithm::killWindow() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// Quit SDL
	SDL_Quit();
}

void SortingAlgorithm::prepareDraw(int red, int blue) {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	// Draw sort state
	drawState(array, renderer, red, blue);
	// Show to window
	SDL_RenderPresent(renderer);
	// Delay
	SDL_Delay(pow(speed*0.2, -1) * 100);
}
