#include "lists.h"
#include <stdio.h>

int check_cycle(listint_t *list)
{
	listint_t *loop_one;
	listint_t *loop_two;

	if (list == NULL || list->next == NULL)
		return (0);

	loop_one = list->next;
	loop_two = list->next->next;

	while (loop_one && loop_two && loop_two->next)
	{
		if (loop_one == loop_two->next)
		{
			return (1);
		}
		loop_one = loop_one->next;
		loop_two = loop_two->next->next;
	}
	return (0);
}
