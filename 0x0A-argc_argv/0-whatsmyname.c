#include "main.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
    print_program_name(argv[0]);
    return (0);
}

/**
 * print_program_name - Prints the program name
 * @program_name: The name of the program
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

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 (Success), -1 (Error)
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

