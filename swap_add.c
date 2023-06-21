#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number of the instruction
 *
 * Description: This function swaps the positions of the top two elements in
 *              the stack. If the stack contains less than two elements, it
 *              displays an error message and exits.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}

/**
 * _add - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number of the instruction
 *
 * Description: This function adds the top two elements of the stack and
 *              replaces the top element with the sum. If the stack contains
 *              less than two elements, it displays an error message and exits.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		free_all();
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_number);
}

/**
 * _nop - Does nothing
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number of the instruction
 *
 * Description: This function does nothing. It is used as a placeholder
 *              for the "nop" instruction.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
