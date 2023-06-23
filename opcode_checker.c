#include "monty.h"

/**
 * processor - bytecode function processor
 * @fn: file
 * Return: void
 *
 */
int d;

void processor(char *fn)
{
	FILE *f;
	char buf[1024], *str, *arg;
	unsigned int ln = 0;
	void (*pointer)(stack_t **head, unsigned int ln);
	stack_t *head;

	f = fopen(fn, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fn);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, sizeof(buf), f))
	{
		ln++;
		buf[strspn(buf, "\n")] = '\0';
		str = strtok(buf, " \t");
		if (str == NULL)
			continue;
		if (!opc_checker(str, ln))
			exit(EXIT_FAILURE);
		if ((strcmp(str, "pall") != 0) && strcmp(str, "pint") != 0)
		{
			arg = strtok(NULL, " \t");
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
			if (!arg_checker(arg, ln))
				exit(EXIT_FAILURE);
			d = atoi(arg);
		}
		pointer = get_opcode(str);
		pointer(&head, ln);
	}
	fclose(f);
}
/**
 * arg_checker - opcode checker
 * @s: points to arg
 * @ln: number of line
 * Return: int
 */

int arg_checker(char *s, unsigned int ln)
{
	for (; *s ; s++)
	{
		if (!isdigit(*s))
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			return (0);
		}
	}
	return (1);
}

/**
 * mal - allocate mem
 * @b: buffer
 * Return: mem pointer
 */

char *mal(char *b)
{
	b = malloc(1024);
	if (b == NULL)
	{
		printf("Error: malloc failed");
		return (NULL);
	}
	return (b);
}

/**
 * opc_checker - validates opcode
 * @opc: instruction
 * @ln: number of line
 * Return: int
 */

int opc_checker(char *opc, int ln)
{
	int count, j;
	char *list[] = {"push", "pall", "pint"};

	count = sizeof(list) / sizeof(list[0]);
	while (j < count)
	{
		if (strcmp(opc, list[j]) == 0)
			return (1);
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opc);
	return (0);
}
