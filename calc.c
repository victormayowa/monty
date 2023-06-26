#include "monty.h"
/**
  *rotl-stack top rotation
  *@st: head of stack
  *@ln: number of line
  *Return: void
 */
void rotl(stack_t **st, unsigned int ln)
{
	stack_t *temp = *st, *a;

	(void)ln;
	if (*st == NULL || (*st)->next == NULL)
		return;
	a = (*st)->next;
	a->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *st;
	(*st)->next = NULL;
	(*st)->prev = temp;
	(*st) = a;
}


/**
 *rotr- stack rotation to the bottom
 *@st: head of stack
 *@ln: number of line
 *Return: void
 */
void rotr(stack_t **st, unsigned int ln)
{
	stack_t *cp;

	(void)ln;
	cp = *st;
	if (*st == NULL || (*st)->next == NULL)
		return;
	while (cp->next)
		cp = cp->next;
	cp->next = *st;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*st)->prev = cp;
	(*st) = cp;
}

/**
 * stack - print top of stak
 * @st: head of stack
 * @ln: num of line
 * Return: void
 */
void stack(stack_t **st, unsigned int ln)
{
	(void)ln;
	(void)st;
	car.l = 0;
}

/**
 *sub- subtration of top of stack
 *@st: head of stack
 *@ln: counter of line_number
 *Return: void
 */
void sub(stack_t **st, unsigned int ln)
{
	stack_t *a;
	int s, n;

	a = *st;
	for (n = 0; a != NULL; n++)
		a = a->next;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	a = *st;
	s = a->next->n - a->n;
	a->next->n = s;
	*st = a->next;
	free(a);
}

/**
 * swap - adds the_top_2_content_of_stack.
 * @st: head of stack
 * @ln: counter of linenumber
 * Return: void
*/
void swap(stack_t **st, unsigned int ln)
{
	stack_t *a;
	int i = 0, au;

	a = *st;
	for (; a; a = a->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		fclose(car.f);
		free(car.c);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	a = *st;
	au = a->n;
	a->n = a->next->n;
	a->next->n = au;
}
