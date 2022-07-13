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

