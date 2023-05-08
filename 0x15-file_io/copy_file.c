#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * copy - Copies the contents of one file to another
 * @file_from: The path to the file to copy from
 * @file_to: The path to the file to copy to
 *
 * Return: 0 on success, 1 on error
 */

int copy(const char *file_from, const char *file_to)
{
int fd_from, fd_to, ret;
ssize_t nread;
char buf[BUFSIZE];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
{
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
    return (1);
}

fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
    return (1);
}

while ((nread = read(fd_from, buf, BUFSIZE)) > 0)
{
    ret = write(fd_to, buf, nread);
    if (ret != nread)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        return (1);
    }
}

if (nread == -1)
{
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
    return (1);
}

if (close(fd_from) == -1)
{
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
    return (1);
}

if (close(fd_to) == -1)
{
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
    return (1);
}

return (0);
}
