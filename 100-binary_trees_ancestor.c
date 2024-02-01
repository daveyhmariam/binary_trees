#include "binary_trees.h"


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: return a pointer to the lowest common
			ancestor node of the two given nodes
 *			If no common ancestor was found, your function must return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	int d1, d2;
	binary_tree_t *f, *s;

	if (!first || !second)
		return (NULL);
	f = (binary_tree_t *) first;
	s = (binary_tree_t *) second;
	d1 = depth(f);
	d2 = depth(s);
	while (d1 - d2 != 0)
	{
		if (d1 - d2 > 0)
		{
			f = f->parent;
			d1--;
		}
		if (d1 - d2 < 0)
		{
			s = s->parent;
			d1++;
		}
	}

	if (f == s)
		return (f);
	while (f != s)
	{
		f = f->parent;
		s = s->parent;
	}
	return (f);
}

/**
 * depth - function that measures
 *						the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of node, If tree is NULL, your function must return 0
 */

int depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + depth(tree->parent) : 0);
}
