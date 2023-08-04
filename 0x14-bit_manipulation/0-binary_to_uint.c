#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Return: The converted number, or 0 if there is an invalid character or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int num = 0;
int i;

if (b == NULL)
return (0);

for (i = 0; b[i] != '\0'; i++)
{
if (b[i] != '0' && b[i] != '1')
return (0);

num <<= 1; /* Left shift by 1 position */
num += (b[i] - '0'); /* Convert char to int and add to num */
}

return (num);
}
