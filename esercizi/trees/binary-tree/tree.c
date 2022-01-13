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
	if(is_empty(t)) {
		printf("Empty tree!\n");
		return;
	}
	print_tree_ric(t, 0);
	printf("\n");
}

void symmetrical_parenthetical_ric(tree t)
{
	if (is_empty(t)) return;
	
	if(is_leaf(t)) {
		printf(" ()%d() ", t->data);
		return;
	}
	printf("(");
	symmetrical_parenthetical_ric(t->left);
	printf("%d", t->data);
	symmetrical_parenthetical_ric(t->right);
	printf(")");
}

void preorder_parenthetical_ric(tree t)
{
	if (is_empty(t)) return;

	if(is_leaf(t)) {
		printf(" ()%d() ", t->data);
		return;
	}
	printf("(");
	printf("%d", t->data);	
	preorder_parenthetical_ric(t->left);
	preorder_parenthetical_ric(t->right);
	printf(")");
}

void symmetrical_parenthetical(tree t){
	symmetrical_parenthetical_ric(t);
	printf("\n");
}

void preorder_parenthetical(tree t){
	preorder_parenthetical_ric(t);
	printf("\n");
}

node* allocate_node(int v)
{
	node* newNode = (node*)malloc(sizeof(node));
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

void dealloc(tree* t)
{
	if(is_empty(*t)) return;

	dealloc(&(*t)->left);
	dealloc(&(*t)->right);

	free(*t);
	(*t) = NULL;
}

void trunk(tree* t, node* n)
{
	if((*t) == n) {
		dealloc(t);
		return;
	}

	if(n->parent->left == n) dealloc(&(n->parent->left));
	else if (n->parent->right == n) dealloc(&(n->parent->left));
}

void trunk_height(tree* t, int h)
{
	if (t == NULL) return;	
	if (h == -1) {
		dealloc (t);
		return;
	}

	trunk_height(&(*t)->left, h-1);
	trunk_height(&(*t)->right, h-1);
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

	if (t->right != NULL) {
		printf("%d has a right child!\n", t->data);
		return 0;
	}

	return (only_left(t->left));
}

int only_right(tree t)
{
	if (is_empty(t)) return 1;

	if (t->left != NULL) {
		printf("%d has a left child!\n", t->data);
		return 0;
	}

	return (only_right(t->right));
}

int has_grandparent(node* n){
	if (is_empty(n)) return 0;
	if (n->parent == NULL) return 0;
	if (n->parent->parent == NULL) return 0;

	return 1;
}

int two_children(node* n)
{
	return n->right != NULL & n->left != NULL;
}

int two_children_count(tree t)
{
	if (is_empty(t)) return 0;
	if (!two_children(t)) return 0;

	return two_children_count(t->left) + two_children_count(t->right) + 1;
}

int four_grandchildren(node* n)
{
	if (is_empty(n)) return 0;
	if (!two_children(n)) return 0;
	if (two_children(n->left) && two_children(n->right)) return 1;
	return 0;
}

int four_grandchildren_count(tree t)
{
	if (is_empty(t)) return 0;
	return four_grandchildren(t) + four_grandchildren_count(t->left) + four_grandchildren_count(t->right);
}

int same_as_grandparent(tree t){
	if (is_empty(t)) return 0;
	if (has_grandparent(t) && t->parent->parent->data == t->data)
		return same_as_grandparent(t->left) + same_as_grandparent(t->right) + 1;
	return same_as_grandparent(t->left) + same_as_grandparent(t->right);
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

node* right(node* n)
{
	return n->right;
}

node* left(node* n)
{
	return n->left;
}

node* parent(tree t, node* n)
{
	if(is_empty(t)) return NULL;

	if (t->right == n || t->left == n) return t;
	
	node* p = parent(t->left, n);

	if (p != NULL) return p;
	else return parent(t->right, n);
}

int traversal_preorder(node* n, int v)
{
	if(is_empty(n)) return 0;
			
	printf("%d has been processed.\n", n->data);
	if(n->data == v) return 1;
	
	if (traversal_preorder(n->left, v)) return 1;
	if (traversal_preorder(n->right, v)) return 1;

	return 0;
}

int traversal_postorder(node* n, int v)
{
	if(is_empty(n)) return 0;

	if (traversal_postorder(n->left, v)) return 1;
	if (traversal_postorder(n->right, v)) return 1;

	printf("%d has been processed.\n", n->data);
	if(n->data == v) return 1;

	return 0;
}

int traversal_inorder(node* n, int v)
{
	if(is_empty(n)) return 0;

	if (traversal_inorder(n->left, v)) return 1;

	printf("%d has been processed.\n", n->data);
	if(n->data == v) return 1;

	if (traversal_inorder(n->right, v)) return 1;

	return 0;
}

int binary_search(tree t, int v)
{
	if(is_empty(t)) return 0;
	
	printf("%d has been processed.\n", t->data);
	if(t->data == v) return 1;
	
	if (v < t->data) return binary_search(t->left, v);
	else return binary_search(t->right, v);

	return 0;
}

int count(tree t)
{
	if(is_empty(t)) return 0;
	return count(t->left) + count(t->right) + 1;
}

int is_path(tree t)
{
	if(is_empty(t)) return 1;
	if((is_path(t->right) && t->left == NULL) || (t->right == NULL && is_path(t->left))) return 1;
	return 0;
}

int is_leaf(tree t)
{
	return ((t->left == NULL) && (t->right == NULL));
}

int is_complete(tree t)
{
	if( t == NULL ) return 1;

	return height(t->left) == height(t->right);
}

int height(tree t)
{
	if(is_empty(t)) return -1;

	int l = height(t->left);
	int r = height(t->right);
	int max = 0;

	if (l > r) max = l;
	else max = r;

	return max + 1;	
}

int sum(tree t)
{
	if(is_empty(t)) return 0;
	return sum(t->right) + sum(t->left) + t->data;
}


float average_bad(tree t) {
   return ((float)sum(t))/count(t);
}

void average_ric(tree t, int* s, int* c)
{
	if(is_empty(t)) return;

	*s += t->data;
	*c = *c + 1;

	average_ric(t->left, s, c);
	average_ric(t->right, s, c);
}

float average(tree t)
{
	if(is_empty(t)) return 0;
	int sum=0, count=0;
	average_ric(t, &sum, &count);
	return ((float)sum)/count;
}