#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner name
 *
 * Return: pointer to the new dog, or NULL if fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;
char *name_copy, *owner_copy;
int name_len, owner_len, i;

/* Allocate memory for the new dog */
new_dog = malloc(sizeof(dog_t));
if (new_dog == NULL)
return (NULL);

/* Get the length of name and owner */
for (name_len = 0; name[name_len] != '\0'; name_len++)
;
for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
;

/* Allocate memory for name and owner copies */
name_copy = malloc(name_len + 1);
if (name_copy == NULL)
{
free(new_dog);
return (NULL);
}
owner_copy = malloc(owner_len + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(new_dog);
return (NULL);
}

/* Copy name and owner to their allocated memory */
for (i = 0; i <= name_len; i++)
name_copy[i] = name[i];
for (i = 0; i <= owner_len; i++)
owner_copy[i] = owner[i];

/* Initialize the new dog */
new_dog->name = name_copy;
new_dog->age = age;
new_dog->owner = owner_copy;

return (new_dog);
}
