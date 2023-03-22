#include "main.h"
/**
* times_table - prints the 9 times table
*/
void times_table(void)
{
int row, column, product;

for (row = 0; row <= 9; row++)
{
for (column = 0; column <= 9; column++)
{
/* Calculate the product of row and column */
product = row * column;

/* Print the product, with appropriate spacing */
if (column == 0)
{
/* For the first column, print just the product */
_putchar(product + '0');
}
else if (product <= 9)
{
/* For single-digit products, print with leading and trailing spaces */
_putchar(' ');
_putchar(product + '0');
}
else
{
/* For double-digit products, print with leading space only */
_putchar((product / 10) + '0');
_putchar((product % 10) + '0');
}

/* Print a comma and a space after each column (except the last) */
if (column < 9)
{
_putchar(',');
_putchar(' ');
}
}

/* Start a new line after each row */
_putchar('\n');
}
}
