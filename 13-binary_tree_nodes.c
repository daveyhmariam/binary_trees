#include "binary_trees.h"


/**
 * binary_tree_nodes - counts the nodes with
 *						at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of non leaf nodes, If tree is NULL,
 *			the function must return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t non_leaf = 0;
	if (tree)
	{
		non_leaf += (tree->left || tree->right) ? 1 : 0;
		non_leaf += binary_tree_nodes(tree->left);
		non_leaf += binary_tree_nodes(tree->right);
		return (non_leaf);
	}
	return (0);
}
