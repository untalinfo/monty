#include "monty.h"

/**
 * op_mod - subtracts the top element of the
 * stack from the second top element of the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func("can't mod, stack too short", line_number);
	ptr = *stack;
	if (ptr->n == 0)
		error_func("division by zero", line_number);

	ptr->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if (*stack == NULL || stack == NULL)
		error_func("can't pchar, stack empty", line_number);
	x = (*stack)->n;
	if (x >= 1 && x <= 127)
		printf("%c\n", x);
	else
		error_func("can't pchar, value out of range", line_number);
}

/**
 * op_pstr - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int i = 0;

	(void)line_number;
	if (*stack == NULL || stack == NULL)
		putchar('\n');
	else
	{
		ptr = *stack;
		while (ptr != NULL)
		{
			i = ptr->n;
			if (i >= 1 && i <= 127)
				putchar(i);
			else
				break;
			ptr = ptr->next;
		}
		putchar('\n');
	}
}
