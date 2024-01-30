#include "binary_trees.h"


#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node
 *                            as the right-child of another node
 * @parent:  pointer to the node to insert the right-child in
 * @value: he value to store in the new node
 * Return:  pointer to the created node,
 *          or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (!node || !parent)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->right)
	{
		node->right = parent->right;
		node->right->parent = node;
	}
	parent->right = node;
	return (node);
}
