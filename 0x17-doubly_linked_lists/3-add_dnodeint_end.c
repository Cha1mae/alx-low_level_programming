#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end.
 * @head: A pointer to a pointer to the head
 * @n: The integer value to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *fresh_node;
	dlistint_t *temp;

	fresh_node = malloc(sizeof(dlistint_t));
	if (fresh_node == NULL)
		return (NULL);

	fresh_node->n = n;
	fresh_node->next = NULL;

	if (*head == NULL)
	{
		fresh_node->prev = NULL;
		*head = fresh_node;
		return (fresh_node);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = fresh_node;
	fresh_node->prev = temp;

	return (fresh_node);
}
