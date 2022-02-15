#include "bst.h"

void print_array(int * a, int len)
{
	printf("{");
	if(len>0){
		for(int i=0; i<len-1; i++)
			printf(" %d,", a[i]);
		printf(" %d ", a[len-1]);
	}
	printf("}\n");
}

void print_tree_ric(bst t, int space)
{
	if(t == NULL) return;

	space += WIDTH;

	print_tree_ric(t->right, space);

	printf("\n");
	for (int i = WIDTH; i < space; i++)	{
		printf(" ");
	}
	printf("%d\n", t->key);

	print_tree_ric(t->left, space);
}

void print_tree(bst t)
{
	if(is_tree_empty(t)) {
		printf("Empty tree!\n");
		return;
	}
	print_tree_ric(t, 0);
	printf("\n");
}

void symmetrical_parenthetical_ric(bst t)
{
	if (is_tree_empty(t)) return;
	
	if(is_leaf(t)) {
		printf(" ()%d() ", t->key);
		return;
	}
	printf("(");
	symmetrical_parenthetical_ric(t->left);
	printf("%d", t->key);
	symmetrical_parenthetical_ric(t->right);
	printf(")");
}

void preorder_parenthetical_ric(bst t)
{
	if (is_tree_empty(t)) return;

	if(is_leaf(t)) {
		printf(" ()%d() ", t->key);
		return;
	}
	printf("(");
	printf("%d", t->key);	
	preorder_parenthetical_ric(t->left);
	preorder_parenthetical_ric(t->right);
	printf(")");
}

void symmetrical_parenthetical(bst t){
	symmetrical_parenthetical_ric(t);
	printf("\n");
}

void preorder_parenthetical(bst t){
	preorder_parenthetical_ric(t);
	printf("\n");
}

bstNode* allocate_bst_node(int k)
{
	bstNode* newBst = (bstNode*)malloc(sizeof(bstNode));
	newBst->parent = NULL;
	newBst->left = NULL;
	newBst->right = NULL;
	newBst->key = k;
	return newBst;
}

int is_tree_empty(bst t)
{
	return t == NULL;
}

int is_leaf(bst t)
{
	return ((t->left == NULL) && (t->right == NULL));
}

int height(bst t)
{
	if(is_tree_empty(t)) return -1;

	int l = height(t->left);
	int r = height(t->right);
	int max = (l > r) ? l : r;

	return max + 1;
}

int tree_insert(bst* t, bstNode* p, int k)
{
	if ( (*t) == NULL ) //tree is empty, creating the first node
	{
		(*t) = allocate_bst_node(k);
		(*t)->parent = p;
		return 1;
	}

	if ( (*t)->key == k ) //k is already part of the tree
	{
		return 0; //do nothing
	}
	
	if ( (*t)->key > k)
	{
		return tree_insert( &(*t)->left, (*t), k);
	} 
	else 
	{
		return tree_insert( &(*t)->right, (*t), k);
	}
}

int add_new_key(bst* t, int k)
{
	return tree_insert(t, NULL, k);
}

int node_count(bst t)
{
	if (t == NULL)
	{
		return 0;
	}

	return 1 + node_count(t->left) + node_count(t->right);
}

// Returns 1 if the array is sorted, 0 otherwise
int is_sorted(int* a, int len)
{
	if (len <= 1) return 1;
	for (int i = 0; i < len-1; i++)
	{
		if (a[i] > a[i+1])
		{
			return 0;
		}
	}
	return 1;
}

bstNode* bst_minimum_key(bst t)
{
	while(t->left != NULL)
		t = t->left;
	
	return t;
}

bstNode* bst_maximum_key(bst t)
{
	while(t->right != NULL)
		t = t->right;
	
	return t;
}

// theta: 1
// x has at most 1 child
void bst_bypass(bst t, bst x)
{
	bstNode* child = NULL;

	// Store the child
	child = (x->left != NULL) ? x->left : x->right;
	
	// Point it to the grandparent
	if (child != NULL) {
		child->parent = x->parent;
	}
	

	if (x->parent != NULL) {
		if (x == x->parent->left) {
			x->parent->left = child;
		}
		else {
			x->parent->right = child;
		}
	}
	else {
		t = child;
	}
}

//theta: h
void bst_delete_key(bst t, bstNode* k)
{
	if (k == NULL)
	{
		printf("Tried to delete a NULL node pointer! Exiting...\n");
		exit(1);
	}
	
	bstNode* x = NULL;
	printf("Deleting %d\n", k->key);
	if (k->left != NULL && k->right != NULL)
	{
		x = bst_minimum_key(k->right);
		printf("It has two children. The minimum of the right subtree is %d\n", x->key);
		k->key = x->key;
	}
	else 
	{
		x = k;
	}
	bst_bypass(t, x);
}

