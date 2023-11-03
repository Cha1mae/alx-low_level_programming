#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted ht
 * @size: array size
 *
 * Return: pointer to the newly created ht
 */
shash_table_t *shash_table_create(unsigned long int size) 
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));
	if (ht == NULL) return NULL;

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - Adds an elemnt to sorted ht
 * @ht: The sorted ht
 * @key: The key to be added
 * @value: The value to be added
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *cool_node, *tmpo;
	unsigned long int idx;

	if (ht == NULL || key == NULL || value == NULL || strcmp(key, "") == 0)
		return (0);

	idx = key_index((unsigned char *)key, ht->size);
	tmpo = ht->array[idx];

	while (tmpo != NULL)
    {
	    if (strcmp(tmpo->key, key) == 0)
	    {
		    free(tmpo->value);
		    tmpo->value = strdup(value);
		    return (1);
	    }
	    tmpo = tmpo->next;
    }

	cool_node = malloc(sizeof(shash_node_t));
	if (cool_node == NULL) return 0;

	cool_node->key = strdup(key);
	if (cool_node->key == NULL)
	{
		free(cool_node);
		return (0);
	}

	cool_node->value = strdup(value);
	if (cool_node->value == NULL)
	{
		free(cool_node->key);
		free(cool_node);
		return (0);
	}

	cool_node->next = ht->array[idx];
	ht->array[idx] = cool_node;

	if (!ht->shead)
	{
		cool_node->sprev = NULL;
		cool_node->snext = NULL;
		ht->shead = cool_node;
		ht->stail = cool_node;
	} else {
		tmpo = ht->shead;
		while (tmpo)
		{
			if (strcmp(key, tmpo->key) < 0)
			{
				cool_node->sprev = tmpo->sprev;
				cool_node->snext = tmpo;
				if (tmpo->sprev)
					tmpo->sprev->snext = cool_node;
				else
					ht->shead = cool_node;
				tmpo->sprev = cool_node;
				break;
			}
			tmpo = tmpo->snext;
		}
		if (!tmpo)
		{
			cool_node->sprev = ht->stail;
			cool_node->snext = NULL;
			ht->stail->snext = cool_node;
			ht->stail = cool_node;
		}
	}

	return (1);
}

/**
 * shash_table_get - value retrieved by kee
 * @ht: The sorted hash table
 * @key: The key to be searched
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *node;

	if (ht == NULL || key == NULL || strcmp(key, "") == 0)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints ht
 * @ht: sorted ht
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL) 
	{
		if (comma_flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma_flag = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints ht in reverse
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		if (comma_flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma_flag = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
	unsigned long int xy;

	if (ht == NULL)
		return;

	for (xy = 0; xy < ht->size; xy++) 
	{
		node = ht->array[xy];
		while (node != NULL)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	free(ht->array);
	free(ht);
}
