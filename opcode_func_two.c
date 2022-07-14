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
