#include "monty.h"

/**
 * f_pop - reomves the top element of the stack
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Return: No return value.
 */
void f_pop(stack_t **head, unsigned int counter)
{
stack_t *h;

/* Check is the stack is empty */
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* emove the top element from the stack */
h = *head;
*head = h->next;

/* Free the mmemory of the removed top node */
free(h);
}
