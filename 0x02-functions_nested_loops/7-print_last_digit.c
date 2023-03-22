#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 *
 * @n: the number to print the last digit of
 *
 * Return: the value of the last digit of n
 */
int print_last_digit(int n)
{
int last_digit;

/* Get the last digit of n */
if (n < 0)
last_digit = -1 * (n % 10);
else
last_digit = n % 10;

/* Print the last digit */
_putchar(last_digit + '0');

/* Return the value of the last digit */
return (last_digit);
}
