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

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number.
 *
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		error_pchar2(line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		err_pr1(line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number.
 *
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	(void)line_number;

	while (traverse && traverse->n > 0 && traverse->n < 127)
	{
		printf("%c", traverse->n);
		traverse = traverse->next;
	}
	putchar('\n');
}

/**
 * rotl -  Rotates the stack to the top.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number.
 *
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	add_dnodeint_end(stack, temp->n);
	free(temp);
}

/**
 * rotr -  Rotates the stack to the bottom.
 *
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: The line number.
 *
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = get_dnodeint_at_index(*stack,  dlistint_len(*stack) - 1);
	add_dnodeint(stack, temp->n);
	delete_dnodeint_at_index(stack, dlistint_len(*stack) - 1);
}
