#include <stdio.h>
#include <sys/types.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024
#define _GNU_SOURCE
#define STACK 0
#define QUEUE 1

/**
 * execute_opcode - used to execute the selected function
 * @stack: pointer to the pointer to the head
 * @opcode: the selected option
 * @line_number: no of the line
 *
 * Return: nothing
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_mode},
		{"queue", queue_mode},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instructions: %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main - entry point
 * @argc: no of arguments passed
 * @argv: arguments passed
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	size_t line_size = 0;
	ssize_t read_f;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_f = getline(&line, &line_size, file);
	while (read_f != -1)
	{
		line_number++;
		line = strtok(line, "\n\t\r\v\f ");
		execute_opcode(&stack, line, line_number);
	}
	free_stack(stack);
	fclose(file);
	free(line);
	exit(EXIT_SUCCESS);
}
