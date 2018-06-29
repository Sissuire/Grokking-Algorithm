#include "GrokkingAlgorithm.h"

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int val = 0;
	while (std::cin >> val)
	{
		std::cout << GrokkingAlgorithm::Ch1_BinarySearch(array, 12, val) << std::endl;
	}
	return 0;
}