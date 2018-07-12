#include "GrokkingAlgorithm.h"

//template<typename T> void PrintData(const T &data)
//{
//	auto iter = data.begin();
//	while (iter != data.end())
//		std::cout << *iter++ << ", ";
//	std::cout << std::endl;
//
//	return;
//}
//
//template<typename T> void PrintData(T *data, int num)
//{
//	int cnt = 0;
//	for (; cnt != num; ++cnt)
//		std::cout << data[cnt] << ", ";
//
//	return;
//}

int InBinarySearch(const int *array, int pos1, int pos2, int val)
{
	/* Binary Search for recursive computation */
	int pos = -1;
	int j = (pos1 + pos2) / 2;

	if (pos1 > pos2);
	else
	{
		if (val == array[j])
			pos = j;
		else if (val < array[j])
			pos = InBinarySearch(array, pos1, j - 1, val);
		else if (val > array[j])
			pos = InBinarySearch(array, j + 1, pos2, val);
	}

	return pos;
}

int GrokkingAlgorithm::BinarySearch_Ch1(const int *ascend_array, int num, int val)
{
	/* Binary Search
	*
	*  Params:
	*		- ascend_array£¬ int pointer for an ascend-sorted array
	*		- num, length of input array
	*		- val, value to be searched.
	*
	*  Out
	*		return position if found, else -1.
	*/

	/* recursive */
	//return InBinarySearch(ascend_array, 0, num - 1, val);

	/* loop */
	int pos1 = 0, pos2 = num - 1;
	int pos = -1, j;
	while (pos1 <= pos2)
	{
		j = (pos1 + pos2) / 2;

		if (val == ascend_array[j])
		{
			pos = j;
			break;
		}
		else if (val < ascend_array[j])
			pos2 = j - 1;
		else if (val > ascend_array[j])
			pos1 = j + 1;
	}

	return pos;
}

void SelectionSort(int *array, int num)
{
	int val = INT_MAX;
	int pos = 0;
	int j, counter = 0;
	int temp;

	while (counter != num)
	{
		val = INT_MAX;
		for (j = counter; j != num; ++j)
		{
			if (val > array[j])
			{
				val = array[j];
				pos = j;
			}
		}

		temp = array[counter];
		array[counter] = val;
		array[pos] = temp;

		++counter;
	}

	return;
}

void Ch2_SelectionSortInArray(int *array, int *sortedArray, int num)
{
	/* Selection Sort for array rather than list
	*
	*  Params:
	*		- array, int pointer for input unordered array
	*		- sortedArray, int pointer for output ordered array
	*		- num, length of array
	*
	*  NOTE:
	*		MAKE SURE these's enough malloc memory for output sortedArray.
	*/

	int *temp = (int *)malloc(sizeof(int)*num);
	memcpy(temp, array, sizeof(int)*num);

	int val = INT_MAX;
	int pos = 0;
	int counter = num;
	int j;

	while (counter)
	{
		val = INT_MAX;
		for (j = 0; j != num; ++j)
		{
			if (val > temp[j])
			{
				val = temp[j];
				pos = j;
			}
		}

		temp[pos] = INT_MAX;
		sortedArray[num - counter--] = val;
	}

	free(temp);
	return;
}

void GrokkingAlgorithm::SelectionSort_Ch2(std::list<int> lst, std::list<int> &sortedLst)
{
	/* Selection Sort
	*
	*  Params:
	*		- lst, input unordered list
	*		- sortedLst, output ordered list
	*
	*  Why choose list<int> ?
	*		Fairly for quickly deleting element
	*
	*  Note:
	*		- The idea in this book is to generate a new array/list and delete the original one.
	*		- My preference is to swap data as "SelectionSort" function on the beginning of this file.
	*
	*/

	int val;
	std::list<int>::iterator iter_min;
	std::list<int>::iterator iter;

	while (lst.begin() != lst.end())
	{
		val = INT_MAX;
		for (iter = lst.begin(); iter != lst.end(); ++iter)
		{
			if (val > *iter)
			{
				val = *iter;
				iter_min = iter;
			}
		}
		sortedLst.push_back(val);
		lst.erase(iter_min);
	}

	/*
	// ======================================
	// test for Ch2_SelectionSortInArray(int *array, int *sortedArray, int num)
	// ======================================

	int a[5] = { 5, 2, 6, 3, 8 };
	int *b = (int *)malloc(sizeof(int) * 5);
	Ch2_SelectionSortInArray(a, b, 5);

	std::cout << "Original List:" << std::endl;
	for (int i = 0; i != 5; ++i)
	std::cout << a[i] << "\t";
	std::cout << std::endl << "Sorted List:" << std::endl;
	for (int i = 0; i != 5; ++i)
	std::cout << b[i] << "\t";
	std::cout << std::endl;
	free(b);
	*/

	/*
	// ======================================
	// test for SelectionSortInArray(int *array, int num) | A preferable one for me
	// ======================================

	int a[5] = { 5, 2, 6, 3, 8 };

	std::cout << "Original List:" << std::endl;
	for (int i = 0; i != 5; ++i)
	std::cout << a[i] << "\t";

	SelectionSort(a, 5);

	std::cout << std::endl << "Sorted List:" << std::endl;
	for (int i = 0; i != 5; ++i)
	std::cout << a[i] << "\t";
	std::cout << std::endl;
	*/

	return;
}

