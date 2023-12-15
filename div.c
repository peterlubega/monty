#include "monty.h"

/**
 * fn_div - divides the top two elements of the stack.
 * @head: pointer to the head of the stack.
 * @counter: line number where the operation is called.
 * Return: no return.
 */
void fn_div(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, aux;

/* Trverse the stack to count the number of elements */
h = *head;
while (h)
{
h = h->next;
len++;
}

/* Check if there atleast two elements in the stack */
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

h = *head;

/* Check if the divisor(top element) is zero */
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Perform the division and update the stack*/
aux = h->next->n / h->n;
h->next->n = aux;
*head = h->next;

/* Free the memeory of the removed top element*/
free(h);
}
