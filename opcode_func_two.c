#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number.
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next = NULL;
	int sum, leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_add(line_number);
		exit(EXIT_FAILURE);
	}

	next = head->next;
	sum = (*stack)->n + (((*stack)->next)->n);
	next->n = sum;
	*stack = next;
	free(head);
}

/**
 * nop - Doesn’t do anything.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number.
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 *
 * @stack: a pointer to a pointer to the beginning of the stack implementation
 * @line_number: The line number
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int diff, leng;
	stack_t *temp = *stack;

	leng = dlistint_len(*stack);
	if (leng < 2)
	{
		error_sub(line_number);
		exit(EXIT_FAILURE);
	}
	diff = (temp->next->n) - (temp->n);
	temp->next->n = diff;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
/**
 * divt - divides the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: a pointer to a pointer to the beginning of the stack implementation
 * @line_number: The line number
 *
 */
void divt(stack_t **stack, unsigned int line_number)
{
	int quotient;
	stack_t *temp = *stack;
	int leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_div1(line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		error_div2(line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (temp->next->n) / (temp->n);
	temp->next->n = quotient;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @stack: a pointer to a pointer to the beginning of the stack implementation
 * @line_number: The line number
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int pro;
	stack_t *temp = *stack;
	int leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_mul(line_number);
		exit(EXIT_FAILURE);
	}
	pro = (temp->n) * (temp->next->n);
	temp->next->n = pro;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
