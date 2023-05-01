#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
size_t n = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
n++;
}

return (n);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slowPtr = head, *fastPtr = head;
int loopExists = 0;
size_t n = 0;

while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL)
{
slowPtr = slowPtr->next;
fastPtr = fastPtr->next->next;

if (slowPtr == fastPtr)
{
loopExists = 1;
break;
}
}

if (loopExists)
{
do {
printf("%d\n", slowPtr->n);
slowPtr = slowPtr->next;
n++;
} while (slowPtr != fastPtr);

printf("...\n");
return (n);
}
else
{
return (print_listint(head));
}
}
