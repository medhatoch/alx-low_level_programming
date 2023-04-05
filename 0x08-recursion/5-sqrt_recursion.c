#include "main.h"
/**
 * find_sqrt - helper function to find the natural square root of a number.
 *
 * @n: the number to find the square root of.
 * @start: the starting point of the search.
 * @end: the ending point of the search.
 *
 * Return: the square root of n, or -1 if n does not have a natural square root.
 */
int find_sqrt(int n, int start, int end)
{
if (start > end)
return (-1);
if (start * start == n)
return (start);
if (start * start > n)
return (-1);
return (find_sqrt(n, start + 1, end));
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 *
 * @n: the number to find the square root of.
 *
 * Return: the square root of n, or -1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (find_sqrt(n, 1, n / 2));
}
