#include "HeapSort.h"

HeapSort::HeapSort(int size, int animSpeed) {

    arraySize = size;
    speed = animSpeed;
    initArray();

    SDL_CreateWindowAndRenderer(
        size * 20, size * 10, 0,
        &window, &renderer
    );
    SDL_RenderSetScale(renderer, 10, 10);

    sort();
}

void HeapSort::sort() {
    // Build heap (rearrange array)
    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heapify(arraySize, i);

    // One by one extract an element
    // from heap
    for (int i = arraySize - 1; i > 0; i--) {

        // Move current root to end
        std::swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(i, 0);
        prepareDraw(i, 0);
    }
    SDL_Delay(100);
    killWindow();
}

void HeapSort::heapify(
    int heapSize,
    int node) {

    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < heapSize && array[left] > array[largest])
        largest = left;

    if (right < heapSize && array[right] > array[largest])
        largest = right;

    if (largest != node) {
        std::swap(array[node], array[largest]);
        prepareDraw(left, right);
        heapify(heapSize, largest);
    }
    prepareDraw(left, right);
}