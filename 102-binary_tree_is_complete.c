#include "binary_trees.h"


/**
 * binary_tree_is_complete - checkes if a binary tree is complete
 * @tree: pointer to root node
 * Return: 1 if complete, 0 if not or tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int s;

	if (!tree)
		return (0);
	s = _size((binary_tree_t *) tree);
	return (check_complete((binary_tree_t *) tree, 0, s));
}


/**
 * check_complete - checkes the tree if complete and returns value
 * @tree: root to binary tree
 * @idx: index of the node
 * @s: size of the whole tree
 * Return: 1 if tree is complete, 0 if not
 */

int check_complete(binary_tree_t *tree, int idx, int s)
{
	if (tree == NULL)
		return (1);
	if (idx >= s)
		return (0);
	return (check_complete(tree->left, (2 * idx) + 1, s)
			&& check_complete(tree->right, (2 * idx) + 2, s));
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
