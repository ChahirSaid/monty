#include "monty.h"

/**
 * free_all - Frees file and line memory
 *
 * Description: This function frees the dynamically allocated memory
 *              for the file and line variables used in the program.
 *              It closes the file stream and frees the memory for the line buffer.
 */
void free_all()
{
	fclose(gv.file);
	free(gv.line);
}

/**
 * free_stack - Frees a stack
 * @stack: Double pointer to the head of the stack
 *
 * Description: This function frees a stack by traversing through the nodes
 *              using a loop. It starts from the head node and frees each node until the end.
 *              It updates the stack pointer to the next node and frees the current node.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}
