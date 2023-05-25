#include "monty.h"

/**
 * mul - multiplies the last and second last.
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
/**
 * mod - computes the division of second top element and top element.
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;

	(void)line_number;
	while (cur != NULL && cur->n != 0 && cur->n >= 0 && cur->n <= 127)
	{
		putchar(cur->n);
		cur = cur->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
