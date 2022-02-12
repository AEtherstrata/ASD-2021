#include "tree.h"

treeNode* allocate_node(node* n)
{
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));

	node->info = n;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int is_empty(treeNode* t)
{
	return t == NULL;
}

void add_child(treeNode* p, node* n)
{
	if (is_empty(p))
	{
		printf("%d cannot be added: invalid parent node!\n");
		exit(1);
	}

	treeNode* newNode = allocate_node(n);

	newNode->parent = p;
	newNode->right = p->left;

	p->left = newNode;
}

void print_tree_ric(treeNode* t)
{
	printf("%d:", t->info->id);

	treeNode* i = t->left;
	while (i != NULL) {
		printf(" -> %d", i->info->id);
		i = i->right;
	}
	printf("\n");
	
	i = t->left;
	while (i != NULL) {		
		print_tree(i);	
		i = i->right;
	}
}

void print_tree(treeNode* t)
{
	if (is_empty(t)){
		printf("Empty tree!\n\n");
		return;
	} 
	print_tree_ric(t);
}

void set_root(treeNode** t, node* n)
{
	treeNode* newNode = allocate_node(n);
	*t = newNode;
}