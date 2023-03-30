#include "main.h"
/**
 * reverse_array - Reverses the content of an array of integers
 * @a: Pointer to the array to be reversed
 * @n: Number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
int i, j, temp;

for (i = 0, j = n - 1; i < j; i++, j--)
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
