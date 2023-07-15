#pragma once
#include "SortingAlgorithm.h"
class HeapSort : SortingAlgorithm
{
public:

	HeapSort(int size, int animSpeed);
	void sort();
	void heapify( 
		int heapSize,
		int node
	);
};

