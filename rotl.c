#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called
 * Return: No return value.
 */

void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
stack_t *tmp = *head, *aux;

/* If the stack is empty or has only one element, no rotation needed */
if (*head == NULL || (*head)->next == NULL)
{
return;
}

/* Save the second element of the stack */
aux = (*head)->next;
aux->prev = NULL;

/* Traverse to the end of the stack */
while (tmp->next != NULL)
{
tmp = tmp->next;
}

/* Connect the last element to the original head */
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;

/* pdate the head to the second element, effectively rotating the stack */
(*head) = aux;
}
