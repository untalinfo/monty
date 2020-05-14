#include "monty.h"

/**
 * main - main program of interpreter for Monty ByteCodes files.
 * @argc: number of arguments
 * @argv: arguments of matrix
 * Return: EXIT SUCCESS
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1]);
	return (EXIT_SUCCESS);
}
/**
 * read_file - function that interprets the file
 * @file_name: name of file
 * Return: None
 */
void read_file(char *file_name)
{
	stack_t *stack = NULL;
	int line_num = 0;
	char **token, *buffer = NULL;
	size_t size = 0;
	FILE *file;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, file) != -1)
	{
		line_num++;
		token = parse_line(buffer);
		if (token == NULL)
			continue;
		else
			get_function(token, line_num)(&stack, line_num);
	}
    fclose(file);
	free(buffer);
	free_list(&stack);
}
