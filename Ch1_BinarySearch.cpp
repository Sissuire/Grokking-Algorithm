#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	int InBinarySearch(const int *array, int pos1, int pos2, int val)
	{
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

	int Ch1_BinarySearch(const int *ascend_array, int num, int val)
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
		// return InBinarySearch(ascend_array, 0, num - 1, val);

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
}
