#include "monty.h"

/**
 * fn_sub - Subtracts the top element of the stack from the second top element.
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Return: No return value.
 */
void fn_sub(stack_t **head, unsigned int counter)
{
stack_t *aux;
int sus, nodes;

/* Initialize the auxiliary pointer to the head of the stack */
aux = *head;

/* Count the number of nodes in the stack */
for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;

/* Check if there are at least two elements in the stack for subtraction */
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Reset the auxiliary pointer to the head of the stack */
aux = *head;
/* Calculate the difference between the second top and top elements */
sus = aux->next->n - aux->n;
/* Update the second top element with the result */
aux->next->n = sus;
/* Update the head to point to the new top of the stack */
*head = aux->next;

/* Free the memory of the previous top element */
free(aux);
}
