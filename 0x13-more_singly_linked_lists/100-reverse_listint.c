#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
if (*head == NULL || (*head)->next == NULL)
return (*head);

listint_t *rest = reverse_listint(&(*head)->next);
(*head)->next->next = *head;
(*head)->next = NULL;

return (rest);
}
