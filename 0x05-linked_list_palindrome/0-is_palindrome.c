#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Check if the linked list is a palindrome
 * @head: Type listint_s double pointer of node
 * Return: 1 if is a palindrome 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL && *head == NULL)
		return (1);
	else
		return (recursive_palindrome(head, *head));
}

/**
 * recursive_palindrome - Recursive function that traverse each node
 * in parallel
 * @head: type listint_s double pointer of the node aka head
 * @tail: type listint_s double pointer of the last node aka tail
 * Return: 1 if is a palindrome otherwise 0
 */
int recursive_palindrome(listint_t **head, listint_t *tail)
{
	if (tail == NULL)
		return (1);

	if (recursive_palindrome(head, tail->next) && (*head)->n == tail->n)
	{
		*head = (*head)->next;
		return (1);
	}
	else
		return (0);
}
