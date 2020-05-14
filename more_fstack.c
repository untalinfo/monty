#include "monty.h"
/**
 * op_add - adds the top two elements of the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func("can't add, stack too short", line_number);
	ptr = *stack;
	if (ptr->next == NULL)
		error_func("can't add, stack too short", line_number);
	ptr->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_nop - doesn’t do anything.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * op_sub - subtracts the top element of the
 * stack from the second top element of the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func("can't sub, stack too short", line_number);
	ptr = *stack;
	if (ptr->next == NULL)
		error_func("can't sub, stack too short", line_number);
	ptr->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_div - subtracts the top element of the
 * stack from the second top element of the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func("can't div, stack too short", line_number);
	ptr = *stack;
	if (ptr->n == 0)
		error_func("division by zero", line_number);
	ptr->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_mul - subtracts the top element of the
 * stack from the second top element of the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func("can't mul, stack too short", line_number);
	ptr = *stack;

	ptr->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
