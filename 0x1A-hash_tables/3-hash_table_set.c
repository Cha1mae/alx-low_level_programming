#include "hash_tables.h"

/**
 * insert_node_at_index - Inserts a node at a specified index in the hash table
 * @ht: The hash table
 * @cool_node: Node to be inserted
 * @idx: Index to insert the node at
 * @key: Key to be inserted
 *
 * Return: 1 on success, 0 on failure
 */
int insert_node_at_index(hash_table_t *ht, hash_node_t *cool_node,
						 unsigned long int idx, const char *key)
{
	hash_node_t *curr = ht->array[idx];

	if (strcmp(curr->key, key) == 0)
	{
		cool_node->next = curr->next;
		ht->array[idx] = cool_node;
		free_node(curr);
		return (1);
	}

	while (curr->next != NULL && strcmp(curr->next->key, key) != 0)
		curr = curr->next;

	if (strcmp(curr->key, key) == 0)
	{
		cool_node->next = curr->next->next;
		free_node(curr->next);
		curr->next = cool_node;
	}
	else
	{
		cool_node->next = ht->array[idx];
		ht->array[idx] = cool_node;
	}
	return (1);
}

/**
 * hash_table_set - Assigns a value within the hash table
 * @ht: Hash table
 * @key: Indexed key
 * @value: Value to be set for the hash table
 *
 * Return: 1 if successful, 0 if not
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *cool_node;

	if (strcmp(key, "") == 0 || key == NULL || ht == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	cool_node = malloc(sizeof(hash_node_t));

	if (cool_node == NULL)
		return (0);

	cool_node->key = strdup((char *)key);
	cool_node->value = strdup((char *)value);
	cool_node->next = NULL;

	if (ht->array[idx] == NULL)
		ht->array[idx] = cool_node;
	else
	{
		if (!insert_node_at_index(ht, cool_node, idx, key))
			return (0);
	}
	return (1);
}

/**
 * free_node - Frees a node.
 * @node: The node to be freed
 *
 * Return: Void
 */
void free_node(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}
