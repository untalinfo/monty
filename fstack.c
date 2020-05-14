#include "monty.h"
/**
 * op_push - pushes an element to the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	if (*stack == NULL)
		new_node->next = NULL;
	else
		new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/**
 * op_pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to linked list = stack
 * @line_number: Line number of the instruction
 * Return: None
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *ptr;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
