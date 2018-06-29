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

	// ==================== demo Chapter 3 -- Recuresion ============================
	int num;
	while (std::cin >> num)
	{
		std::cout << "Fibonacci (" << num << " ) is " << GrokkingAlgorithm::Ch3_Recursion(num) << std::endl;
	}
	return 0;
}