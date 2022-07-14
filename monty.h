#ifndef MONTY_H
#define MONTY_H

/*
 * File: monty.h
 *
 * Desc: This header file contains all the structure definations, header files,
 * and all the function prototypes used for the 0x19. C - Stacks,
 * Queues - LIFO, FIFO project in the ALX's Software Engineering program.
 *
 * Author: Gizachew Bayness (Elec Crazy) and  Kaleab Girma
 *
 * Date Created: Jul 13 2022
 *
 */

#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define error_ac() fprintf(stderr, "USAGE: monty file\n")
#define error_fopen(name) fprintf(stderr, "Error: Can't open file %s\n", name)
#define error_malloc() fprintf(stderr, "Error: malloc failed\n")
#define error_op(ln, c) fprintf(stderr, "L%u: unknown instruction %s\n", ln, c)
#define error_int(ln) fprintf(stderr, "L%u: usage: push integer\n", ln)
#define error_pint(ln) fprintf(stderr, "L%u: can't pint, stack empty\n", ln)
#define error_pop(ln) fprintf(stderr, "L%u: can't pop an empty stack\n", ln)
#define error_swap(l) fprintf(stderr, "L%u: can't swap, stack too short\n", l)
#define error_add(ln) fprintf(stderr, "L%u: can't add, stack too short\n", ln)
#define error_sub(ln) fprintf(stderr, "L%u: can't sub, stack too short\n", ln)
#define error_div1(ln) fprintf(stderr, "L%u: can't div, stack too short\n", ln)
#define error_div2(ln) fprintf(stderr, "L%u: division by zero\n", ln)
#define error_mul(ln) fprintf(stderr, "L%u: can't mul, stack too short\n", ln)
#define error_mod1(ln) fprintf(stderr, "L%u: can't mod, stack too short\n", ln)
#define err_pr1(l) fprintf(stderr, "L%u: can't pchar, value out of range\n", l)
#define error_pchar2(l) fprintf(stderr, "L%u: can't pchar, stack empty\n", l)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;

} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *h;
extern FILE *file;
extern char *value;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divt(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

size_t dlistint_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

#endif
