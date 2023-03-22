#include "main.h"
/**
 * _islower - checks whether a character is lowercase
 * @c: the character to check
 *
 * Return: 1 if c is a letter, lowercase or uppercase, 0 otherwise.
 */
int _islower(int c)
{
if (c >= 'a' && c <= 'z')
{
return (1);
}
else if (c >= 'A' && c <= 'Z')
{
return (1);
}
else
{
return (0);
}
}
