#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>
#include <string.h>
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
#endif