int GrokkingAlgorithm::Recursion_Ch3(int val)
{
	/* Recursion -- implementation of Fibonacci numbers
	*
	*  Params:
	*		- val, input nonnegetive number to generate Fibonacci number
	*
	*  Out
	*		return the computation result.
	*
	*  Note:
	*		- "Loops may achieve a performance gain for your program. Recursion may achieve a performance gain for your programmer."
	*
	*		- For Fibonacci numbers, dynamic programming (DP) is a considerable approach. This is just a demo for recursion.
	*/

	if (val <= 0)
		return 0;
	else if (val == 1)
		return 1;
	else
		return (Recursion_Ch3(val - 1) + Recursion_Ch3(val - 2));
}

int GrokkingAlgorithm::MaxSquare_Ch4(int w, int h)
{
	/*
	* ========== Max Square ==============
	*
	* solution to max square given arbitary rectangle with w width and h height.
	*
	* Params:
	*
	*		- w, width of your rectangle
	*		- h, height of youre rectangle
	*
	* Out
	*
	*		return the side length of max square
	*
	*/

	if (!((w > 0) && (h > 0)))
		return -1;

	int minL(h), maxL(w);

	if (h > w)
	{
		minL = w; maxL = h;
	}

	int res = maxL % minL;
	if (res)
		return MaxSquare_Ch4(minL, res);
	else
		return minL;
}

int GrokkingAlgorithm::Sum_Ch4(int *array, int num)
{
	/*
	* ========== Sum =====================
	*
	* solution to sum an array with D&C (divide and conquer)
	*
	* Params:
	*		- array, input integer array
	*		- num, length of array
	*
	* Out
	*		return the sum
	*
	* Note:
	*		- This is implemented with 'a[0] + sum{a[1], a[2], ...}' ---- (sum one and the others)
	*		- Another approach is with 'sum{a[0] + ... + a[m/2]} + sum{a[m/2+1], ..., a[m]}' ---- (sum one half and the other part, which is similar to Binary Search)
	*
	*		- 'Find max value of an array' is with the same idea. No coding more.
	*/

	if (num == 0)
		return 0;
	if (num == 1)
		return array[0];

	return array[0] + Sum_Ch4(&array[1], num - 1);
}

void GrokkingAlgorithm::QuickSort_Ch4(int *array, int num)
{
	/*
	* ========== Quick Sort ==============
	*
	* solution to merge sort of an integer array (ascending)
	*
	* Params:
	*		- array, intpu unordered array
	*		- num, length of array
	*
	* Out
	*		sorted ordered array
	*
	* Note
	*		- The first number of an array is selected for base value
	*		- For better illustration, a new array is created, thus inrcreasing the cost.
	*		- A more efficient version (no-creating new array) is on the below.
	*/


	/* base line */
	if (num < 2)
		return;

	int temp;
	if (num == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}
		return;
	}

	/* D & C */
	int baseVal = array[0];


	// ========= create a new array for better understanding ============== 
	int *newArray = (int *)malloc(num * sizeof(int));

	int i = 0, j = num - 1;
	for (int k = 1; k != num; ++k)
	{
		if (baseVal < array[k])
			newArray[j--] = array[k];
		else
			newArray[i++] = array[k];
	}
	newArray[i] = baseVal;


	QuickSort_Ch4(newArray, i);
	QuickSort_Ch4(&newArray[i + 1], num - i - 1);

	memcpy(array, newArray, num * sizeof(int));
	free(newArray);


	/*
	// ========= a no-creating version ====================================
	int head = 1, tail = num - 1;
	while (head <= tail)
	{
	while ((array[tail] > baseVal) && (head <= tail)) --tail;
	if (head >= tail)
	break;

	while ((array[head] < baseVal) && (head <= tail)) ++head;
	if (head <= tail)
	{
	temp = array[tail];
	array[tail] = array[head];
	array[head] = temp;
	++head; --tail;
	}
	}

	array[0] = array[tail];
	array[tail] = baseVal;

	Ch4_QuickSort(array, tail);
	Ch4_QuickSort(&array[tail + 1], num - tail - 1);
	*/

	return;
}

