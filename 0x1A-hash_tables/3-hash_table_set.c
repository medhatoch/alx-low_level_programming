#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_set - Add or update a key-value pair in the hash table
 * @ht: The hash table
 * @key: The key string (cannot be an empty string)
 * @value: The value associated with the key (can be an empty string)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    /* Calculate the index for the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check for collision by iterating through the linked list at the index */
    current_node = ht->array[index];
    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            /* Update the value if the key already exists */
            free(current_node->value);
            current_node->value = strdup(value);
            if (current_node->value == NULL)
                return (0);
            return (1);
        }
        current_node = current_node->next;
    }

    /* Allocate memory for the new node and duplicate the key and value */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);
    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }
    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    /* Add the new node at the beginning of the linked list */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
