#include "monty.h"
/**
 * add - add to the top of the stack.
 * @st: head of stack
 * @ln: line_number
 * Return: no return
*/
void add(stack_t **st, unsigned int ln)
{
	stack_t *a;
	int i, aly;

	a = *st;
	for (i = 0; a; a = a->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	a = *st;
	aly = a->n + a->next->n;
	a->next->n = aly;
	*st = a->next;
	free(a);
}

/**
 * node - add node tostack
 * @st: head stack
 * @ln: new line number
 * Return: void
*/
void node(stack_t **st, unsigned int ln)
{

	stack_t *new, *a;

	a = *st;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (a)
		a->prev = new;
	new->n = ln;
	new->next = *st;
	new->prev = NULL;
	*st = new;
}

/**
 * queue_top - print_queue_top
 * @st: head of stack
 * @ln: number of linne
 * Return: void
*/
void queue_top(stack_t **st, unsigned int ln)
{
	(void)ln;
	(void)st;
	car.l = 1;
}

/**
 * queue - add node tostack_tail
 * @ln: number_value
 * @st: stack_head
 * Return: void
*/
void queue(stack_t **st, unsigned int ln)
{
	stack_t *new, *a;

	a = *st;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		printf("Error\n");
	new->n = ln;
	new->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*st = new;
		new->prev = NULL;
	}
	else
	{
		a->next = new;
		new->prev = a;
	}
}

/**
 * _div - division of the top two data of the stack.
 * @st: head of stack
 * @ln: number of line
 * Return: void
*/
void _div(stack_t **st, unsigned int ln)
{
	stack_t *a;
	int i = 0, au;

	a = *st;
	for (; a; a = a->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	a = *st;
	if (a->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	au = a->next->n / a->n;
	a->next->n = au;
	*st = a->next;
	free(a);
}
