#include "main.h"
/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 */
void puts_half(char *str)
{
int length = 0;
int i;

while (str[length] != '\0')
{
length++;
}

if (length % 2 == 0)
{
for (i = length / 2; i < length; i++)
{
putchar(str[i]);
}
}
else
{
for (i = (length + 1) / 2; i < length; i++)
{
putchar(str[i]);
}
}

putchar('\n');
}
