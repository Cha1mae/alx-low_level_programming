#include "hash_tables.h"

/**
 * hash_table_delete - it deletes ht
 * @ht: hash tab to b del
 *
 * Return: void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *tmpo, *nxt;

	if (ht == NULL)
		return;

	for (idx = 0; idx < ht->size; idx++)
	{
		tmpo = ht->array[idx];
		while (tmpo != NULL)
		{
			nxt = tmpo->next;
			free(tmpo->key);
			free(tmpo->value);
			free(tmpo);
			tmpo = nxt;
		}
	}
	free(ht->array);
	free(ht);
}
