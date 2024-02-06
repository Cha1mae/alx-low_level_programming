#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in an arr of
 * ints using the ISA
 *
 * @array: Pointer to the first elmnt of the arr to search
 * @size: Size of the arr
 * @value: Value to search for
 *
 * Return: Index of the value, or -1 if not found
 *
 * Description: Interpolation search algorithm implementation (ISA)
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t P, L, H;
	double chae;

	if (array == NULL)
		return (-1);

	L = 0;
	H = size - 1;

	while (size)
	{
		chae = (double)(H - L) / (array[H] - array[L]) * (value - array[L]);
		P = (size_t)(L + chae);
		printf("Value checked array[%lu]", P);

		if (P >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[P]);
		}

		if (array[P] == value)
			return ((int)P);

		if (array[P] < value)
			L = P + 1;
		else
			H = P - 1;

		if (L == H)
			break;
	}

	return (-1);
}
