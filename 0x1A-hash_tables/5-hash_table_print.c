#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Print the elements of a hash table
 * @ht: The hash table
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    int printed = 0;
    hash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            if (printed)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            printed = 1;
            node = node->next;
        }
    }
    printf("}\n");
}
