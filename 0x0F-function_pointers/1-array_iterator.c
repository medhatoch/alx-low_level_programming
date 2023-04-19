#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - applies a function to each element of an array
 * @array: the array to iterate over
 * @size: the size of the array
 * @action: a function pointer to the function to apply to each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i;

if (array && action)
{
for (i = 0; i < size; i++)
action(array[i]);
}
}
