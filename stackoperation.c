#include "monty.h"

/**
 * mul_nodes - Add top two elements of stack
 * @stack: Points to a pointer to top node of stack
 * @line_number: Int representing the line number of opcode
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sums = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds top two elements of stack
 * @stack: Points to a pointer to top node of stack
 * @line_number: Int representing the line number of opcode
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sums = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
