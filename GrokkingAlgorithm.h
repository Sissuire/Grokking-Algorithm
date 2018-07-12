#ifndef GROKKING_ALGORITHM_H_
#define GROKKING_ALGORITHM_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>

class GrokkingAlgorithm
{
public:
	GrokkingAlgorithm();
	~GrokkingAlgorithm();

	void runDemoChapter_1();
	void runDemoChapter_2();
	void runDemoChapter_3();
	void runDemoChapter_4();
	void runDemoChapter_5();
	void runDemoChapter_6();
	void runDemoChapter_7();
	void runDemoChapter_8();
	void runDemoChapter_9();

private:
	int BinarySearch_Ch1(const int *ascend_array, int num, int val);
	void SelectionSort_Ch2(std::list<int> lst, std::list<int> &sortedLst);
	int Recursion_Ch3(int val);
	int MaxSquare_Ch4(int w, int h);
	int Sum_Ch4(int *array, int num);
	void QuickSort_Ch4(int *array, int num);
	void MergeSort_Ch4(int *array, int num);
	void HashTable_Ch5(std::map<std::string, int> &mapping);
	std::pair<bool, std::string> BreadthFirstSearch_Ch6(std::map<std::string, std::vector<std::string>> &relationNet, std::set<std::string> &seller);
	std::pair<std::vector<std::string>, int> Dijkstra_Ch7(std::map<std::string, std::map<std::string, int>> &graph);
	std::set<std::string> GreedyAlgorithm_Ch8(std::set<std::string> &states_needed, std::map<std::string, std::set<std::string>> &stations);
};

template<typename T> void PrintData(const T &data)
{
	auto iter = data.begin();
	while (iter != data.end())
		std::cout << *iter++ << ", ";
	std::cout << std::endl;

	return;
}

template<typename T> void PrintData(T *data, int num)
{
	int cnt = 0;
	for (; cnt != num; ++cnt)
		std::cout << data[cnt] << ", ";
	std::cout << std::endl;
	return;
}

#endif