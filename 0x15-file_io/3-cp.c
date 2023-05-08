#include <stdio.h>
#include <stdlib.h>
#include "copy_file.c"

/**
* main - Entry point for the program
* @argc: The number of arguments passed to the program
* @argv: An array of strings containing the arguments passed to the program
*
* Return: 0 on success, 97-100 on error
*/

int main(int argc, char **argv)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

if (copy(argv[1], argv[2]) == 1)
{
exit(99);
}

return (0);
}
