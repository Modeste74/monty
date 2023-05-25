#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
/**
 * stack_mode - sets the format of the data to a stac
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * queue_mode - sets the format of the data to a queue
 * @stack: pointer to the pointer of top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	(*stack)->prev = current;
	current->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
