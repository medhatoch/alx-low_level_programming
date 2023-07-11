#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * display_error - Displays an error message and exits with the specified code.
 * @message: The error message to display.
 * @code: The exit code.
 */
void display_error(const char *message, int code);

/**
 * copy_file - Copies the content of a file to another file.
 * @file_from: The source file name.
 * @file_to: The destination file name.
 * Return: 0 on success, -1 on failure.
 */
int copy_file(const char *file_from, const char *file_to);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 97 on incorrect number of arguments, 98 on copy error.
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
display_error("Usage: cp file_from file_to\n", 97);
exit(97);
}

if (copy_file(argv[1], argv[2]) == -1)
exit(98);

return (0);
}

void display_error(const char *message, int code)
{
dprintf(STDERR_FILENO, message);
exit(code);
}

int copy_file(const char *file_from, const char *file_to)
{
int file_descriptor_from, file_descriptor_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

/* Open the source file in read-only mode */
file_descriptor_from = open(file_from, O_RDONLY);
if (file_descriptor_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
return (-1);
}

/* Open or create the destination file in write-only mode */
file_descriptor_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (file_descriptor_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
close(file_descriptor_from);
return (-1);
}

while ((bytes_read = read(file_descriptor_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(file_descriptor_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
close(file_descriptor_from);
close(file_descriptor_to);
return (-1);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
close(file_descriptor_from);
close(file_descriptor_to);
return (-1);
}

if (close(file_descriptor_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor_from);
close(file_descriptor_to);
return (-1);
}

if (close(file_descriptor_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor_to);
return (-1);
}

return (0);
}
