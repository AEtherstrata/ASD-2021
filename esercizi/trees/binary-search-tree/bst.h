#ifndef _BST_H
#define _BST_H

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5

typedef struct SEARCH_NODE
{
	struct SEARCH_NODE*		parent;
	struct SEARCH_NODE*		right;
	struct SEARCH_NODE*		left;
	int						key;
//	value field
} bstNode;

typedef struct TREE_INFO
{
	int 					is_bst;
	int						min;
	int						max;
}treeInfo;

typedef bstNode* bst;

void print_array(int * a, int len);

void print_tree_ric(bst tree, int space);

void print_tree(bst tree);

void symmetrical_parenthetical_ric(bst tree);

void symmetrical_parenthetical(bst tree);

void preorder_parenthetical_ric(bst tree);

void preorder_parenthetical(bst tree);

bstNode* allocate_bst_node(int key);

int is_tree_empty(bst t);

int is_leaf(bst t);

int tree_insert(bst* t, bstNode* p, int k);

int add_new_key(bst* t, int k);

int node_count(bst tree);

bstNode* bst_minimum_key(bst tree);

bstNode* bst_maximum_key(bst tree);

void bst_bypass(bst tree, bst node);

void bst_delete_key(bst tree, bstNode* key);

bstNode* iterative_bst_search(bst tree, int key);

bstNode* recursive_bst_search(bst tree, int key);

int tree_to_array(int* array, int length, bst tree, int index);

int bst_sorted(bst tree);

int not_higher(bst t, int k);

int not_lower(bst t, int k);

int is_bst_pre(bst t);

treeInfo* is_bst_post(bst t);

int tree_sort(int* a, int len);

#endif