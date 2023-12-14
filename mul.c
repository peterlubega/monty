#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the head pf the stack.
 * @counter: line number where the operation is called
 * Return: No return value
 */
void f_mul(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, aux;

/* Traverse the stack to count the number of elements*/
h = *head;
while (h)
{
h = h->next;
len++;
}

/* Check if there are at least two elements in the stcak */
if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;

/* Perfome the multiplication operation and update the stack */
aux = h->next->n * h->n;
h->next->n = aux;

/* Update the head of the stack to point to the next node */
*head = h->next;

/* Free the memory of the removed top node */
free(h);
}
