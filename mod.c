#include "monty.h"

/**
 * fn_mod - computes the reminder of the division of the second
 * top element of the stack by the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line number where the operation is called
 * Return: no return
 */
void fn_mod(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, aux;
/* Traverse the satck to counf the number of elements */
h = *head;
while (h)
{
h = h->next;
len++;
}
/* Check if there are at least two elements in the stack */
if (len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
/* Check if the divisor (top element) is zero */
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
/* Perfome the modulus operation and update the stack */
aux = h->next->n % h->n;
h->next->n = aux;
/* Update the head of the stack to point to the next node */
*head = h->next;
/* Free the mempry of the removed node */
free(h);
}
