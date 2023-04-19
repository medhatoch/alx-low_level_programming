#include "function_pointers.h"

/**
 * print_name - prints a name in a specific format
 * @name: the name to print
 * @f: a function pointer to the print format
 */
void print_name(char *name, void (*f)(char *))
{
if (name && f)
f(name);
}
