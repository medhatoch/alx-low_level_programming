#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table array.
 *
 * Return: A pointer to the created sorted hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));

    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (unsigned long int i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Inserts a key-value pair into the sorted hash table.
 * @ht: The sorted hash table to insert into.
 * @key: The key to insert.
 * @value: The value to insert.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            if (current->value == NULL)
                return (0);
            return (1);
        }
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
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

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Insert into sorted linked list */
    if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
    {
        new_node->snext = ht->shead;
        new_node->sprev = NULL;
        if (ht->shead != NULL)
            ht->shead->sprev = new_node;
        ht->shead = new_node;
        if (ht->stail == NULL)
            ht->stail = new_node;
    }
    else
    {
        current = ht->shead;
        while (current->snext != NULL && strcmp(key, current->snext->key) > 0)
            current = current->snext;
        new_node->snext = current->snext;
        new_node->sprev = current;
        if (current->snext != NULL)
            current->snext->sprev = new_node;
        current->snext = new_node;
        if (current == ht->stail)
            ht->stail = new_node;
    }

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in the sorted hash table.
 * @ht: The sorted hash table to search in.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in ascending order of keys.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    int first = 1;
    shash_node_t *current;

    if (ht == NULL)
        return;

    printf("{");
    current = ht->shead;
    while (current != NULL)
    {
        if (first)
            first = 0;
        else
            printf(", ");
        printf("'%s': '%s'", current->key, current->value);
        current = current->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in descending order of keys.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    int first = 1;
    shash_node_t *current;

    if (ht == NULL)
        return;

    printf("{");
    current = ht->stail;
    while (current != NULL)
    {
        if (first)
            first = 0;
        else
            printf(", ");
        printf("'%s': '%s'", current->key, current->value);
        current = current->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table and frees all allocated memory.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current, *temp;
unsigned long int i;
    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}
