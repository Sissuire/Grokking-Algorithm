#ifndef GROKKING_ALGORITHM_H_
#define GROKKING_ALGORITHM_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace GrokkingAlgorithm
{
	int Ch1_BinarySearch(const int *ascend_array, int num, int val);
	
	void Ch2_SelectionSort(std::list<int> lst, std::list<int> &sortedLst);

	int Ch3_Recursion(int val);

	int Ch4_MaxSquare(int w, int h);

	int Ch4_Sum(int *array, int num);

	void Ch4_QuickSort(int *array, int num);

	void Ch4_MergeSort(int *array, int num);

};

#endif