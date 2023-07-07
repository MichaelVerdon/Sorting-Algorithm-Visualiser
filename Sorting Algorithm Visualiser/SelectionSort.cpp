#include "SelectionSort.h"

SelectionSort::SelectionSort(int size) {

	arraySize = size;
    initArray();

    SDL_CreateWindowAndRenderer(
        size * 20, size * 10, 0,
        &window, &renderer
    );
    SDL_RenderSetScale(renderer, 10, 10);

    sort();
}

void SelectionSort::sort() {
    int i, j, min_idx;

    // One by one
    for (i = 0; i < arraySize - 1; i++) {

        // Find the min element
        min_idx = i;
        for (j = i + 1; j < arraySize; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
            prepareDraw(i, min_idx);
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            std::swap(array[min_idx], array[i]);
        prepareDraw(i, min_idx);
    }
    SDL_Delay(100);
    killWindow();

}