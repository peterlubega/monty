#include "monty.h"

/**
 * f_queue - Sets the stack behavior to queue (FIFO).
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Return: No return value.
 */
void f_queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
/* Set the stack behavior to queue (FIFO) */
bus.lifi = 1;
}

/**
 * addqueue - Adds a new node with a given integer to
 * the tail of the stack.
 * @head: Pointer to the head of the stack.
 * @n: New value to be added to the stack.
 * Return: No return value.
 */
void addqueue(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;

/* Allocate memory for the new node */
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}

/* Set the value of the new node */
new_node->n = n;
new_node->next = NULL;

/* traverse to the end to add the new node */
if (aux)
{
while (aux->next)
aux = aux->next;
}

/* update the head to the new node */
if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
/* Add the new node to the tail of the stack */
aux->next = new_node;
new_node->prev = aux;
}
}
