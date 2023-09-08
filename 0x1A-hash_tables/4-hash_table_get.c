#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieve a value associated with a key from the hash table
 * @ht: The hash table
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if the key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *current_node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    /* Calculate the index for the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Iterate through the linked list at the index to find the key */
    current_node = ht->array[index];
    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            /* Key found, return its associated value */
            return (current_node->value);
        }
        current_node = current_node->next;
    }

    /* Key not found, return NULL */
    return (NULL);
}
