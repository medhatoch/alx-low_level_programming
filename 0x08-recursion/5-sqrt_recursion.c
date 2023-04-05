#include "main.h"
/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The natural square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
if (n == 0 || n == 1)
return (n);

return find_sqrt(n, 1, n / 2);
}

/**
 * find_sqrt - Recursive helper function to find the square root of a number
 * @n: The number to find the square root of
 * @start: The starting value of the search range
 * @end: The ending value of the search range
 *
 * Return: The natural square root of n, or -1 if n does not have a natural square root
 */
int find_sqrt(int n, int start, int end)
{
int mid = (start + end) / 2;

if (mid * mid == n)
return (mid);
else if (mid * mid > n)
return find_sqrt(n, start, mid - 1);
else if ((mid + 1) * (mid + 1) <= n)
return find_sqrt(n, mid + 1, end);
else
return (-1);
}
