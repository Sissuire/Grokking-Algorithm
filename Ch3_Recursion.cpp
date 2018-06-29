#include "GrokkingAlgorithm.h"

namespace GrokkingAlgorithm
{
	int Ch3_Recursion(int val)
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
			return (Ch3_Recursion(val - 1) + Ch3_Recursion(val - 2));
	}
}