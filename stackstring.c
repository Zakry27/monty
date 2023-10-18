#include "monty.h"

/**
 * print_char - Print Ascii val
 * @stack: Points to a pointer to top node of stack
 * @line_number: Int representing the line number of opcode
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		string_err(10, line_number);
	printf("%c\n", asci);
}

/**
 * print_str - Print string
 * @stack: Points to a pointer to top node of stack
 * @ln: Int representing the line number of opcode
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asci;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		asci = tmp->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotate first node of stack to bottom
 * @stack: Points to a pointer to top node of stack
 * @ln: Int representing the line number of opcode
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotate last node of stack to top
 * @stack: Points to a pointer to top node of stack
 * @ln: Int representing the line number of opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
