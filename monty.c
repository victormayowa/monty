#include "monty.h"
#include <stdio.h>
veh car = {NULL, NULL, NULL, 0};
/**
* main - entry point for monty interpreter
* @argc: args count
* @argv: arg vector for file location
* Return: 0 or 1
*/
int main(int argc, char *argv[])
{
	char *val;
	FILE *f;
	size_t s = 0;
	ssize_t rl = 1;
	stack_t *st = NULL;
	unsigned int ln = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	car.f = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rl > 0)
	{
		val = NULL;
		rl = custom_getline(&val, &s, f);
		car.c = val;
		ln++;
		if (rl > 0)
			exec(val, &st, ln, f);
		free(val);
	}
	redeem(st);
	fclose(f);
	return (0);
}

/**
* exec - execute_opcode
* @st: head ofstack
* @ln: number of lin counter
* @fl: points to  file
* @val: value of line content
* Return: val
*/
int exec(char *val, stack_t **st, unsigned int ln, FILE *fl)
{
	instruction_t op[] = {
				{"push", push}, {"pall", pall}, {"pint", pin},	{"pop", pop},
				{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
				{"div", _div}, {"mul", _mul}, {"mod", mod}, {"pchar", pchar},
				{"pstr", pstr}, {"rotl", rotl},	{"rotr", rotr},
				{"queue", queue}, {"stack", stack},	{NULL, NULL}
				};
	unsigned int l = 0;
	char *opc;

	opc = strtok(val, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	car.ag = strtok(NULL, " \n\t");
	while (op[l].opcode && opc)
	{
		if (strcmp(opc, op[l].opcode) == 0)
		{
			op[l].f(st, ln);
			return (0);
		}
		l++;
	}
	if (opc && op[l].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opc);
		fclose(fl);
		free(val);
		redeem(*st);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * custom_getline - getline replica
 * @lineptr: line pointer
 * @n: number
 * @stream: of char
 * Return: 0 in success
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;  /* Current buffer size */
	size_t pos = 0;      /* Current position within the buffer */
	int c;               /* Current character read */

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		bufsize = 128;
		*lineptr = malloc(bufsize);
		if (*lineptr == NULL)
			return (-1);
		*n = bufsize;
	}
	else
		bufsize = *n;
	while ((c = fgetc(stream)) != EOF)
	{
		(*lineptr)[pos++] = c;
		if (pos >= bufsize - 1)
		{
			bufsize += 128;
			*lineptr = realloc(*lineptr, bufsize);
			if (*lineptr == NULL)
				return (-1);
			*n = bufsize;
		}
		if (c == '\n')
			break;
	}
	(*lineptr)[pos] = '\0';
	return ((ssize_t)pos);
}

