#include "hash_tables.h"

/**
 * key_index - Returns the idx at which the key/value pair
 *             shld be stored in the arr of the ht
 * @key: The key to be hashed.
 * @size: The size of the array of the ht
 *
 * Return: The index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value, index;

	hash_value = hash_djb2(key);
	index = hash_value % size;

	return (index);
}
