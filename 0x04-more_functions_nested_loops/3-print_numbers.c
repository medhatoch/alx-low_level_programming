#include "main.h"
/**
 * print_numbers - prints the numbers, from 0 to 9, followed by a new line
 *
 * @n: number
 *
 * Return: void
 */
void print_numbers(void)
{
int n = 0;
while (n < 10)
{
_putchar(n + '0');
n++;
}
_putchar('\n');
}
