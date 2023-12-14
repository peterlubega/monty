#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack or queue.
 * @n: integer value stroed in the node.
 * @prev: points to the previous element of the stack or queue.
 * @next: points to the next element of the stack or queue.
 *
 * Description: Node structure for a doubly linked list used for
 * implementing stack, ques, LIFO and FIFO.
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct bus_s - Structure holding variables for args,
 * file and line content.
 * @arg: Value (argument).
 * @file: pointer to monty file being processed.
 * @content: line content from the Monty file.
 * @lifi: flag indicating a change between stack and que operations.
 *
 * Description: This structue=re carries values throughtout the
 * program to share information across functions.
 */
typedef struct bus_s
{
char *arg;
FILE *file;
char *content;
int lifi;
}  bus_t;

/* Global variable to store shared info across functions */
extern bus_t bus;

/**
 * struct instruction_s - opcodes and its coressponding function.
 * @opcode: the opcode (instruction).
 * @f: Function poniter to the function handling the opcode.
 *
 * Description: Structure representing an opcode and its
 * associated function, used for stack, queues, LIFO, and FIFO
 * operations in the Holberton project.
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Function prototypes */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);

#endif
