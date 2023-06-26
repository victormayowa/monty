#include "monty.h"
/**
 * _mul - multiplies the_top_2_elements_on_stack.
 * @st: head fo stack
 * @ln: number of line
 * Return: void
*/
void _mul(stack_t **st, unsigned int ln)
{
	stack_t *a;
	int i = 0, au;

	a = *st;
	for (; a; a = a->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	a = *st;
	au = a->next->n * a->n;
	a->next->n = au;
	*st = a->next;
	free(a);
}

/**
 * mod - division of the second top element of the stack
 * @st: head of stack
 * @ln: number of line
 * Return: void
*/
void mod(stack_t **st, unsigned int ln)
{
	stack_t *a;
	int i = 0, au;

	a = *st;
	for (; a; a = a->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
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
	au = a->next->n % a->n;
	a->next->n = au;
	*st = a->next;
	free(a);
}

/**
  *nop - no node , no stack, no queue
  *@st: head ofstack
  *@ln: number of linne
  *Return: void
 */
void nop(stack_t **st, unsigned int ln)
{
	(void) st;
	(void) ln;
}

/**
 * pchar - print_char onstack_top, followed by a new line
 * @st: head of stack
 * @ln: number of line
 * Return: void
*/
void pchar(stack_t **st, unsigned int ln)
{
	stack_t *a;

	a  = *st;
	if (!a)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	if (a->n > 127 || a->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", a->n);
}

/**
 * pstr - print_string from top_of_stack, followed by new one
 * @st: head of stack
 * @ln: _number of linne
 * Return: void
*/
void pstr(stack_t **st, unsigned int ln)
{
	stack_t *a;
	(void)ln;

	a = *st;
	while (a)
	{
		if (a->n > 127 || a->n <= 0)
			break;
		printf("%c", a->n);
		a = a->next;
	}
	printf("\n");
}
