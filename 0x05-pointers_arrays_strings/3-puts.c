#include "main.h"
/**
 * _puts - prints a string to stdout, followed by a new line.
 * @str: pointer to a character string.
 *
 * Return: void.
 */
void _puts(char *str)
{
int i = 0;

while (str[i] != '\0')
{
putchar(str[i]);
i++;
}

putchar('\n');
}
