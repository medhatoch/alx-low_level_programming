#include "main.h"

/**
 * print_program_name - prints the name of the program
 * @program_name: the name of the program
 *
 * Return: void
 */
void print_program_name(char *program_name)
{
while (*program_name)
{
_putchar(*program_name);
program_name++;
}
_putchar('\n');
}
