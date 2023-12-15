#include "monty.h"

/**
 * fn_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: Pointer to the head of the stack.
 * Description: This function prints the string starting at the top
 * of the stack, followed by a new line.
 * @counter: Line number where the operation is called
 * Return: No return value
 */
void fn_pstr(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;

/* If the stack is empty, print a new line */
if (h == NULL)
{
printf("\n");
return;
}

/* Traverse the stack and print characters until codition */
while (h && h->n != 0 && h->n >= 0 && h->n <= 127)
{
printf("%c", h->n);
h = h->next;
}
/* Print a new line after printing the string */
printf("\n");
}
