#include "binary_trees.h"
/**
 * binary_tree_node - create a node
 * @parent: pointer to parent
 * @value: value for child node
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *child_nd;

	child_nd = malloc(sizeof(binary_tree_t));
	if (child_nd == NULL)
		return (NULL);
	child_nd->n = value;
	child_nd->parent = parent;
	child_nd->left = NULL;
	child_nd->right = NULL;
	return (nodo);
}
