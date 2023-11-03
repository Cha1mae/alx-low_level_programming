#include "hash_tables.h"

/**
 * hash_table_get - gets value with an associated key
 * @ht: hash table
 * @key: kee with value
 *
 * Return: The value assted with elmnt, or NULL kee not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *tmpo;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	tmpo = ht->array[idx];

	while (tmpo != NULL)
	{
		if (strcmp(tmpo->key, key) == 0)
			return (tmpo->value);
		tmpo = tmpo->next;
	}
	return (NULL);
}
