#include "list.h"
List *first_node(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(str);
		return (NULL);
	}
	new->next = new;
	new->prev = new;
	*list = new;
	return (new);
}
/**
 * add_node_end - adds node at the end
 * @list: circular linked list
 * @str: string to insert
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *tmp, *aux;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
		return (first_node(list, str));

	aux = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = aux;
	new->prev = aux->prev;
	tmp = aux->prev;
	aux->prev = new;
	tmp->next = new;

	return (new);
}
/**
 * add_node_begin - adds node at the beginning
 * @list: circular linked list
 * @str: string to insert
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *tmp, *aux;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
		return (first_node(list, str));

	aux = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = aux;
	new->prev = aux->prev;
	tmp = aux->prev;
	aux->prev = new;
	tmp->next = new;
	*list = new;

	return (new);

}
