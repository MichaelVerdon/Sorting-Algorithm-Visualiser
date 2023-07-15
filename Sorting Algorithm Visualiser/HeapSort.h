#pragma once
#include "SortingAlgorithm.h"
class HeapSort : SortingAlgorithm
{
public:

	HeapSort(int size);
	void sort();
	void heapify( 
		int heapSize,
		int node
	);
};

