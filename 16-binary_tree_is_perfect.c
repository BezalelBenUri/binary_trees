#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *nd);
size_t depth(const binary_tree_t *stem);
const binary_tree_t *get_leaf(const binary_tree_t *stem);
int is_perfect_recursive(const binary_tree_t *stem,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *nd)
{
	return ((node->left == NULL && nd->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t depth(const binary_tree_t *stem)
{
	return (stem->parent != NULL ? 1 + depth(stem->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *stem)
{
	if (is_leaf(stem) == 1)
		return (stem);
	return (stem->left ? get_leaf(stem->left) : get_leaf(stem->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *stem,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(stem))
		return (level == leaf_depth ? 1 : 0);
	if (stem->left == NULL || stem->right == NULL)
		return (0);
	return (is_perfect_recursive(stem->left, leaf_depth, level + 1) &&
		is_perfect_recursive(stem->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
