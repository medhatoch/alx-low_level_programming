#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node with a given value at a specified position in a linked list
 * @head: pointer to pointer to the head of the linked list
 * @idx: index where the new node should be added, starting from 0
 * @n: value to be assigned to the data (n) field of the new node
 *
 * Return: the address of the new node, or NULL if it failed to add the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *current;
unsigned int i;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

current = *head;
for (i = 0; i < idx - 1 && current != NULL; i++)
current = current->next;

if (current == NULL)
{
free(new_node);
return (NULL);
}

new_node->next = current->next;
current->next = new_node;

return (new_node);
}
