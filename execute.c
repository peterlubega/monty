#include "monty.h"

/**
 * execute - executes the opcode.
 * @content: line content from Monty file.
 * @stack: pointer to the head of the stack
 * @counter: line counter
 * @file: poiner to Monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{

/* Array of opcode-function pairs*/
instruction_t opst[] = {
{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
{"sub", f_sub},
{"div", f_div},
{"mul", f_mul},
{"mod", f_mod},
{"pchar", f_pchar},
{"pstr", f_pstr},
{"rotl", f_rotl},
{"rotr", f_rotr},
{"queue", f_queue},
{"stack", f_stack},
{NULL, NULL}
};

unsigned int i = 0;
char *op;

/* Tockenize the content tp extract the opcode */
op = strtok(content, " \n\t");

/* If the opcode is a comment, ignore the line */
if (op && op[0] == '#')
return (0);

/* Extract the argument for the opcode*/
bus.arg = strtok(NULL, " \n\t");

/* Search for the opcode in the opcode-function array*/
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
/* Execute the corresponding function for thr opcode*/
opst[i].f(stack, counter);
return (0);
}
i++;
}

/* If the opcode is not found, print an error msg and exit*/
if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}

/* Return 1 to indicate failure */
return (1);
}
