#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line number where the operation is called
 * Return: no return
 */

void f_add(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, aux;

h = *head;

/* Count the number of elements in the stack */
while (h)
{
h = h->next;
len++;
}

/* Check if there at least two elements in the stack*/
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->n + h->next->n;

/* Update the two elements with the sum of the top two elements*/
h->next->n = aux;

/* Remove the top element from the stack */
*head = h->next;

/* Free the memory of the removed top element */
free(h);
}
