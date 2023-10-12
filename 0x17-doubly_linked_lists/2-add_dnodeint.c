#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning
 * @head: A pointer to a pointer to the head.
 * @n: The integer value to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *fresh_node;

	fresh_node = malloc(sizeof(dlistint_t));
	if (fresh_node == NULL)
		return (NULL);

	fresh_node->n = n;
	fresh_node->prev = NULL;
	fresh_node->next = *head;

	if (*head != NULL)
		(*head)->prev = fresh_node;

	*head = fresh_node;
	return (fresh_node);
}
