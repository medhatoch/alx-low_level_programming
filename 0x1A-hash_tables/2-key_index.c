#include "hash_tables.h"

/**
 * key_index - Get the index of a key in the hash table's array
 * @key: The key string
 * @size: The size of the array in the hash table
 *
 * Return: The index at which the key should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    /* Calculate the hash value using the hash_djb2 function */
    unsigned long int hash_value = hash_djb2(key);

    /* Map the hash value to an index within the array size */
    unsigned long int index = hash_value % size;

    return (index);
}
