#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - Iterate through an array and performs action on each elemnt
 * @array: The array to iterate through
 * @size: The number of elements in the array.
 * @action: Pointer to the function that performs an action on an element.
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
