#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

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
/**
 * struct vehicle - args, file, line content
 * @ag: args value
 * @f: pointer to file
 * @c: line values
 * @l: change stack of queue by flag
 */
typedef struct vehicle
{
	char *ag;
	FILE *f;
	char *c;
	int l;
} veh;
extern veh car;
/**
 * functions
 */
void node(stack_t **st, unsigned int ln);
void add(stack_t **st, unsigned int ln);
void queue_top(stack_t **st, unsigned int ln);
void queue(stack_t **st, unsigned int ln);
void _div(stack_t **st, unsigned int ln);
void _mul(stack_t **st, unsigned int ln);
void mod(stack_t **st, unsigned int ln);
void nop(stack_t **st, unsigned int ln);
void pchar(stack_t **st, unsigned int ln);
void pstr(stack_t **st, unsigned int ln);
void swap(stack_t **st, unsigned int ln);
void sub(stack_t **st, unsigned int ln);
void stack(stack_t **st, unsigned int ln);
void rotr(stack_t **st, unsigned int ln);
void rotl(stack_t **st, unsigned int ln);
/**
 * opcode
 */
void redeem(stack_t *st);
void pall(stack_t **st, unsigned int ln);
void pin(stack_t **st, unsigned int ln);
void push(stack_t **st, unsigned int n);
void pop(stack_t **st, unsigned int ln);
int exec(char *val, stack_t **st, unsigned int ln, FILE *fl);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
#endif /* #ifndef  DATA_STRUCTURE_H*/
