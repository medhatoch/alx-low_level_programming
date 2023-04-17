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

/* Define dog_t as a new name for struct dog */
typedef struct dog dog_t;


/* Function prototype for init_dog */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
