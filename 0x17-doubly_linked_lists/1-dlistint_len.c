#include "lists.h"

/**
 * dlistint_len - Returns the number of elements
 * @head: A pointer to the head
 * Return: The number of elements
 */
size_t dlistint_len(const dlistint_t *head)
{
	size_t num_l = 0;

	while (head != NULL)
	{
		num_l++;
		head = head->next;
	}

	return (num_l);
}
