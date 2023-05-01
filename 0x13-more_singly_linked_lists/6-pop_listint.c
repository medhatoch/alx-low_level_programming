#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 *
 * Return: the data (n) of the deleted node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int n;

if (head == NULL || *head == NULL)
{
return (0);
}

temp = *head;
*head = (*head)->next;
n = temp->n;
free(temp);

return (n);
}
