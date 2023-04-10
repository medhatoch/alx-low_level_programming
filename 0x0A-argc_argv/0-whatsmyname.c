#include "main.h"
#include <stdio.h>

/**
 * print_program_name - Prints program name followed by newline
 * @argc: The number of command line arguments
 * @argv: An array of strings containing the command line arguments
 *
 * Return: Nothing
 */
void print_program_name(int argc, char **argv)
{
(void)argc;
printf("%s\n", argv[0]);
}
