#include "monty.h"

/**
 * fn_pall - Prints the elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number (not used in this function)
 * Return: No return value.
 */
void fn_pall(stack_t **head, unsigned int counter)
{
stack_t *h;
/* Unised paarameter to prevent compiler warning */
(void)counter;

h = *head;

/* If stack is empty, no need to print anything */
if (h == NULL)
return;

/* Traverse the stack and print each element */
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
