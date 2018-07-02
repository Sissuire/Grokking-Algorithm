#include "GrokkingAlgorithm.h"

int main()
{
	/*
	// ==================== demo Chapter 1 -- Binary Search =========================
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int val = 0;
	while (std::cin >> val)
	{
	std::cout << GrokkingAlgorithm::Ch1_BinarySearch(array, 12, val) << std::endl;
	}
	*/

	/*
	// ==================== demo Chapter 2 -- Selection Sort ========================
	std::list<int> lst = { 5, 3, 6, 2, 10 };
	std::list<int> sortedLst;

	GrokkingAlgorithm::Ch2_SelectionSort(lst, sortedLst);

	std::cout << "Original List:" << std::endl;
	for (auto &elem : lst)
	std::cout << elem << "\t";
	std::cout << std::endl << "Sorted List:" << std::endl;
	for (auto &elem : sortedLst)
	std::cout << elem << "\t";
	std::cout << std::endl;
	*/

	/*
	// ==================== demo Chapter 3 -- Recuresion ============================
	int num;
	while (std::cin >> num)
	{
	std::cout << "Fibonacci (" << num << " ) is " << GrokkingAlgorithm::Ch3_Recursion(num) << std::endl;
	}
	*/

	/*
	// ==================== demo Chapter 4 -- Quick Sort ============================

	// Max Square
	int  w, h;
	while (std::cin >> w >> h)
	{
	std::cout << "side length of the max square: " << GrokkingAlgorithm::Ch4_MaxSquare(w, h) << std::endl;
	}

	// Sum
	int array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << GrokkingAlgorithm::Ch4_Sum(array, 9) << std::endl;

	// Quick Sort
	int unorderedArray[11] = { 25, 6, 1, 3, 8, 10, 52, 30, 15, 0, 55 };
	std::cout << "\nQuick Sort\nunordered array:" << std::endl;
	for (int i = 0; i != 11; ++i)
	std::cout << unorderedArray[i] << " ";
	std::cout << std::endl;

	GrokkingAlgorithm::Ch4_QuickSort(unorderedArray, 11);
	std::cout << "ordered array:" << std::endl;
	for (int i = 0; i != 11; ++i)
	std::cout << unorderedArray[i] << " ";
	std::cout << std::endl;

	// Merge Sort
	int unorderedArray2[12] = { 5, 6, 100, 1, 3, 8, 10, 52, 30, 15, 0, 55 };
	std::cout << "\nMerge Sort\nunordered array:" << std::endl;
	for (int i = 0; i != 12; ++i)
	std::cout << unorderedArray2[i] << " ";
	std::cout << std::endl;

	GrokkingAlgorithm::Ch4_MergeSort(unorderedArray2, 12);
	std::cout << "ordered array:" << std::endl;
	for (int i = 0; i != 12; ++i)
	std::cout << unorderedArray2[i] << " ";
	std::cout << std::endl;
	*/

	// ==================== demo Chapter 5 -- Hash Table ============================
	GrokkingAlgorithm::Ch5_HashTable();

	return 0;
}