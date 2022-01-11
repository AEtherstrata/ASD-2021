#include "tree.h"

void print_tree_ric(tree t, int space)
{
	if(t == NULL) return;

	space += WIDTH;

	print_tree_ric(t->right, space);

	printf("\n");
	for (int i = WIDTH; i < space; i++)	{
		printf(" ");
	}
	printf("%d\n", t->data);

	print_tree_ric(t->left, space);
}

void print_tree(tree t)
{
	print_tree_ric(t, 0);
	printf("\n");
}

node* allocate_node(int v)
{
	node* newNode = (node*)calloc(1, sizeof(node));
	newNode->parent = NULL;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->data = v;
	return newNode;
}

void set_root(tree* t, int v)
{
	node* newNode = allocate_node(v);
	*t = newNode;
	printf("New rooted tree initialized with value: %d\n", newNode->data);
	print_tree(*t);
}

node* add_left(node* n, int v)
{
	if(n->left != NULL) {
		printf("Left node is already present -> %d\n", n->left->data);
		exit(1);
	}

	node* leftNode = allocate_node(v);
	leftNode->parent = n;
	n->left = leftNode;
	printf("Left node has been added: %d -> %d\n", n->data,  n->left->data);
	print_tree(root(n));
	return leftNode;
} 

node* add_right(node* n, int v)
{
	if(n->right != NULL) {
		printf("Right node is already present! %d -> %d\n", n->data, n->right->data);
		exit(1);
	}

	node* rightNode = allocate_node(v);
	rightNode->parent = n;
	n->right = rightNode;
	printf("Right node has been added: %d -> %d\n", n->data, n->right->data);
	print_tree(root(n));
	return rightNode;
} 

int only_left(tree t)
{
	if (is_empty(t)) return 1;	

	if (t->right != NULL) printf("%d has a right child!\n", t->data);

	return only_left(t->left) && only_left(t->right) && (t->right == NULL);
}

int only_right(tree t)
{
	if (is_empty(t)) return 1;

	if (t->left != NULL) printf("%d has a left child!\n", t->data);

	return only_right(t->left) && only_right(t->right) && (t->left == NULL);
}

int two_children(node* n)
{
	return n->right != NULL & n->left != NULL;
}

int is_empty(tree t)
{
	return t == NULL;
}

node* root(node* n)
{
	if(is_empty(n)) {
		printf("Empty tree!\n");
		exit(1);
	}

	if (n->parent == NULL) return n;
	
	root(n->parent);
}