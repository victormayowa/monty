#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int d; /* Variable use to store stack int data */
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

int check(char *fn);
int opc_checker(char *opc, int ln);
void pall(stack_t **st, unsigned int ln);
void pin(stack_t **st, unsigned int ln);
void push(stack_t **st, unsigned int n);
int arg_checker(char *s, unsigned int ln);
char *mal(char *b);
void (*get_opcode(char *))(stack_t **, unsigned int);
void processor(char *fn);
#endif /* #ifndef MONTY_H */
