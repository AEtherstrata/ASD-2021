#ifndef _TREE_H
#define _TREE_H

#define WIDTH 5

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_STRUCT 
{
	struct NODE_STRUCT*		parent;
	struct NODE_STRUCT*		right;
	struct NODE_STRUCT*		left;
	int						data;
} node;

typedef node* tree;

void print_tree_ric(tree tree, int space);

void print_tree(tree tree);

node* allocate_node(int value);

void set_root(tree* tree, int value);

node* add_left(node* node, int value);

node* add_right(node* node, int value);

int only_left(tree tree);

int only_right(tree tree);

int two_children(node* node);

int is_empty(tree tree);

node* root(node* node);

node* right(node* node);

node* left(node* node);

int traversal_preorder(node* node, int value);

int traversal_postorder(node* node, int value);

int traversal_inorder(node* node, int value);

int count(tree tree);

int is_path(tree tree);

int height(tree tree);

int sum(tree tree);

float average_bad(tree tree);

void average_ric(tree t, int* s, int* c);

float average(tree t);

#endif