#include "lists.h"
/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *curr = *head;
listint_t *next = NULL;

while (curr != NULL)
{
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}

*head = prev;
return (*head);
}
