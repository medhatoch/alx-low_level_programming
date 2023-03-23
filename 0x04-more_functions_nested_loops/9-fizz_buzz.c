#include "main.h"
/**
 * fizz_buzz - Prints the numbers from 1 to 100, replacing
 * multiples of 3 with "Fizz", multiples of 5 with "Buzz",
 * and multiples of both 3 and 5 with "FizzBuzz".
 */
void fizz_buzz(void)
{
int i;
for (i = 1; i <= 100; i++)
{
if (i % 3 == 0 && i % 5 == 0)
{
_putchar('F');
_putchar('i');
_putchar('z');
_putchar('z');
_putchar('B');
_putchar('u');
_putchar('z');
_putchar('z');
_putchar(' ');
}
else if (i % 3 == 0)
{
_putchar('F');
_putchar('i');
_putchar('z');
_putchar('z');
_putchar(' ');
}
else if (i % 5 == 0)
{
_putchar('B');
_putchar('u');
_putchar('z');
_putchar('z');
_putchar(' ');
}
else
{
int j = i;
while (j > 0)
{
_putchar(j % 10 + '0');
j /= 10;
}
_putchar(' ');
}
}
_putchar('\n');
}
