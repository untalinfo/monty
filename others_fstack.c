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
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (!(isascii((*stack)->n)))
	{
		printf("L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
