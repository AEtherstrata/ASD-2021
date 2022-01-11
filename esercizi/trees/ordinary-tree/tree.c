#include "tree.h"

void print_tree_ric(tree t)
{
	printf("%d:", t->data);

	node* i = t->first;
	while (i != NULL) {
		printf(" -> %d", i->data);
		i = i->next;
	}
	printf("\n");
	
	i = t->first;
	while (i != NULL) {		
		print_tree(i);	
		i = i->next;
	}
}

void print_tree(tree t)
{
	if (is_empty(t)){
		printf("Empty tree!\n\n");
		return;
	} 
	print_tree_ric(t);
}

node* allocate_node(int v)
{
	node* newNode = (node*)calloc(1, sizeof(node));
	newNode->parent = NULL;
	newNode->first = NULL;
	newNode->next = NULL;
	newNode->data = v;
	return newNode;
}

void set_root(tree* t, int v)
{
	node* newNode = allocate_node(v);
	*t = newNode;
	printf("New rooted tree initialized with value: %d\n", newNode->data);
}

int is_empty(tree t)
{
	return t == NULL;
}

node* add_child(node* n, int v)
{
	if (is_empty(n))
	{
		printf("%d cannot be added: invalid parent node!\n");
		exit(1);
	}

	node* newNode = allocate_node(v);
	newNode->parent = n;
	newNode->next = n->first;
	n->first = newNode;
	return newNode;
}