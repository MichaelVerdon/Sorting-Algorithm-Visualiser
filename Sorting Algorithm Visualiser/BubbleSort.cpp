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
    for (i = 0; i < arraySize - 1; i++) {

        swapped = false;
        for (j = 0; j < arraySize - i - 1; j++) {

            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
            prepareDraw(i, j);
        }

        if (swapped == false)
            break;
    }
    SDL_Delay(100);
    killWindow();
}
