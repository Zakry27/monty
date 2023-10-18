#include "monty.h"

/**
 * open_file - to open file
 * @file_name: file namepath
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fl = fopen(file_name, "r");

	if (file_name == NULL || fl == NULL)
		err(2, file_name);

	read_file(fl);
	fclose(fl);
}


/**
 * read_file - reads the file
 * @fl: points to the file descriptor
 *
 * Return: void
 */

void read_file(FILE *fl)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fl) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Separate each lines into tokens to
 * determine which function to call
 * @buffer: line from file
 * @line_number: the line number
 * @format:  storage format, nodes will be entered if 0 as stack
 * and nodes will be entered as a queue if 1
 *
 * Return: opcode is stack if 0 and queue if 1
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, line_number, format);
	return (format);
}

/**
 * find_func - finds appropriate func for opcode
 * @opcode: the opcode
 * @val: the argument of opcode
 * @format:  storage format, nodes will be entered as a stack if 0
 * @ln: the line number
 *
 * nodes will be entered as queue if 1
 * Return: void
 */
void find_func(char *opcode, char *val, int ln, int format)
{
	int z;
	int flags;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flags = 1, z = 0; func_list[z].opcode != NULL; z++)
	{
		if (strcmp(opcode, func_list[z].opcode) == 0)
		{
			call_fun(func_list[z].f, opcode, val, ln, format);
			flags = 0;
		}
	}
	if (flags == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls required function
 * @func: Points to the func that is about to be called
 * @op: the string representing the opcode
 * @val: the string representing a num val
 * @ln: the line number for the instruction
 * @format: Format specifier, nodes will be entered as a stack if 0
 * nodes will be entered as a queue if 1.
 *
 * Return: void
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flags;
	int z;

	flags = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flags = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (z = 0; val[z] != '\0'; z++)
		{
			if (isdigit(val[z]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flags);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
