#include "monty.h"
/**
 *add_dnodeint_end - adds a node at the end of a doubly linked list
 *@head:pointer to list
 *@n:integer data
 *Return:address of new node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	temp = *head;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		new_node->prev = temp;
		temp->next = new_node;
	}
	return (new_node);
}
/**
 *add_node_beg - adds a node at the beginning of a doubly linked list
 *@head:pointer to list
 *@n:integer data
 *Return:address of new node
 */
stack_t  *add_node_beg(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (*head);
	}
	else
	{
		while ((*head)->prev != NULL)
			*head = (*head)->prev;
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (new_node);
}
/**
 *free_dlistint - frees a doubly linked list
 *@head:doubly linked list
 *Return:void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head->prev)
	{
		head = head->prev;
	}
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	free(temp);
}
/**
 *is_no - checks whether  a certain char is a no.
 *@c:char to check
 *Return:1 - true, 0 otherwise
 */
int is_no(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
