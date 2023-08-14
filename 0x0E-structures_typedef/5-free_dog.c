#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory occupied by a dog structure
 * @d: Pointer to the dog structure to free
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
