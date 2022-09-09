#include "monty.h"
/**
 *push - adds values on top of the stack
 *@stack:pointer to the stack doubly linked list
 *@line_number: line number of monty file to parse
 *Return:void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int number, i = 0;
	char *n = mon.args[1];

	if (n == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		freer();
		exit(EXIT_FAILURE);
	}
	/*check if the string contains an integer*/
	while (n[i])
	{
		if ((is_no(n[i]) == 0 && n[i] != '-') || (n[i] == '-' && n[i + 1] == '\0'))
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			freer();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(n);
	mon.args[1] = NULL;
	if (mon.stack_queue == 1)
		add_dnodeint_end(stack, number);
	else
		add_node_beg(stack, number);
}
/**
 *pall - prints all the values of the stack from the top
 *@stack:pointer to the stack
 *@ln:line number
 *Return:void
 */
void pall(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	(void)ln;
	if (tmp == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
}
/**
 *pint - prints the top value of a stack
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void pint(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	printf("%d\n", tmp->n);
}
/**
 *pop - removes the top element of a stack
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->prev)
	{
		tmp->prev->next = NULL;
	}
	free(tmp);
	if (tmp->prev == NULL)
		*stack = NULL;
}
/**
 *swap - swaps the two topmost elements of a stack
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void swap(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;
	int swap_n;

	if (tmp == NULL || tmp->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	swap_n = tmp->prev->n;
	tmp->prev->n = tmp->n;
	tmp->n = swap_n;
}
