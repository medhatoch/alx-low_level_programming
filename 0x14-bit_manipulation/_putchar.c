#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, return the number of characters written.
 * On error, return -1 and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
