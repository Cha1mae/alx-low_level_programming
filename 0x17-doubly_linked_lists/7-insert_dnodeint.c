#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node
 * @h: A pointer to a pointer to the head.
 * @idx: The index where the new node should be addd (starting from 0).
 * @n: The integer value to be stored in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *up_node, *temp = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	up_node = malloc(sizeof(dlistint_t));
	if (up_node == NULL)
		return (NULL);

	up_node->n = n;

	if (idx == 0)
	{
		up_node->prev = NULL;
		up_node->next = temp;
		if (temp != NULL)
			temp->prev = up_node;
		*h = up_node;
		return (up_node);
	}

	while (temp != NULL)
	{
		if (i == idx)
		{
			up_node->prev = temp->prev;
			up_node->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = up_node;
			temp->prev = up_node;
			return (up_node);
		}
		temp = temp->next;
		i++;
	}

	free(up_node);
	return (NULL);
}
