#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_ptr - frees a listint_ptr_t list
 * @head: pointer to pointer to head of list
 *
 * Return: void
 */
void free_listint_ptr(listint_ptr_t **head)
{
listint_ptr_t *tmp;

while (*head)
{
tmp = *head;
*head = (*head)->next;
free(tmp);
}
}

/**
 * check_cycle - checks if a linked list contains a cycle
 * @head: pointer to head of list
 *
 * Return: 1 if cycle found, 0 otherwise
 */
int check_cycle(listint_t *head)
{
listint_t *slow = head, *fast = head;

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
return (1);
}

return (0);
}

/**
 * free_listint_safe - frees a listint_t list, even if it contains a cycle
 * @h: pointer to pointer to head of list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
size_t size = 0;
listint_ptr_t *head_ptr = NULL, *new_ptr = NULL;
listint_t *tmp = NULL;

if (h == NULL || *h == NULL)
return (0);

tmp = *h;
while (tmp)
{
size++;
new_ptr = malloc(sizeof(listint_ptr_t));
if (new_ptr == NULL)
{
free_listint_ptr(&head_ptr);
exit(98);
}
new_ptr->ptr = (void *)tmp;
new_ptr->next = head_ptr;
head_ptr = new_ptr;
if (check_cycle(*h))
{
free_listint_ptr(&head_ptr);
exit(98);
}
tmp = tmp->next;
}

free_listint_ptr(&head_ptr);
while (*h)
{
tmp = (*h)->next;
free(*h);
*h = tmp;
}

*h = NULL;
return (size);
}
