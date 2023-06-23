#include "monty.h"

/**
 * main - main function
 * @argc: arg counter
 * @argv: arg vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *fn;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fn = argv[1];
	if (!check(fn))
	{
		fprintf(stderr, "Error: Can't open file %s\n", fn);
		exit(EXIT_FAILURE);
	}
	processor(fn);
	return (0);
}
