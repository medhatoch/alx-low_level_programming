#include "main.h"
#include <stdlib.h>  // Required for malloc and exit


/**
 * malloc_checked - Allocates memory using malloc
 * @b: The amount of memory to allocate
 *
 * Return: A pointer to the allocated memory
 *         If malloc fails, the malloc_checked function causes normal process
 *         termination with a status value of 98
 */
void *malloc_checked(unsigned int b)
{
  void *ptr;

  ptr = malloc(b);
  if (ptr == NULL) {
    perror("Error: malloc failed");
    exit(98);
  }

  return (ptr);
}
