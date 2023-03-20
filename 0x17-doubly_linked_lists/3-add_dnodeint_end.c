#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a list
 *
 * @head: head node
 * @n: integer new node
 *
 * Return: address of the new element
 *
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
	return (new_node);
}
