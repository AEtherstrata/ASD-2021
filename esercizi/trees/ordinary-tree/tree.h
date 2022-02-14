#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_STRUCT 
{
	struct NODE_STRUCT*		parent;		// Parent of the current node
	struct NODE_STRUCT*		first;		// Left-most sibling node (and first child)
	struct NODE_STRUCT*		next; 		// Right sibling of the current node
	int						data;		// Data stored in the node
} node;

typedef node* tree;

void print_tree_ric(tree t);

void print_tree(tree t);

void print_array(int* a, int len);

node* allocate_node(int v);

void set_root(tree* tree, int value);

int is_empty(tree t);

node* add_child(node* node, int value);

node* add_sibling(node* node, int value);

int height(tree t);

void nodes_depth_count(tree t, int h, int* a);

int* count_nodes_foreach_depth_level(tree t, int h);

#endif