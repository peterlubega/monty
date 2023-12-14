#include "monty.h"

/**
 * addnode - adds a new node to the head of the stack
 * @head: pointer to the head of the stack
 * @n: value of the new node
 * Return: no return
 */
void addnode(stack_t **head, int n)
{

stack_t *new_node, *aux;

/* Save the current head of the stack */
aux = *head;

/* Allocate memory for the new node */
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
exit(0); }

/* Update the previous pointer of the current head */
if (aux)
aux->prev = new_node;

/* Initialze thee new node with the given value and connections */
new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;

/* Update the head of the stack to point to the new node */
*head = new_node;
}
