#include "main.h"
/**
 * puts_half - prints the second half of a string.
 * @str: pointer to a character string.
 *
 * Return: void.
 */
void puts_half(char *str)
{
int length = 0, i, n;

while (str[length] != '\0')
{
length++;
}

if (length % 2 == 0)
{
n = length / 2;
}
else
{
n = (length - 1) / 2;
}

for (i = n; i < length; i++)
{
putchar(str[i]);
}

putchar('\n');
}
