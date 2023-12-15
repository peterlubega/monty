#include "monty.h"

/**
 * fn_nop - Does nothing; a NOP for Monty code.
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is called.
 * Description: This function performs a no-operation (NOP), doing nothing.
 * Unused parameters (head and counter) are intentionally left undeclared
 * to prevent compiler warnings about unused variables.
 * Return: No return value.
 */
void fn_nop(stack_t **head, unsigned int counter)
{
(void)counter;
(void)head;
}
