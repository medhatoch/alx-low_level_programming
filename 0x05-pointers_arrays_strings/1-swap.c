#include "main.h"
/**
 * swap_int - swaps the values of two integers.
 * @a: pointer to an integer.
 *
 * @b: pointer to an integer.
 *
 * @c: permutator.
 *
 * Return: void.
 */
void void swap_int(int *a, int *b)
{
int *c;
*c = *a;
*a = *b;
*b = *c;
return (0);
}
