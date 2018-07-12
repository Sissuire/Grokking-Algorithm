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

	/*
	// ==================== demo Chapter 5 -- Hash Table ============================
	GrokkingAlgorithm::Ch5_HashTable();
	*/

	/*
	// ==================== demo Chapter 6 -- Breadth First Search ==================
	GrokkingAlgorithm::Ch6_BreadthFirstSearch();
	*/

	/*
	// ==================== demo Chapter 7 -- Dijkstra Algorithm ====================

	std::map<std::string, std::map<std::string, int>> graph;

	// graph 1
	graph["start"]["a"] = 5;
	graph["start"]["b"] = 0;
	graph["a"]["c"] = 15;
	graph["a"]["d"] = 20;
	graph["b"]["c"] = 30;
	graph["b"]["d"] = 35;
	graph["c"]["fin"] = 20;
	graph["d"]["fin"] = 10;

	//// graph 2
	//graph["start"]["A"] = 6;
	//graph["start"]["B"] = 2;
	//graph["A"]["fin"] = 1;
	//graph["B"]["A"] = 3;
	//graph["B"]["fin"] = 5;

	//// graph 3
	//graph["start"]["b"] = 5;
	//graph["start"]["c"] = 2;
	//graph["b"]["d"] = 4;
	//graph["b"]["e"] = 2;
	//graph["c"]["b"] = 8;
	//graph["c"]["e"] = 7;
	//graph["d"]["fin"] = 3;
	//graph["d"]["e"] = 6;
	//graph["e"]["fin"] = 1;

	//// graph 4
	//graph["start"]["b"] = 10;
	//graph["b"]["d"] = 20;
	//graph["d"]["c"] = 1;
	//graph["c"]["b"] = 1;
	//graph["d"]["fin"] = 30;

	//// graph 5
	//// This is a cyclic graph with negative side, no more Dijkstra
	//graph["start"]["b"] = 2;
	//graph["start"]["d"] = 2;
	//graph["d"]["b"] = 2;
	//graph["b"]["fin"] = 2;
	//graph["b"]["e"] = 2;
	//graph["e"]["d"] = -5;
	//graph["e"]["fin"] = 2;

	std::map<std::string, int> fin;
	graph["fin"] = fin;

	std::pair<std::vector<std::string>, int> ret;
	ret = GrokkingAlgorithm::Ch7_Dijkstra(graph);

	size_t i = 0, dims = ret.first.size();
	std::vector<std::string>::iterator iter;
	std::cout << "Shortest route:" << std::endl;
	for (iter = ret.first.begin(); i < dims - 1; ++i, ++iter)
	std::cout << *iter << " <- ";
	std::cout << *iter << std::endl << "Shortest distance:\t" << ret.second << std::endl;
	*/

	// ==================== demo Chapter 8 -- Greedy Algorithm ==================

	GrokkingAlgorithm::Ch8_GreedyAlgorithm();

	return 0;
}