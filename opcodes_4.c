#include "monty.h"
/**
* rotl - function that rotates a stack by one to the top.
* @stack: first parameter
*@ln: second parameter
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;
	int rotl_n;

	(void)ln;
	if (tmp == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	rotl_n = tmp->n;
	while (tmp->prev != NULL)
	{
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
	tmp->n = rotl_n;
}

/**
  * rotr - opcode that rotates a stack to the bottom
  * @stack: 1st paramenter
  * @ln: 2nd parameter
  *
  * Return: void
  */
void rotr(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;
	int rotr_n;

	(void)ln;
	if (tmp == NULL)
		return;
	rotr_n = tmp->n;
	while (tmp->next != NULL)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = rotr_n;
}
/**
 *stack - changes stack_queue int to 1 so that a stack is implemente
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void stack(stack_t **stack, unsigned int ln)
{
	(void)ln;
	(void)stack;

	mon.stack_queue = 1;
}
/**
 *queue - changes stack_queue int to 0 so that we push to a queue
 *@stack:pointer to stack
 *@ln:line number
 *Return:void
 */
void queue(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;

	mon.stack_queue = 0;
}
