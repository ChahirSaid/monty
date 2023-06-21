#include "monty.h"

/**
 * _pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number of the instruction
 *
 * Description: This function prints the value at the top of the stack.
 *              If the stack is empty, it displays an error message and exits.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number of the instruction
 *
 * Description: This function removes the top element of the stack.
 *              If the stack is empty, it displays an error message and exits.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
