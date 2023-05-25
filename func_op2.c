#include "monty.h"

/**
 * swap - swaps 2 elements of the stack
 * @stack: pointer to a pointer to the top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
  int temp = 0;

  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  temp = (*stack)->n;
  (*stack)->n = (*stack)->next->n;
  (*stack)->next->n = temp;
}
/**
 * add - adds the top 2 elements
 * @stack: pointer to a pointer to the top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  (*stack)->next->n += (*stack)->n;
  pop(stack, line_number);
}
/**
 * nop - does nothing
 * @stack: pointer to a pointer to the top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}
/**
 * sub - subtracts the top elements from the one that follows
 * @stack: pointer to a pointer to the top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  (*stack)->next->n -= (*stack)->n;
  pop(stack, line_number);
}
/**
 * div_op - divides the 2 top elements from the top one
 * @stack: pointer to a pointer to the top stack
 * @line_number: no of line
 *
 * Return: nothing
 */
void div_op(stack_t **stack, unsigned int line_number)
{
  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  if ((*stack)->n == 0)
    {
      fprintf(stderr, "L%u: division by zero\n", line_number);
      exit(EXIT_FAILURE);
    }

  (*stack)->next->n /= (*stack)->n;
  pop(stack, line_number);
}
