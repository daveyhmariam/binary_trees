#include "binary_trees.h"


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not If tree is NULL, your function must return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h, s, sz_prfct;
	if (tree)
	{
		h = height(tree);
		s = _size(tree);
		sz_prfct = (int) (power(2, h + 1) - 1);
		return (sz_prfct == s ? 1 : 0);
	}
	return (0);
}

/**
 * height - determines the height of a tree
 * @tree: pointer to the root node of the tree to measure height
 * Return: heght of the tree, 0 if the tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + height(tree->left) : 0;
		r = tree->right ? 1 + height(tree->right) : 0;
	}
	return ((l > r) ? l : r);
}


/**
 * _size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: number of nodes (size) of binaary tree
 *			If tree is NULL, the function must return 0
 */

int _size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size += _size(tree->left);
	size += _size(tree->right);
	size++;
	return (size);
}


/**
 * power - calculates the exponential
 * @base: base of expression
 * @exponent: exponent of expression
 * Return: the exponential value
 */

double power(double base, int exponent)
{
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1.0 / power(base, -exponent);
    }
}
