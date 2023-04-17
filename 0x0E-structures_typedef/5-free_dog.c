#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees the memory allocated for a dog
 * @d: pointer to dog to free
 *
 * Return: None
 */
void free_dog(dog_t *d)
{
    if (d != NULL)
    {
        free(d->name);
        free(d->owner);
        free(d);
    }
}
