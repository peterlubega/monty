#include "monty.h"

/**
 * f_push - Adds a new node with a given integer to the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Return: No return value.
 */

void f_push(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;
/* Check if the argument for push is provided */
if (bus.arg)
{
if (bus.arg[0] == '-')
j++;
/* Validate that the argument is a valid integer */
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] > 57 || bus.arg[j] < 48)
flag = 1; }
/* If the argument is not a valid integer, exit with an error */
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
else
{
/* If no argument is provided for push, exit with an error */
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
/* Convert the argument to an integer */
n = atoi(bus.arg);
/* Add the new node to the stack or queue based on the flag */
if (bus.lifi == 0)
addnode(head, n);
else
addqueue(head, n);
}
