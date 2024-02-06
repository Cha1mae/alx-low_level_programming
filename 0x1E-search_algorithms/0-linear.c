#include "search_algos.h"
/**
 * linear_search - using the LSA it searches for
 * value in an array of ints
 *
 * @array: pointer to the first elmnt of the array to search
 * @size: number of elmnt in array
 * @value: value searching for
 * Return: the first index where value is located, otherwise -1
 */
int linear_search(int *array, size_t size, int value)
{
	int chae;

	if (array == NULL)
		return (-1);

	for (chae = 0; chae < (int)size; chae++)
	{
		printf("Value checked array[%u] = [%d]\n", chae, array[chae]);
		if (value == array[chae])
			return (chae);
	}
	return (-1);
}
