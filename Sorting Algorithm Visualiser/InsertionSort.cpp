#include "InsertionSort.h"

InsertionSort::InsertionSort(int size, int animSpeed) {

    arraySize = size;
    speed = animSpeed;
    initArray();

    SDL_CreateWindowAndRenderer(
        size * 20, 100 * 10, 0,
        &window, &renderer
    );
    SDL_RenderSetScale(renderer, 10, 10);

    sort();
    SDL_Delay(100);
    killWindow();
}

void InsertionSort::sort() {

    int i, key, j;
    for (i = 1; i < arraySize; i++) {
        key = array[i];
        j = i - 1;
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        prepareDraw(i, j);

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            prepareDraw(i, j);
        }
        array[j + 1] = key;
    }
}