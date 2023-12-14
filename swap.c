#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Return: No return value.
 */

void f_swap(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, aux;

/* Initialize the auxiliary pointer to the head of the stack */
h = *head;

/* Count the number of nodes in the stack */
while (h)
{
h = h->next;
len++;
}

/* Check if there are at least two elements in the stack for swapping*/
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Reset the auxiliary pointer to the head of the stack */
h = *head;

/* Swap the values of the top two elements */
aux = h->n;
h->n = h->next->n;
h->next->n = aux;
}
