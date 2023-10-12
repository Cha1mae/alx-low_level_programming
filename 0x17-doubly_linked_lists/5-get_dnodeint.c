#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node
 * @head: A pointer to the head
 * @index: The index of the node to retrieve (starting from 0).
 * Return: The node at the specified index, or NULL if it doesn't exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}
