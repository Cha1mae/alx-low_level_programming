#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of the linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *last_node;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	last_node = malloc(sizeof(list_t));
	if (!last_node)
		return (NULL);

	last_node->str = strdup(str);
	last_node->len = len;
	last_node->next = NULL;

	if (*head == NULL)
	{
		*head = last_node;
		return (last_node);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = last_node;

	return (last_node);
}
