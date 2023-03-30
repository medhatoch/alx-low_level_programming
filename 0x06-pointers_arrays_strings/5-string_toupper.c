#include "main.h"
/**
 * string_toupper - Changes all lowercase letters of a string to uppercase
 * @s: Pointer to the string to be converted
 *
 * Return: Pointer to the converted string
 */
char *string_toupper(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= 'a' && s[i] <= 'z')
{
s[i] = s[i] - 'a' + 'A';
}
}

return (s);
}
