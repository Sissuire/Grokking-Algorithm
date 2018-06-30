#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	int Ch4_MaxSquare(int w, int h)
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
			return Ch4_MaxSquare(minL, res);
		else
			return minL;

	}

	int Ch4_Sum(int *array, int num)
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

		return array[0] + Ch4_Sum(&array[1], num - 1);
	}

	void Ch4_QuickSort(int *array, int num)
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


		Ch4_QuickSort(newArray, i);
		Ch4_QuickSort(&newArray[i + 1], num - i - 1);

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

	void Ch4_MergeSort(int *array, int num)
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
		* Out
		*		sorted ordered array
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
		Ch4_MergeSort(array, pos);
		Ch4_MergeSort(&array[pos], num - pos);
		Merge(array, num, pos);

		return;
	}
}