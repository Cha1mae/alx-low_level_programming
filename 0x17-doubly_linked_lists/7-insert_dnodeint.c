#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node
 * @h: Pointer to the head
 * @idx: Position where node should be
 * @n: The value for the new node.
 * Return: The address of the new node, or NULL if it failed.
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *up_node = *h, *new_node;
	unsigned int index, x = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		new_node->prev = NULL;
		new_node->next = *h;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (*h);
	}

	index = idx - 1;
	while (up_node && x != index)
	{
		x++;
		up_node = up_node->next;
	}

	if (x == index && up_node)
	{
		new_node->prev = up_node;
		new_node->next = up_node->next;
		if (up_node->next)
			up_node->next->prev = new_node;
		up_node->next = new_node;
		return (new_node);
	}
	free(new_node);
	return (NULL);
}
