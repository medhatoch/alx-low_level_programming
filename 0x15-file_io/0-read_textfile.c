#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if the file cannot be opened or read, or if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
ssize_t file_descriptor;
ssize_t bytes_written;
ssize_t bytes_read;

fd = open(filename, O_RDONLY);
if (file_descriptor == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(file_descriptor, buffer, letters);
w = write(STDOUT_FILENO, buffer, bytes_read);

free(buffer);
close(file_descriptor);
return (bytes_written);
}
