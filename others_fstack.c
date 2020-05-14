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
