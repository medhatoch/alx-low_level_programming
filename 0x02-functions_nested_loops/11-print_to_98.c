#include "main.h"
/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
int i;
char digit;

if (n <= 98)
{
for (i = n; i < 98; i++)
{
digit = i / 10;
_putchar(digit);
digit = i % 10;
_putchar(digit);
_putchar(',');
_putchar(' ');
}
}
else
{
for (i = n; i > 98; i--)
{
digit = i / 10;
_putchar(digit);
digit = i % 10;
_putchar(digit);
_putchar(',');
_putchar(' ');
}
}

_putchar('9');
_putchar('8');
_putchar('\n');
}



