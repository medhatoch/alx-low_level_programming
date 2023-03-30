#include "main.h"
/**
 * _strncpy - Copies up to n bytes of the string pointed to by src
 *            to the buffer pointed to by dest.
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 * @n: Maximum number of bytes to copy from src
 *
 * Return: Pointer to the destination buffer dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];

for ( ; i < n; i++)
dest[i] = '\0';

return (dest);
}
