#pragma once
#include "SortingAlgorithm.h"

class MergeSort : SortingAlgorithm
{
public:

	MergeSort(int size, int animSpeed);
	void sort();
	void merge(int const left, int const mid,
		int const right);
	void mergeSort(int const begin, int const end);
};

