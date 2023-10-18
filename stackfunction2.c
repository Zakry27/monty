#include "monty.h"

/**
 * nop - it does nothing
 * @stack: it points to a pointer to top node of stack
 * @line_number: Int representing the line num of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - swap top two elements of stack
 * @stack: Points to a pointer to top node of stack
 * @line_number: Int representing the line number of opcode
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Add top two elements of stack
 * @stack: Points to a pointer to top node of stack
 * @line_number: Int representing the line number of opcode
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sums = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds top two elements of stack
 * @stack: Points to a pointer to top node of stack
 * @line_number: Int representing the line number of opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sums = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds top two elements of stack
 * @stack: Points to a pointer to top node of  stack.
 * @line_number: Int representing the line number of opcode
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sums = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