bstNode* iterative_bst_search(bst t, int k)
{
	while (t != NULL && k != t->key)
	{
		t = (k < t->key) ? t->left : t->right;
	}
	return t;
}

bstNode* recursive_bst_search(bst t, int k)
{
	if (t == NULL || t->key == k)
		return t;
	
	if (k < t->key)
	{
		return recursive_bst_search(t->left, k);
	}
	else
	{
		return recursive_bst_search(t->right, k);
	}
}

int tree_to_array(int* a, int len, bst t, int i)
{
	if (t == NULL)
		return i;
	
	i = tree_to_array(a, len, t->left, i);
	a[i] = t->key;
	i = tree_to_array(a, len, t->right, ++i);
	
	return i;
}

int bst_sorted(bst t)
{
	int len = node_count(t);
	int a[len];
	tree_to_array(a, len, t, 0);
	return is_sorted(a, len);
}

int not_higher(bst t, int k)
{
	if (t == NULL) return 1;
	else return(t->key <= k 
				&& not_higher(t->left, k)
				&& not_higher(t->right, k));
}

int not_lower(bst t, int k)
{
	if (t == NULL) return 1;
	else return(t->key >= k 
				&& not_lower(t->left, k)
				&& not_lower(t->right, k));
}

/*
	Worst case = the tree is a path -> theta: n

		- Master Theorem is not applicable
		T(n) = T(n-1) + theta(n)

		Sum of theta(n) = n -> T(n) = [[ theta(n^2) ]]
*/

int is_bst_pre(bst t)
{
	if (t == NULL) return 1;
	
	else return(not_higher(t->left, t->key)
				&& not_lower(t->right, t->key)
				&& is_bst_pre(t->left)
				&& is_bst_pre(t->right));
}

/*
	In the postorder search the subtrees get processed before the parent.
	This enables passing min and max values to the parent when it gets processed.

	[[ theta: n ]]
*/

treeInfo* is_bst_post(bst t)
{
	if (t == NULL) return NULL;

	treeInfo* result = (treeInfo*)malloc(sizeof(treeInfo));

	treeInfo* l = is_bst_post(t->left);		// O(n)
	treeInfo* r = is_bst_post(t->right);	// O(n)

	// from this line forward this is all O(1)
	if (l == NULL && r == NULL)
	{
		/*
		printf("Found a leaf with value: %d\n", t->key);
		if (t->parent != NULL) {
			printf("Leaf's parent: %d\n", t->parent->key);
		}
		*/
		result->is_bst = 1;
		result->max = t->key;
		result->min = t->key;
		//printf("[POST] Tree is a bst: %d\n       Tree max value: %d\n       Tree min value: %d\n\n", result->is_bst, result->max, result->min);
		return result;
	}

	if (l == NULL && r != NULL)
	{
		result->is_bst = r->is_bst && (t->key < r->min);
		result->max = r->max;
		result->min = t->key;
		//printf("Found a node with value: %d\n", t->key);
		//printf("[POST] Tree is a bst: %d\n       Tree max value: %d\n       Tree min value: %d\n\n", result->is_bst, result->max, result->min);
		return result;
	}
	
	if (l != NULL && r == NULL)
	{
		result->is_bst = l->is_bst && (t->key > l->max);
		result->max = t->key;
		result->min = l->min;
		//printf("Found a node with value: %d\n", t->key);
		//printf("[POST] Tree is a bst: %d\n       Tree max value: %d\n       Tree min value: %d\n\n", result->is_bst, result->max, result->min);
		return result;
	}
	
	result->is_bst = l->is_bst && r->is_bst && t->key > l->max && t->key < r->min;
	result->max = r->max;
	result->min = l->min;
	//printf("Found a node with value: %d\n", t->key);
	//printf("[POST] Tree is a bst: %d\n       Tree max value: %d\n       Tree min value: %d\n\n", result->is_bst, result->max, result->min);

	return result;
}

int tree_sort(int* a, int len)
{
	if (len <= 1) return 1; //A single element array is always ordered.

	bst tempTree = NULL;

	printf("Original -> ");
	print_array(a, len);

	for (int i = 0; i < len; i++) {
		add_new_key(&tempTree, a[i]);
	}

	for (int i = 0; i < len; i++) {
		tree_to_array(a, len, tempTree, 0);
	}

	printf("Sorted ---> ");
	print_array(a, len);

	return is_sorted(a, len);
}