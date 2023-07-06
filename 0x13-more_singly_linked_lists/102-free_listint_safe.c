#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint - Frees a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Description: This function frees a listint_t linked list
 * without handling loops.
 */
void free_listint(listint_t *head)
{
listint_t *temp;

while (head)
{
temp = head;
head = head->next;
free(temp);
}
}

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *slow = *h;
listint_t *fast = *h;
size_t count = 0;
int loop_detected = 0;

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
count++;

if (slow == fast)
{
loop_detected = 1;
break;
}
}

if (loop_detected)
{
listint_t *loop_node = slow;
listint_t *temp = *h;

while (temp != loop_node)
{
listint_t *next = temp->next;
free(temp);
temp = next;
count++;
}

*h = NULL;
return (count);
}

free_listint(*h);
*h = NULL;
return (count);
}
