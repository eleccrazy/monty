#include "monty.h"
/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 *
 * @stack: A pointer to a pointer to the beginning of the stack
 * @line_number: The line number.
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	stack_t *temp = *stack;
	int leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_mod1(line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		error_div2(line_number);
		exit(EXIT_FAILURE);
	}
	rem = (temp->next->n) % (temp->n);
	temp->next->n = rem;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
