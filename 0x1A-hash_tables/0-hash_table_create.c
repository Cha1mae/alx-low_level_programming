#include "hash_tables.h"

/**
 * hash_table_create - Function to create a hash table.
 * @size: The size of the hash table.
 *
 * Return: The created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int ary;
	hash_table_t *hasht_able;

	if (size == 0)
		return (NULL);
	hasht_able = malloc(sizeof(hash_table_t));
	if (hasht_able == NULL)
		return (NULL);
	hasht_able->size = size;
	hasht_able->array = malloc(sizeof(hash_node_t *) * size);
	if (hasht_able->array == NULL)
		return (NULL);

	for (ary = 0; ary < size; ary++)
	{
		hasht_able->array[ary] = NULL;
	}
	return (hasht_able);
}
