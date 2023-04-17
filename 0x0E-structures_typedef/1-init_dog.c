#include "dog.h"
#include &lt;stddef.h&gt;

/**
 * init_dog - initializes a dog struct
 * @d: pointer to dog struct
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner name
 *
 * Return: None
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d != NULL)
    {
        d-&gt;name = name;
        d-&gt;age = age;
        d-&gt;owner = owner;
    }
}
