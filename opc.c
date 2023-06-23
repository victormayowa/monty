#include "monty.h"
/**
 * push - push func to stack
 * @st: point to linked head
 * @n: line where instruct is found
 * Return: node number in list
 */
void push(stack_t **st, unsigned int n)
{
	stack_t *t;
	stack_t *node;

	(void)n;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = d;
	node->prev = NULL;
	node->next = NULL;
	if (*st == NULL)
	{
		*st = node;
		return;
	}
	t = *st;
	t->prev = node;
	node->next = t;
	*st =  node;
}

/**
 * pin - print top element
 * @st: list head pointer
 * @ln: line of file
 * Return: number of nodes
 */
void pin(stack_t **st, unsigned int ln)
{
	stack_t *p = NULL;

	(void)ln;
	if (*st  == NULL)
	{
		return;
	}
	p = *st;
	printf("%d\n", p->n);
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
	if (*st == NULL)
	{
		return;
	}
	p = *st;
	for (; p != NULL; p = p->next)
		printf("%d\n", p->n);
}

/**
 * check - func that checksif file extension is correct
 * @fn: filename
 * Return: int
 */
int check(char *fn)
{
	char *e = strrchr(fn, ',');

	if (e == NULL || strcmp(e, ".m") != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fn);
		return (0);
	}
	return (1);
}


/**
 * get_opcode - selects the correct stack func
 * @opc: represents stack op to done
 * Return: funcpointer
 */

void (*get_opcode(char *opc))(stack_t **head, unsigned int line_number)
{
	instruction_t ops[] = {{"push", push}, {"pall", pall},
		{"pint", pin}, {NULL, NULL}};
	int j = 0;

	for (j = 0; j < 3; j++)
	{
		if (strcmp(ops[j].opcode, opc) == 0)
			return (ops[j].f);
	}
	return (NULL);
}
