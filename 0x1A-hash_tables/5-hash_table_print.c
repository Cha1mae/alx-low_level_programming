#include "hash_tables.h"

/**
 * hash_table_print - this will print us an ht
 * @ht: The hash table to print.
 *
 * Return: void.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *temp = NULL;
	int indicator = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (idx = 0; idx < ht->size; idx++)
	{
		temp = ht->array[idx];
		while (temp != NULL)
		{
			if (indicator == 1)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			indicator = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
