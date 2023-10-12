#include "lists.h"

/**
 * free_dlistint - Frees dlist.
 * @head: A pointer to the head
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *del;

	while (head != NULL)
	{
		del = head;
		head = head->next;
		free(del);
	}
}
