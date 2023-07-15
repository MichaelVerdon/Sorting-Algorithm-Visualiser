#include "QuickSort.h"

QuickSort::QuickSort(int size) {

    arraySize = size;
    initArray();

    SDL_CreateWindowAndRenderer(
        size * 20, size * 10, 0,
        &window, &renderer
    );
    SDL_RenderSetScale(renderer, 10, 10);

    sort(0, arraySize-1);
    SDL_Delay(100);
    killWindow();
}

void QuickSort::sort(int start, int end) {
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(start, end);

    // Sorting the left part
    sort(start, p - 1);

    // Sorting the right part
    sort(p + 1, end);
}

int QuickSort::partition(int start, int end)
{
 
    int pivot = array[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (array[i] <= pivot)
            count++;
        prepareDraw(i, pivot);
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(array[pivotIndex], array[start]);
    prepareDraw(start, pivot);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (array[i] <= pivot) {
            i++;
            prepareDraw(i, pivot);
        }
 
        while (array[j] > pivot) {
            j--;
            prepareDraw(j, pivot);
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(array[i++], array[j--]);
            prepareDraw(i, j);
        }
    }
 
    return pivotIndex;
}

