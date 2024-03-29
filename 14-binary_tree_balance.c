#include "binary_trees.h"


/**
 * binary_tree_balance -  measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the given tree or subtree
 *			If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	left = determine_height(tree->left);
	right = determine_height(tree->right);
	return (left - right);
}


/**
 * determine_height - determines the height of a tree
 * @tree: pointer to the root node of the tree to measure height
 * Return: heght of the tree, 0 if the tree is NULL
 */
int determine_height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + determine_height(tree->left) : 1;
		r = tree->right ? 1 + determine_height(tree->right) : 1;
	}
	return ((l > r) ? l : r);
}
