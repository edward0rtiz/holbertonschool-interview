#include "search.h"

/**
 * list_check - check for value in list
 * @node: type pointer of node in the lists
 * @value: type pointer of the first node indicating value
 * Return: addres pointer where the value is located otherwise NULL
 *
 */

skiplist_t *list_check(skiplist_t *node, int value)
{
	for (; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		if (node->n == value)
		{
			return (node);
		}
	}
	return (NULL);
}
/**
 * linear_skip -  search a value in a sorted list
 * @list: type pointer to head of the list bieng searched
 * @value: type int value to search in the list
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current_node, *prev_node, *temp_node;

	if (list == 0)
	{
		return (NULL);
	}
	current_node = list;
	while (current_node)
	{
		if (current_node->express == NULL)
		{
			prev_node = current_node->express;
			for (temp_node = list; temp_node;
			     temp_node = temp_node->next)
				if (temp_node->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
					       current_node->index,
					       temp_node->index);
					break;
				}
			break;
		}
		if (current_node->express->n >= value)
		{
			prev_node = current_node->express;
			printf("Value checked at index [%lu] = [%d]\n",
			       prev_node->index, prev_node->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       current_node->index, prev_node->index);
			break;
		}
		current_node = current_node->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       current_node->index, current_node->n);
	}
	return (list_check(current_node, value));
}
