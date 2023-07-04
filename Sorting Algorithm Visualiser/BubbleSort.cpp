#include "BubbleSort.h"

BubbleSort::BubbleSort(int size) {

	arraySize = size;
	initArray();

    SDL_CreateWindowAndRenderer(
    size*20, size*10, 0,
        &window, &renderer
    );
    SDL_RenderSetScale(renderer, 10, 10);

	sort();
}

void BubbleSort::sort() {

    int i, j;
    bool swapped;
    for (i = 0; i < array.size() - 1; i++) {

        swapped = false;
        for (j = 0; j < array.size() - i - 1; j++) {

            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            // Draw sort state
            drawState(array, renderer, i, j);
            // Show to window
            SDL_RenderPresent(renderer);
            // Delay
            SDL_Delay(1);
        }

        if (swapped == false)
            break;
    }
    SDL_Delay(100);
    killWindow();
}
