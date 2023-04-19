#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: the array to search
 * @size: the size of the array
 * @cmp: a function pointer to the comparison function
 *
 * Return: the index of the first element for which cmp doesn't return 0,
 * or -1 if no element matches or if size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;

if (array && cmp && size > 0)
{
for (i = 0; i < size; i++)
{
if (cmp(array[i]) != 0)
return (i);
}
}

return (-1);
}
