#include "main.h"
/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
int i;

if (n < 2) /* 0 and 1 are not prime */
return (0);

if (n == 2) /* 2 is prime */
return (1);

if (n % 2 == 0) /* all even numbers except 2 are not prime */
return (0);

for (i = 3; i <= sqrt(n); i += 2) /* check odd numbers from 3 to sqrt(n) */
{
if (n % i == 0) /* if i divides n without a remainder, n is not prime */
return (0);
}

return (1); /* n is prime */
}
