#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

#include "object.h"

treeNode* allocate_node(node* node);

int is_empty(treeNode* tree);

void add_child(treeNode* parent, node* node);

void print_tree_ric(treeNode* tree);

void print_tree(treeNode* tree);

void set_root(treeNode** treePointer, node* node);

#endif