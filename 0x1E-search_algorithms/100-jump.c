#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in an arr of
 * ints using the Jump search algorithm
 *
 * @array: Pointer to the first elmnt of the arr to search
 * @size: Size of the arr
 * @value: Value to search for
 *
 * Return: Index of the value, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int chae, L, S, P;

	if (array == NULL || size == 0)
		return (-1);

	S = (int)sqrt((double)size);
	L = 0;
	P = chae = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", chae, array[chae]);

		if (array[chae] == value)
			return (chae);
		L++;
		P = chae;
		chae = L * S;
	} while (chae < (int)size && array[chae] < value);

	printf("Value found between indexes [%d] and [%d]\n", P, chae);

	for (; P <= chae && P < (int)size; P++)
	{
		printf("Value checked array[%d] = [%d]\n", P, array[P]);
		if (array[P] == value)
			return (P);
	}

	return (-1);
}