void Merge(int *array, int num, int pos)
{
	/*
	* function for Merge Sort
	*
	* merge two arrays | [0, pos) & [pos, num)
	*/

	int *newArray = (int *)malloc(num * sizeof(int));

	int i = 0, j = pos, k = 0;

	while ((i != pos) && (j != num))
	{
		if (array[i] < array[j])
			newArray[k++] = array[i++];
		else
			newArray[k++] = array[j++];
	}

	while (i != pos)
		newArray[k++] = array[i++];
	while (j != num)
		newArray[k++] = array[j++];

	memcpy(array, newArray, num * sizeof(int));
	free(newArray);
	return;
}

void GrokkingAlgorithm::MergeSort_Ch4(int *array, int num)
{
	/*
	* ========== Merge Sort ==============
	*
	* solution to merge sort of an integer array (ascending)
	*
	* Params:
	*		- array, intpu unordered array
	*		- num, length of array
	*
	*/

	if (num < 2)
		return;

	int temp;
	if (num == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}
		return;
	}

	int pos = num / 2;
	MergeSort_Ch4(array, pos);
	MergeSort_Ch4(&array[pos], num - pos);
	Merge(array, num, pos);

	return;
}

void GrokkingAlgorithm::HashTable_Ch5(std::map<std::string, int> &mapping)
{
	/*
	* ========== Hash Table ==============
	*
	* solution to hash table for quick search and insertion
	*
	* Params:
	*		- mapping, a map containing name (string) and age(int)
	*
	*/
	std::string input;
	int age;
	char flag;
	std::map < std::string, int>::iterator iter;

	while (true)
	{
		std::cout << "Input Name to Search: ('q' to quit)" << std::endl;
		std::cin >> input;

		if (input == "q")
			break;

		iter = mapping.find(input);

		if (iter == mapping.end())
		{
			std::cout << "No such name. \n Will you add this one? (Y/N)" << std::endl;
			std::cin >> flag;
			if (flag == 'Y')
			{
				std::cout << "Please input the age:" << std::endl;
				std::cin >> age;

				mapping.insert(std::pair<std::string, int>(input, age));
				std::cout << "Done!" << std::endl;
			}
			std::cout << std::endl;
			continue;
		}
		else
			std::cout << "Age: " << iter->second << std::endl << std::endl;
	}

	return;
}

std::pair<bool, std::string> GrokkingAlgorithm::BreadthFirstSearch_Ch6(std::map<std::string, std::vector<std::string>> &relationNet, std::set<std::string> &seller)
{
	/*
	* ========== Breadth First Search (BFS) ==============
	*
	* solution to search a specific one in your relation network with BFS
	*
	* Params:
	*		- relationNet, a map representing your personal relation network
	*		- seller, a set containing suitable person name to search
	*
	* Out:
	*		a pair of bool value representing FOUND or NOT, and a string for the person's name if FOUND
	*/


	/* creat a counter */
	std::map < std::string, int> counter;

	std::queue<std::string> search_queue;
	std::vector<std::string>::iterator iter;

	/* add your first layer relationship*/
	for (iter = relationNet["you"].begin(); iter != relationNet["you"].end(); ++iter)
	{
		search_queue.push(*iter);
	}

	/* search */
	bool flag = false;
	std::string person;
	++counter["your"];
	while (!search_queue.empty())
	{
		/* get the first one */
		person = search_queue.front();
		search_queue.pop();

		/* check if trapped in loop */
		if (counter[person])
			continue;

		/* found or not */
		if (seller.find(person) != seller.end())
		{
			flag = true;
			break;
		}
		else
		{
			++counter[person];
			for (iter = relationNet[person].begin(); iter != relationNet[person].end(); ++iter)
				search_queue.push(*iter);
		}
	}

	return std::pair < bool, std::string > {flag, person};
}

