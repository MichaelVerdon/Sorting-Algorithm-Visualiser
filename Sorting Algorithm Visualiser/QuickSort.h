#pragma once
#include "SortingAlgorithm.h"
class QuickSort : SortingAlgorithm
{
public:

	QuickSort(int size, int animSpeed);
	void sort(int start, int end);
	int partition(int start, int end);
};


