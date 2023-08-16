#include "function_pointers.h"
/**
 * int_index - Returns the index of the frst elmnt that matches the comparison,
 * or -1 if no match is found.
 * @array: The array to search
 * @size: The number of elements in the array
 * @cmp: Pointer to the comparison function
 * Return: Index of matching element, or -1 if no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
