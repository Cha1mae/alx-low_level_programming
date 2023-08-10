#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memo block using malloc and free
 * @ptr: pointer to the memo previously allocated by malloc
 * @old_size: size of the allocated memo for ptr
 * @new_size: new size of the new memo block
 *
 * Return: pointer to the newly allocated memo block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	unsigned int copy_size = old_size < new_size ? old_size : new_size;

	for (unsigned int i = 0; i < copy_size; i++)
		*((char *)new_ptr + i) = *((char *)ptr + i);


	free(ptr);

	return (new_ptr);
}
