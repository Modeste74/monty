#include "monty.h"

/**
 * push - used to add an element in to the stack
 * @stack: pointer to the pointer of the head
 * @m: value of the element
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *value_str = strtok(NULL, " \n\t\r");
	stack_t *new;

	if (value_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isdigit(value_str[0]) && value_str[0] != '-' && value_str[0] != '+')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(value_str);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * pall - prints the values on the stack from top to bottom
 * @stack: pointer to the pointer of the head
 * @line_number: no fo line
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - print value of the top stack
 * @stack: pointer to the pointer to the head
 * @line_number: no fo the line
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - remove the top element in a stack
 * @stack: pointer to the pointer of the top stack
 * @line_number: no of the line
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * free_stack - frees stacks
 * @stack: pointer to top stack
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
