#include "main.h"
/**
 * puts2 - prints every other character of a string, starting with the first.
 * @str: pointer to a character string.
 *
 * Return: void.
 */
void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
if (i % 2 == 0)
{
putchar(str[i]);
}
i++;
}

putchar('\n');
}
