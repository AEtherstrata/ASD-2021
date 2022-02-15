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

void print_array(int* a, int len)
{
	if (len <= 0) {
		printf("Empty array!\n");
		return;
	}

	for (int i = 0; i < len; i++)
	{
		printf("[%d] = %d\n", i , a[i]);
	}
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

node* add_sibling(node* n, int v)
{
	if (is_empty(n))
	{
		printf("%d cannot be added: invalid sibling node!\n");
		exit(1);
	}

	node* newNode = allocate_node(v);
	newNode->parent = n->parent;
	newNode->next = n->next;
	n->next = newNode;

	return newNode;
}

int height(tree t)
{
	if (t == NULL) return -1;

	int l = height(t->first);

	int r = -1;
	tree s = t->next;

	while (s != NULL)
	{
		int rnew = height(s->first);
		r = (rnew > r) ? rnew : r;
		s = s->next;
	}	

	int max = (l > r) ? l : r;

	return max + 1;
}

int is_leaf(tree t)
{
	return (t->first == NULL);
}

int leaves_count(tree t)
{
	if (is_empty(t)) return 0;

	int count = 0;

	if (is_leaf(t)) count++;

	tree x = t->next;
	while (x != NULL)
	{		
		count += leaves_count(x);
		x = x->next;
	}
	
	return count + leaves_count(t->first);
}

void nodes_depth_count(tree t, int h, int* a)
{
	if (t == NULL) return;

	if (t->first == NULL && t->next == NULL) {
		a[h]++;
		return;
	}
	
	a[h]++;

	nodes_depth_count(t->first, h+1, a);

	tree s = t->next;
	while (s != NULL)
	{
		a[h]++;
		nodes_depth_count(s->first, h+1, a);
		s = s->next;
	}
}

int* count_nodes_foreach_depth_level(tree t, int h)
{
	int* count = (int*)calloc(h, sizeof(int));

	nodes_depth_count(t, 0, count);

	return count;
}