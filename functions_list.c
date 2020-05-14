#include "monty.h"
/**
 * free_list - free list
 * @stack: double pointer to head list
 * Return: None
 */
void free_list(stack_t **stack)
{
    stack_t *tmp;

    if (*stack == NULL)
        return;
    while (*stack != NULL)
    {
        tmp = (*stack)->next;
        free(*stack);
        if (tmp == NULL)
            return;
        tmp->prev = NULL;
        *stack = tmp;
    }
    free(*stack);
}