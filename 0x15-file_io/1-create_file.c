#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - Creates a file with the specified content and permissions.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int file_descriptor, write_result, text_length = 0;

if (filename == NULL)
return (-1);

/* Open the file with write permissions, creating it if it doesn't exist */
file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (file_descriptor == -1)
return (-1);

/* If text_content is not NULL, write its contents to the file */
if (text_content != NULL)
{
while (text_content[text_length] != '\0')
text_length++;

write_result = write(file_descriptor, text_content, text_length);
if (write_result == -1)
{
close(file_descriptor);
return (-1);
}
}

close(file_descriptor);
return (1);
}
