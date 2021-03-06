#include "monty.h"

/**
 * parse_line - parses a line of the token
 * @line: jkhkjws
 * Return: token or Null if failed
 */
char **parse_line(char *line)
{
	char *token, **tokens;
	unsigned int i;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " '\n'\t");
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	i = 0;
	while (token != NULL && i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, " '\n'\t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

int arg = 0;
/**
 * get_function - check for operation code
 * @tokens: array of strings
 * @ln: line number in monty code file
 * Return: function or NULL
 */
void(*get_function(char **tokens, unsigned int ln))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul}, {"pstr", op_pstr},
		{"mod", op_mod}, {"pchar", op_pchar},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (tokens[0][0] == '#')
	{
		free(tokens);
		return (op_nop);
	}
	while (ops[i].opcode != NULL)
	{
		if ((strcmp(ops[i].opcode, tokens[0]) == 0))
		{
			if ((strcmp(ops[i].opcode, "push") == 0) &&
				(tokens[1] == NULL || (!(valid_arg(tokens[1])))))
			{
				free(tokens);
				error_func("usage: push integer", ln);
			}
			else if ((strcmp(ops[i].opcode, "push") == 0))
				arg = atoi(tokens[1]);
			free(tokens);
			return (ops[i].f);
		} i++;
	}
	fprintf(stderr, "L%d: unknow instruction %s\n", ln, tokens[0]);
	free(tokens);
	exit(EXIT_FAILURE);
}

/**
 * valid_arg - check if the token is valid
 * @token: argument token from valid_op.
 * Return: 1 if valid argument, 0 if not
 */
int valid_arg(char *token)
{
	unsigned int i;

	if (token == NULL)
		return (1);
	i = 0;
	while (token[i] != '\0')
	{
		if (token[0] == '-')
		{
			if ((!(token[1] >= '0' && token[1] <= '9')) || token[1] == '\0')
				return (0);
			i = 1;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
		else
		{
			i = 0;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}
