#pragma once
#include "SortingAlgorithm.h"
class QuickSort : SortingAlgorithm
{
public:

	QuickSort(int size);
	void sort(int start, int end);
	int partition(int start, int end);
};


