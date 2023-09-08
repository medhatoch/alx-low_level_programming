#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    /* Declare variables at the beginning of the function */
    unsigned long int i;
    hash_table_t *new_table;

    /* Allocate memory for the hash table */
    new_table = malloc(sizeof(hash_table_t));

    if (new_table == NULL)
    {
        /* Handle memory allocation error */
        return (NULL);
    }

    /* Allocate memory for the array of hash nodes */
    new_table->array = malloc(sizeof(hash_node_t *) * size);

    if (new_table->array == NULL)
    {
        /* Handle memory allocation error */
        free(new_table);
        return (NULL);
    }

    /* Initialize the size field */
    new_table->size = size;

    /* Initialize all elements of the array to NULL using a separate loop */
    for (i = 0; i < size; i++)
    {
        new_table->array[i] = NULL;
    }

    return (new_table);
}
