#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_node - create an AVL tree
 * @parent: pointer of parent node -printed one
 * @n: size of the tree
 * Return: binary tree otherwise NULL
 */

avl_t *binary_tree_node(avl_t *parent, size_t n)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	return (new_node);
}
/**
 * insert_node - Insert node in the AVL tree
 * @array: Pointer to the element printed
 * @parent: Parent of new node
 * @first: first element in the array
 * @last: last element in the array
 * Return: binary tree otherwise NULL
 */
avl_t *insert_node(int *array, size_t first, size_t last, avl_t *parent)
{
	size_t mid;
	avl_t *root_node;

	if (first > last)
		return (NULL);
	mid = (first + last) / 2;
	root_node = binary_tree_node(parent, array[mid]);
	if (!root_node)
		return (NULL);
	if (mid != first)
		root_node->left = insert_node(array, first, mid - 1, root_node);
	if (mid != last)
		root_node->right = insert_node(array, mid + 1, last, root_node);
	return (root_node);
}
/**
 * sorted_array_to_avl - Insert node insorting nodes at AVL tree
 * @array: Pointer to the element printed
 * @size: number of elements in the array
 * Return: Sorted node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (array == NULL)
		return (NULL);
	return (insert_node(array, 0, size - 1, NULL));
}
