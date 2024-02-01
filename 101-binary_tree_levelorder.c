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
	queue_t *front, *end;
	binary_tree_t *tmp;

	if (tree)
	{
		enqueue((binary_tree_t *)tree, &end);
		front = end;
	}
	while (front)
	{
		tmp = front->node;
		dequeue(&front);
		func(tmp->n);
		if (tmp->left)
			enqueue(tmp->left, &end);
		if (tmp->right)
			enqueue(tmp->right, &end);
	}

}


/**
 * enqueue - adds nodes into queue
 * @node: binary tree node
 * @end: end of queue
 * Return: Nothing
 */
void enqueue(binary_tree_t *node, queue_t **end)
{
	queue_t *new;

	if (node == NULL)
		return;
	new = (queue_t *) malloc(sizeof(queue_t));
	if (new)
		new->node = node;
	new->next = NULL;
	new->prev = NULL;
	if (*end)
	{
		new->prev = *end;
		(*end)->next = new;
	}
	(*end) = new;
}


/**
 * dequeue - pops nodes out of queue
 * @front: front of queue
 * Return: Nothing
 */
void dequeue(queue_t **front)
{
	queue_t *_free;

	_free = (*front);
	(*front) = (*front)->next;
	free(_free);
}
