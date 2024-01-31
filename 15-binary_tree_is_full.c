#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if full or If tree is NULL, 1 if not
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (tree)
	{
		if ((tree->left && !tree->right) ||
				(!tree->left && tree->right))
			return (0);
		full = 1;
		full = tree->left ? binary_tree_is_full(tree->left) : full;
		if (full == 0)
			return (0);
		full = tree->right ? binary_tree_is_full(tree->right) : full;
	}
	return (full);
}
