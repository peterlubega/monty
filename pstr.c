#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called
 * Return: No return value
 */
void f_pstr(stack_t **head, unsigned int counter)
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

/**
 * Traverse the stack and print characters until encountering
 * a zero or a value outside the ASCII printable range
 */
while (h && h->n != 0 && h->n >= 0 && h->n <= 127)
{
printf("%c", h->n);
h = h->next;
}
/* Print a new line after printing the string */
printf("\n");
}
