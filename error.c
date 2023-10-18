#include "monty.h"

/**
 * err - Print correct error msg determined by error code
 * @error_code: error codes are:
 * (1) => user does'nt give file or more than 1 file to program
 * (2) => file given isn't a file that can be opened or read
 * (3) => file given contains an invalid instruction
 * (4) => When program is unable to malloc more memory
 * (5) => When parameter passed to instruction "push" is not an int
 * (6) => When stack is empty for pint.
 * (7) => When stack is empty for pop.
 * (8) => When stack is too short for operation
 */
void err(int error_code, ...)
{
	va_list ags;
	char *ops;
	int l_nums;

	va_start(ags, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: can't open file %s\n",
				va_arg(ags, char *));
			break;
		case 3:
			l_nums = va_arg(ags, int);
			ops = va_arg(ags, char *);
			fprintf(stderr, "L%d: unknown instruction given %s\n", l_nums, ops);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ags, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles the error
 * @error_code: error codes are:
 * (6) => When stack is empty for pint
 * (7) => When stack is empty for pop
 * (8) => When stack is too short for operation.
 * (9) => Division by zero
 */
void more_err(int error_code, ...)
{
	va_list ags;
	char *ops;
	int l_nums;

	va_start(ags, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, the stack's empty\n",
				va_arg(ags, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop empty stack\n",
				va_arg(ags, int));
			break;
		case 8:
			l_nums = va_arg(ags, unsigned int);
			ops = va_arg(ags, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_nums, ops);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ags, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handle error
 * @error_code: error codes are:
 * (10) ~> number inside a node is outside the ASCII bounds
 * (11) ~> stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ags;
	int l_nums;

	va_start(ags, error_code);
	l_nums = va_arg(ags, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar because value out of range\n", l_nums);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar because stack empty\n", l_nums);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
