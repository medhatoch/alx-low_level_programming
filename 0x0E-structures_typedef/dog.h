#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure for dog information
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner name
 *
 * Description: This structure contains information about a dog
 */
struct dog
{
char *name;
float age;
char *owner;
};

/* Function prototype for init_dog */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
