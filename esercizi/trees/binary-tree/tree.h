#ifndef _TREE_H
#define _TREE_H

#define WIDTH 5

#include <stdio.h>
#include <stdlib.h>

#include "../../lists/doubly-linked/list.h"

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

void symmetrical_parenthetical_ric(tree tree);

void symmetrical_parenthetical(tree tree);

void preorder_parenthetical_ric(tree tree);

void preorder_parenthetical(tree tree);

node* allocate_node(int value);

void set_root(tree* tree, int value);

void dealloc(tree* tree);

void trunk(tree* tree, node* node);

void trunk_height(tree* tree, int height);

node* add_left(node* node, int value);

node* add_right(node* node, int value);

int only_left(tree tree);

int only_right(tree tree);

int has_grandparent(node* node);

int two_children(node* node);

int two_children_count(tree t);

int four_grandchildren(node* n);

int four_grandchildren_count(tree t);

int same_as_grandparent(tree tree);

int is_tree_empty(tree tree);

node* root(node* node);

node* right(node* node);

node* left(node* node);

node* parent(tree tree, node* node);

int traversal_preorder(node* node, int value);

int traversal_postorder(node* node, int value);

int traversal_inorder(node* node, int value);

int binary_search(tree tree, int value);

int count(tree tree);

int is_path(tree tree);

int is_leaf(tree tree);

int is_complete(tree tree);

int height(tree tree);

int sum(tree tree);

float average_bad(tree tree);

void average_ric(tree t, int* s, int* c);

float average(tree t);

list* path(tree tree, node* node);

int relatedness(tree t, node* n1, node* n2);

tree copy_tree(tree t);

void height_as_info_ric(tree t, int* c, int h);

int height_as_info(tree t);

#endif
