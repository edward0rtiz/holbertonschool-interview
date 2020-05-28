#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Check if the linked list is a palindrome
 * @head: Type listint_s double pointer of node
 * return: 1 if is a palindrome 0 otherwise
 */

int is_palindrome(listint_s **head)
{
	if (head == NULL)
		return (1);
	else
		return(recursive_palindrome(head, **head));
}

int recursive_palindrome(listint_s *head, listint_t *tail);
{
	if (tail == NULL)
		return(1);
	if (recursive_palindrome(head, tail->next) && (*head)->n == tail->n)
	{
		*head = (*head)->next;
		return (1);
	}
	else
		return (0);
}
