#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to head of list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current;
size_t count;

current = head;
count = 0;

while (current != NULL)
{
printf("[%p] %d\n", (void *) current, current->n);
count++;
if (current < current->next)
{
current = current->next;
}
else
{
printf("-> [%p] %d\n", (void *) current->next, current->next->n);
break;
}
}

if (current == NULL)
{
return (count);
}
else
{
exit(98);
}
}
