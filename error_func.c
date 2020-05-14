#include "monty.h"

/**
 * error_func - prints error message
 * @line_number: line number in monty file
 * @message: error message given
 * Return: None
 */
void error_func(char *message, unsigned int line_number)
{
	if (message == NULL)
		return;
	fprintf(stderr, "L%u: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}
