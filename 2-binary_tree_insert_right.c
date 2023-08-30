#include "binary_trees.h"
#include "limits.h"

size_t high(const binary_tree_t *stem);
int is_avl_helper(const binary_tree_t *stem, int a, int b);
int binary_tree_is_avl(const binary_tree_t *stem);

/**
 * high - Measures the height of a binary tree.
 * @stem: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t high(const binary_tree_t *stem)
{
	if (stem)
	{
		size_t a = 0, k = 0;

		a = stem->left ? 1 + height(stem->left) : 1;
		k = stem->right ? 1 + height(stem->right) : 1;
		return ((a > k) ? a : k);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @stem: A pointer to the root node of the tree to check.
 * @a: The value of the smallest node visited thus far.
 * @b: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *stem, int a, int b)
{
	size_t lgt, rgt, iff;

	if (stem != NULL)
	{
		if (stem->n < a || stem->n > b)
			return (0);
		lgt = height(stem->left);
		rgt = height(stem->right);
		iff = lgt > rgt ? lgt - rgt : rgt - lgt;
		if (iff > 1)
			return (0);
		return (is_avl_helper(stem->left, a, stem->n - 1) &&
			is_avl_helper(stem->right, stem->n + 1, b));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @stem: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *stem)
{
	if (stem == NULL)
		return (0);
	return (is_avl_helper(stem, INT_MIN, INT_MAX));
}
