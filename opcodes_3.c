#include "monty.h"
/**
 *mod - computes the remainder of the division of the second topmost
 *element by the topmost element
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void mod(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;
	int mod_n;

	if (tmp == NULL || tmp->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	mod_n = tmp->prev->n % tmp->n;
	tmp->prev->n = mod_n;
	tmp->prev->next = NULL;
	free(tmp);
}
/**
 *pchar - prints the char at the top followed by a newline
 *Description:top value is treated as ASCII of the top char
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void pchar(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->n < 0 || tmp->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", ln);
		freer();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
/**
 *pstr - prints ascii of stack elements from top
 *@stack:pointer to stack
 *@ln:line number
 * Return:void
 */
void pstr(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	(void)ln;
	if (tmp == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->prev;
	}
	printf("\n");
}