std::map<std::string, int>::iterator find_lowest_cose_node(std::map < std::string, int> &cost, std::map<std::string, int> &counter)
{
	std::map<std::string, int>::iterator iter = cost.begin(), ret = cost.end();
	int minCost = INT_MAX;

	while (iter != cost.end())
	{
		if (iter->second <= minCost  && counter[iter->first] == 0)
		{
			ret = iter;
			minCost = iter->second;
		}
		++iter;
	}

	return ret;
}

std::pair<std::vector<std::string>, int> GrokkingAlgorithm::Dijkstra_Ch7(std::map<std::string, std::map<std::string, int>> &graph)
{
	/*
	* ========== Dijkstra Algorithm ==============
	*
	* solution to Dijkstra algorithm for the shortest route between two position.
	*
	* Params:
	* 		- graph, a graph contains nodes and neighbors as well as weights
	*
	* Out:
	* 		return a pair, the first points to the route and second points to the cost.
	*
	* Note:
	* 		- Dijkstra can only handle directed acyclic graph (DAG) with non-negative side.
	*/

	/* cost map to update routine */
	std::map<std::string, int> cost;

	/* parent map to store parent node */
	std::map<std::string, std::string> parent;

	/* counter map to record processed node */
	std::map<std::string, int> counter;

	/* result */
	std::pair<std::vector<std::string>, int> ret;

	if (graph.empty())
		return ret;

	std::map<std::string, int > neighbor;
	std::map<std::string, int>::iterator iter_neighbor;

	/* initialize */
	cost["start"] = 0;

	std::map<std::string, int>::iterator iter_minCost;
	iter_minCost = find_lowest_cose_node(cost, counter);

	int costVal, prevCost;
	while (iter_minCost != cost.end())
	{
		neighbor = graph[iter_minCost->first];
		prevCost = iter_minCost->second;

		for (iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
		{
			costVal = prevCost + iter_neighbor->second;

			/* update if have none || optimal route found */
			if (cost.find(iter_neighbor->first) == cost.end() || costVal < cost[iter_neighbor->first])
			{
				cost[iter_neighbor->first] = costVal;
				parent[iter_neighbor->first] = iter_minCost->first;
			}
		}

		++counter[iter_minCost->first];

		iter_minCost = find_lowest_cose_node(cost, counter);
	}

	/* return result */
	ret.second = cost["fin"];
	ret.first.push_back("fin");
	while (ret.first.back() != "start")
		ret.first.push_back(parent[ret.first.back()]);

	return ret;
}

std::set<std::string> GrokkingAlgorithm::GreedyAlgorithm_Ch8(std::set<std::string> &states_needed, std::map<std::string, std::set<std::string>> &stations)
{
	/*
	* ========== Greedy Algorithm ==============
	*
	* to find a local optimal solution with Greedy Algorithm
	*
	* Params:
	*		- states_needed, a set containing states needed to cover
	*		- stations, a map containing the states each station covers
	*
	* Out:
	*		a set of stations satisfactory the request, empty if no solution
	*/

	std::set<std::string> final_stations;
	std::set<std::string> states_covered, inter_covered;
	std::string best_station;

	std::map<std::string, std::set<std::string>>::iterator iter;
	std::set<std::string>::iterator iter_covered;

	int counter = 0;
	const int MAX_ITERATIONS = 10000;
	while (!states_needed.empty())
	{
		states_covered.clear();

		/* search for local optimal solution */
		for (iter = stations.begin(); iter != stations.end(); ++iter)
		{
			inter_covered.clear();
			std::set_intersection(states_needed.begin(), states_needed.end(), iter->second.begin(), iter->second.end(), std::inserter(inter_covered, inter_covered.begin()));

			if (inter_covered.size() > states_covered.size())
			{
				best_station = iter->first;
				states_covered = inter_covered;
			}
		}

		/* store */
		final_stations.insert(best_station);

		/* remove */
		stations.erase(best_station);
		for (iter_covered = states_covered.begin(); iter_covered != states_covered.end(); ++iter_covered)
		{
			states_needed.erase(*iter_covered); // Even if no this value. It doesn't matter
		}

		++counter;

		if (counter > MAX_ITERATIONS)
			break;
	}

	std::set<std::string> ret;

	if (counter <= MAX_ITERATIONS)
		ret = final_stations;

	return ret;
}