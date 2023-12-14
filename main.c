#define _POSIX_C_SOURCE 200809L

#include "monty.h"

/* Global variable to store inof shared across functions */
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter.
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
char *content;
FILE *file;
size_t size = 0;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int counter = 0;
/* Check if the correct number of cmd line args is provided */
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
/* Open the Monty file for reading */
file = fopen(argv[1], "r");
bus.file = file;
/* Check if the file was opened successfuly */
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
/* Read and execute each line of the Monty file */
while (read_line > 0)
{
content = NULL;
read_line = getline(&content, &size, file);
bus.content = content;
counter++;
/* Execute the instruction on the current line */
if (read_line > 0)
{
execute(content, &stack, counter, file);
}
/* Free the memeory allocated */
free(content);
}
/* Free the memory allocated for the stack */
free_stack(stack);
fclose(file);
return (0);
}
