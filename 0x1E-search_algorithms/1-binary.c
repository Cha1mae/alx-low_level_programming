#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted arr
 *                 using binary search
 * @array: Pointer to the first elmnt of the arr to search
 * @size: Number of elmnts in the arr
 * @value: Value to search for
 *
 * Return: If value is not present or array is NULL, -1.
 *         Otherwise, the index where the value is located
 *
 * Description: Prints the subarray being searched after each change
 */
int binary_search(int *array, size_t size, int value)
{
	size_t chae, L, R;

	if (array == NULL)
		return (-1);

	for (L = 0, R = size - 1; R >= L;)
	{
		printf("Searching in array: ");
		for (chae = L; chae < R; chae++)
			printf("%d, ", array[chae]);
		printf("%d\n", array[chae]);

		chae = L + (R - L) / 2;
		if (array[chae] == value)
			return (chae);
		if (array[chae] > value)
			R = chae - 1;
		else
			L = chae + 1;
	}

	return (-1);
}
