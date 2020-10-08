#include "binary_trees.h"
/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to root
 * @node: pointer to node in the tree
 * @h: height of the tree
 * @level: layer in the tree
 * Return: no return
 **/
void binary_tree_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (!tree)
		return;
	if (h == level)
		*node = tree;
	level++;
	if (tree->left)
		binary_tree_preorder(tree->left, node, h, level);
	if (tree->right)
		binary_tree_preorder(tree->right, node, h, level);
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree from node
 **/
size_t binary_tree_height(const heap_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = binary_tree_height(tree->right) + 1;
	left = binary_tree_height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value, value_aux;
	size_t level = 0;
	heap_t *aux, *node;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right)
	{
		*root = NULL;
		free(aux);
		return (value);
	}
	binary_tree_preorder(aux, &node, binary_tree_height(aux), level);
	while (aux->left || aux->right)
	{
		if (!aux->right || aux->left->n > aux->right->n)
		{
			value_aux = aux->n;
			aux->n = aux->left->n;
			aux->left->n = value_aux;
			aux = aux->left;
		}
		else if (!aux->left || aux->left->n < aux->right->n)
		{
			value_aux = aux->n;
			aux->n = aux->right->n;
			aux->right->n = value_aux;
			aux = aux->right;
		}

	}
	aux->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
