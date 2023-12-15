#include "monty.h"

/**
 * fn_pint - Prints the value at the top of the stack
 * followed by a new line.
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Return: No return value.
 */

void fn_pint(stack_t **head, unsigned int counter)
{

/* Check if the stack is empty*/
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Print the value at the topof the stack*/
printf("%d\n", (*head)->n);
}
