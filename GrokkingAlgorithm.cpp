#include "GrokkingAlgorithm.h"

GrokkingAlgorithm::GrokkingAlgorithm(){}

GrokkingAlgorithm::~GrokkingAlgorithm(){}

void GrokkingAlgorithm::runDemoChapter_1()
{
	// ========= demo Chapter 1 -- Binary Search =========
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 1 -- Binary Search " << std::endl
		<< " =========================" << std::endl;

	std::cout<< "Original Data : " << std::endl;
	PrintData(array, 12);

	std::cout << "Input an integer for search: " << std::endl;

	int val = 0;
	std::cin >> val;

	std::cout << "search result: " << GrokkingAlgorithm::BinarySearch_Ch1(array, 12, val) << std::endl << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_2()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 2 -- Selection Sort " << std::endl
		<< " =========================" << std::endl;

	std::list<int> lst = { 5, 3, 6, 2, 10 };
	std::list<int> sortedLst;

	GrokkingAlgorithm::SelectionSort_Ch2(lst, sortedLst);

	std::cout << "Original List:" << std::endl;
	PrintData(lst);

	std::cout << "Sorted List:" << std::endl;
	PrintData(sortedLst);
	std::cout << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_3()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 3 -- Recursion " << std::endl
		<< " =========================" << std::endl;

	int num;
	std::cout << "Input an integer for Fibonacci number generation(no more than 20 is preferable):  ";
	std::cin >> num;
	std::cout << std::endl << "Fibonacci (" << num << ") is " << GrokkingAlgorithm::Recursion_Ch3(num) << std::endl << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_4()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 4 -- Quick Sort " << std::endl
		<< " =========================" << std::endl;

	/* Max Square */
	std::cout << std::endl << "solution for Max Square " << std::endl;
	std::cout << "Input two integers for width and height of a rectangle: " << std::endl;

	int  w, h;
	std::cin >> w >> h;
	std::cout << "side length of the max square: " << GrokkingAlgorithm::MaxSquare_Ch4(w, h) << std::endl;

	/* Sum */
	std::cout << std::endl << "solution for Sum " << std::endl;
	
	int array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << "Original Data: ";
	PrintData(array, 9);

	std::cout << "The sum is: " << GrokkingAlgorithm::Sum_Ch4(array, 9) << std::endl;

	/* Quick Sort */
	std::cout << std::endl << "solution for Quick Sort " << std::endl;
	int unorderedArray[11] = { 25, 6, 1, 3, 8, 10, 52, 30, 15, 0, 55 };
	std::cout << "Original Data: " << std::endl;
	PrintData(unorderedArray, 11);

	GrokkingAlgorithm::QuickSort_Ch4(unorderedArray, 11);
	std::cout << "ordered array:" << std::endl;
	PrintData(unorderedArray, 11);

	/* Merge Sort */
	std::cout << std::endl << "solution for Merge Sort " << std::endl;
	int unorderedArray2[12] = { 5, 6, 100, 1, 3, 8, 10, 52, 30, 15, 0, 55 };
	std::cout << "Original Data: " << std::endl;
	PrintData(unorderedArray2, 12);

	GrokkingAlgorithm::MergeSort_Ch4(unorderedArray2, 12);
	std::cout << "ordered array:" << std::endl;
	PrintData(unorderedArray2, 12);
	std::cout << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_5()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 5 -- Hash Table " << std::endl
		<< " =========================" << std::endl;

	std::cout << "Initialize a map | <name, age>" << std::endl;

	std::map<std::string, int> mapping{ { "Allen", 32 }, { "Bob", 22 }, { "Alice", 28 } };
	std::map < std::string, int>::iterator iter;

	std::cout << "Map is initialized as follows:" << std::endl;
	for (iter = mapping.begin(); iter != mapping.end(); ++iter)
		std::cout << "Name: " << iter->first << ",\tAge: " << iter->second << std::endl;

	GrokkingAlgorithm::HashTable_Ch5(mapping);
	std::cout << "\nAll in map are as follows:" << std::endl;
	for (iter = mapping.begin(); iter != mapping.end(); ++iter)
		std::cout << "Name: " << iter->first << ",\tAge: " << iter->second << std::endl;
	std::cout << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_6()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 6 -- Breadth First Search (BFS) " << std::endl
		<< " =========================" << std::endl;

	std::cout << "initialize a personal relationship network by hash map" << std::endl;
	std::map<std::string, std::vector<std::string>> relationNet{ { "you", { "alice", "bob", "claire" } },
	{ "bob", { "anuj", "peggy" } }, { "alice", { "peggy" } }, { "claire", { "thom", "jonny" } },
	{ "anuj", {} }, { "peggy", {} }, { "thom", { "you" } }, { "jonny", {} } };

	/* assume the right one */
	std::set<std::string> seller{ "jonny", "doggy", "catty" };

	std::pair<bool, std::string> ret = GrokkingAlgorithm::BreadthFirstSearch_Ch6(relationNet, seller);

	if (ret.first)
		std::cout << "FOUND!" << std::endl << ret.second << " is a seller!" << std::endl << std::endl;
	else
		std::cout << "Not FOUND !" << std::endl << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_7()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 7 -- Dijkstra Algorithm " << std::endl
		<< " =========================" << std::endl;

	std::map<std::string, std::map<std::string, int>> graph1, graph2, graph3, graph4, graph5;

	/* graph 1 */
	graph1["start"]["a"] = 5;
	graph1["start"]["b"] = 0;
	graph1["a"]["c"] = 15;
	graph1["a"]["d"] = 20;
	graph1["b"]["c"] = 30;
	graph1["b"]["d"] = 35;
	graph1["c"]["fin"] = 20;
	graph1["d"]["fin"] = 10;

	/* graph 2 */
	graph2["start"]["A"] = 6;
	graph2["start"]["B"] = 2;
	graph2["A"]["fin"] = 1;
	graph2["B"]["A"] = 3;
	graph2["B"]["fin"] = 5;

	/* graph 3 */
	graph3["start"]["b"] = 5;
	graph3["start"]["c"] = 2;
	graph3["b"]["d"] = 4;
	graph3["b"]["e"] = 2;
	graph3["c"]["b"] = 8;
	graph3["c"]["e"] = 7;
	graph3["d"]["fin"] = 3;
	graph3["d"]["e"] = 6;
	graph3["e"]["fin"] = 1;

	/* graph 4 */
	graph4["start"]["b"] = 10;
	graph4["b"]["d"] = 20;
	graph4["d"]["c"] = 1;
	graph4["c"]["b"] = 1;
	graph4["d"]["fin"] = 30;

	/* graph 5 */
 	/* This is a cyclic graph with negative side, no more Dijkstra */
	graph5["start"]["b"] = 2;
	graph5["start"]["d"] = 2;
	graph5["d"]["b"] = 2;
	graph5["b"]["fin"] = 2;
	graph5["b"]["e"] = 2;
	graph5["e"]["d"] = -5;
	graph5["e"]["fin"] = 2;

	std::map<std::string, int> fin;
	graph1["fin"] = graph2["fin"] = graph3["fin"] = graph4["fin"] = graph5["fin"] = fin;

	std::pair<std::vector<std::string>, int> ret1, ret2, ret3, ret4, ret5;
	ret1 = GrokkingAlgorithm::Dijkstra_Ch7(graph1);
	ret2 = GrokkingAlgorithm::Dijkstra_Ch7(graph2); 
	ret3 = GrokkingAlgorithm::Dijkstra_Ch7(graph3);
	ret4 = GrokkingAlgorithm::Dijkstra_Ch7(graph4);
	ret5 = GrokkingAlgorithm::Dijkstra_Ch7(graph5);


	size_t i = 0, dims;
	std::vector<std::string>::iterator iter;

	dims = ret1.first.size();
	std::cout << "Shortest route:" << std::endl;
	for (iter = ret1.first.begin(); i < dims - 1; ++i, ++iter)
		std::cout << *iter << " <- ";
	std::cout << *iter << std::endl << "Shortest distance:\t" << ret1.second << std::endl << std::endl;

	dims = ret2.first.size();
	std::cout << "Shortest route:" << std::endl;
	for (iter = ret2.first.begin(); i < dims - 1; ++i, ++iter)
		std::cout << *iter << " <- ";
	std::cout << *iter << std::endl << "Shortest distance:\t" << ret2.second << std::endl << std::endl;

	dims = ret3.first.size();
	std::cout << "Shortest route:" << std::endl;
	for (iter = ret3.first.begin(); i < dims - 1; ++i, ++iter)
		std::cout << *iter << " <- ";
	std::cout << *iter << std::endl << "Shortest distance:\t" << ret3.second << std::endl << std::endl;

	dims = ret4.first.size();
	std::cout << "Shortest route:" << std::endl;
	for (iter = ret4.first.begin(); i < dims - 1; ++i, ++iter)
		std::cout << *iter << " <- ";
	std::cout << *iter << std::endl << "Shortest distance:\t" << ret4.second << std::endl << std::endl;

	dims = ret5.first.size();
	std::cout << "Shortest route:" << std::endl;
	for (iter = ret5.first.begin(); i < dims - 1; ++i, ++iter)
		std::cout << *iter << " <- ";
	std::cout << *iter << std::endl << "Shortest distance:\t" << ret5.second << std::endl << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_8()
{
	std::cout << "\n =========================" << std::endl
		<< " Demo for Chapter 8 -- GreedyAlgorithm " << std::endl
		<< " =========================" << std::endl;

	/* prepare data */
	std::set<std::string> states_needed = { "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };
	std::map<std::string, std::set<std::string>> stations;
	stations["kone"] = std::set < std::string > { "id", "nv", "ut" };
	stations["ktwo"] = std::set < std::string > {"wa", "id", "mt"};
	stations["kthree"] = std::set < std::string > {"or", "nv", "ca"};
	stations["kfour"] = std::set < std::string > {"nv", "ut"};
	stations["kfive"] = std::set < std::string > {"ca", "az"};

	std::set<std::string> ret = GrokkingAlgorithm::GreedyAlgorithm_Ch8(states_needed, stations);
	if (!ret.empty())
	{
		std::cout << "Solution FOUND!" << std::endl;
		for (auto &elem : ret)
			std::cout << elem << ", ";
		std::cout << std::endl << std::endl;
	}
	else
		std::cout << "No Solution!" << std::endl << std::endl;

	return;
}

void GrokkingAlgorithm::runDemoChapter_9(){}
