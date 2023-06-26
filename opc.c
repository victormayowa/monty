#include "monty.h"

/**
 * push - push func to stack
 * @st: point to linked head
 * @n: line where instruct is found
 * Return: node number in list
 */

void push(stack_t **st, unsigned int n)
{
	int i, k = 0, fl;

	if (car.ag)
	{
		if (car.ag[0] == '-')
		{
			k++;
		}
		for (; car.ag[k] != '\0'; k++)
		{
			if (car.ag[k] > 57 || car.ag[k] < 48)
				fl = 1;
		}
		if (fl == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", n);
			fclose(car.f);
			free(car.c);
			redeem(*st);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	i = atoi(car.ag);
	if (car.l == 0)
		node(st, i);
	else
	{
		queue(st, i);
	}
}

/**
 * pin - print top element
 * @st: list head pointer
 * @ln: line of file
 * Return: number of nodes
 */
void pin(stack_t **st, unsigned int ln)
{
	if (*st == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*st)->n);
}

/**
 * pall -prints all element
 * @st: list head pointer
 * @ln: line of file
 * Return:  nodes number
 */
void pall(stack_t **st, unsigned int ln)
{
	stack_t *p;

	(void)ln;
	p = *st;
	if (p == NULL)
	{
		return;
	}
	for (; p != NULL; p = p->next)
		printf("%d\n", p->n);
}

/**
 * redeem - func that frees stackct
 * @st: stackhead
 * none
 */
void redeem(stack_t *st)
{
	stack_t *a;

	a = st;
	while (st)
	{
		a = st->next;
		free(st);
		st = a;
	}
}

/**
 * pop - pos d top
 * @st: stack head
 * @ln: number of lines
 * Return:  void
*/
void pop(stack_t **st, unsigned int ln)
{
	stack_t *a;

	if (*st == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	a = *st;
	*st = a->next;
	free(a);
}
