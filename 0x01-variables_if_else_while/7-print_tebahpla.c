#include<stdio.h>
/* more headers goes there */

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char var;
for (var = 'z'; var >= 'a'; var--)
{
putchar(var);
}
putchar('\n');
return (0);
}
