#include "monty.h"

int value;

/**
 * _push - Pushes an item onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the push operation is performed
 *
 * This function creates a new stack element with the given value and adds
 * it to the top of the stack.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = value;

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - Prints all the elements in the stack
 * @stack: Pointer to the top of the stack
 * @n: Number of the line where the pall operation is performed
 *
 * This function traverses the stack and prints the value of each element
 * from the top to the bottom.
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
