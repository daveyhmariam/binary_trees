#include "binary_trees.h"


/**
 * binary_tree_levelorder - goes through a binary tree in level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *			The value in the node must be passed as a
 *			parameter to this function.
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *cur;
	int s, front = 0, end = 0;


	s = _size(tree);
	queue = (binary_tree_t **) malloc(sizeof(binary_tree_t *) * s);
	queue[end++] = (binary_tree_t *) tree;
	while (front < end)
	{
		cur = queue[front++];
		func(cur->n);
		if (cur->left)
			queue[end++] = cur->left;
		if (cur->right)
			queue[end++] = cur->right;
	}
	free(queue);

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