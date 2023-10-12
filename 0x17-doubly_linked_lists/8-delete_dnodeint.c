#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: A pointer to a pointer to the head
 * @index: The index of the node to delete (starting from 0).
 * Return: (1) if it succeeded, (-1) if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *to_bdeleted = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = to_bdeleted->next;
		if (to_bdeleted->next)
			to_bdeleted->next->prev = NULL;
		free(to_bdeleted);
		return (1);
	}

	while (to_bdeleted)
	{
		if (i == index)
		{
			if (to_bdeleted->prev)
				to_bdeleted->prev->next = to_bdeleted->next;
			if (to_bdeleted->next)
				to_bdeleted->next->prev = to_bdeleted->prev;
			free(to_bdeleted);
			return (1);
		}
		to_bdeleted = to_bdeleted->next;
		i++;
	}

	return (-1);
}

