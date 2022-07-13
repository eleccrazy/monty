#include "monty.h"

/**
 * dlistint_len - Computes the length of a stack_t list.
 *
 * @h: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 *
 */

size_t dlistint_len(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		count += 1;
		h = h->next;
	}

	return (count);
}

/**
 * add_dnodeint - Adds a new element at the begining of the list
 *
 * @head: A pointer that points to another pointer which inturn
 * points to the head of the list.
 *
 * @n: The element to be added
 *
 * Return: The address of the new element, or NULL if it failed
 *
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		error_malloc();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;

	return (*head);
}

/**
 * add_dnodeint_end - Adds a new element at the end of the list
 *
 * @head: A pointer that points to a pointer which inturn points to
 * the head of the list.
 * @n: The element to be added
 *
 * Return: The address of the new element, or NULL if it failed
 *
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		error_malloc();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!(*head))
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}

/**
 * get_dnodeint_at_index - Finds the nth node of a stack_t linked list.
 *
 * @head: A pointer to the head of the list.
 * @index: The index at which the element to be found
 *
 * Return: If the node does not exist it returns NULL, otherwise it
 * Returns the nth node of a dlistint_t linked list.
 *
 */

stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (i < index)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
		i++;
	}

	return (head);
}

/**
 * insert_dnodeint_at_index - Inserts a new node at the index.
 *
 * @h: A pointer to a pointer which inturn points to the head of the list
 * @idx: The index of the list where the new node should be added.
 * @n: The element to be added.
 *
 * Return: Null, if it fails to create a memory or if it is not possible to add
 * a new node at idx, otherwise it returns the address of the new node.
 *
 */

stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *traverse, *new_node;

	if (idx == 0)
		return (add_dnodeint(h, n));
	traverse = *h;

	for (; idx != 1; idx--)
	{
		traverse = traverse->next;
		if (traverse == NULL)
			return (NULL);
	}
	if (traverse->next == NULL)
		return (add_dnodeint_end(h, n));
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		error_malloc();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = traverse;
	new_node->next = traverse->next;
	traverse->next->prev = new_node;
	traverse->next = new_node;
	return (new_node);

}
