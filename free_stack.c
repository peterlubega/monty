#include "monty.h"

/**
 * free_stack - frees a doubly linked list.
 * @head: pointer to the head of the satck.
 */
void free_stack(stack_t *head)
{
stack_t *aux;

/*Use aux to traverse the list while freeing each node */
aux = head;
while (head)
{
/* Save the next node before freeing the current one */
aux = head->next;
/* Free the current node */
free(head);
/* Move to the next node */
head = aux;
}
}
