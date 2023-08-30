#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *child_node;

	if (parent == NULL)
		return (NULL);

	child_node = binary_tree_node(parent, value);

	if (child_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		child_node->left = parent->left;
		child_node->left->parent = child_node;
	}

	parent->left = child_node;

	return (child_node);
}
