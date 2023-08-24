#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 * Return: the address of the new node, or NULL if fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *added_node;
	unsigned int len = 0;

	while (str[len])
		len++;

	added_node = malloc(sizeof(list_t));
	if (!added_node)
		return (NULL);

	added_node->str = strdup(str);
	added_node->len = len;
	added_node->next = (*head);
	(*head) = added_node;

	return (*head);
}
