#include "main.h"

int find_sqrt(int n, int min, int max);

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the number to find the square root of.
 *
 * Return: the natural square root of @n, or -1 if @n does not have a natural
 * square root.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);

return find_sqrt(n, 1, n / 2);
}

/**
 * find_sqrt - finds the natural square root of a number within a given range.
 * @n: the number to find the square root of.
 * @min: the minimum possible square root of @n.
 * @max: the maximum possible square root of @n.
 *
 * Return: the natural square root of @n, or -1 if @n does not have a natural
 * square root.
 */
int find_sqrt(int n, int min, int max)
{
if (min > max)
return (-1);

int guess = (min + max) / 2;
int square = guess * guess;

if (square == n)
return (guess);

if (square < n)
return (find_sqrt(n, guess + 1, max));

return (find_sqrt(n, min, guess - 1));
}
