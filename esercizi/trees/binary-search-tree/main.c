#include "bst.h"

void add_key(bst* t, int k)
{
	int status = add_new_key(t, k);
	if (status)
	{
		printf("%d was added to the tree.\n\n", k);
		print_tree(*t);
	}	
	else
	{
		printf("%d is already part of the tree.\n\n", k);
		print_tree(*t);
		exit(1);
	}
}

void verify_bst(bst t)
{
	printf("Initializing postorder check\n");

	if (t == NULL)
	{
		printf("The tree is empty! Exiting...\n");
		exit(1);
	}

	printf("Found tree with root: %d\n", t->key);
	treeInfo* result = is_bst_post(t);

	printf("[POST] Tree is a bst: %d\n       Tree max value: %d\n       Tree min value: %d\n\n", result->is_bst, result->max, result->min);
}

int main()
{
	bst t1 = NULL;

	add_key(&t1, 65);
	add_key(&t1, 47);
	add_key(&t1, 35);
	add_key(&t1, 88);
	add_key(&t1, 85);
	add_key(&t1, 74);
	add_key(&t1, 81);
	add_key(&t1, 22);
	add_key(&t1, 44);
	add_key(&t1, 53);
	add_key(&t1, 95);	
	add_key(&t1, 89);

	int array[12] = {65,47,35,88,85,74,81,22,44,53,95,89};

	bst_delete_key(t1, iterative_bst_search(t1, 47));
	printf("Deleted 47 from tree.\n\n");
	print_tree(t1);

	if (is_bst_pre(t1))
	{
		printf("[PRE] This tree is a binary search tree.\n\n");
	}
	else
	{
		printf("[PRE] This tree is NOT a binary search tree.\n\n");
	}

	verify_bst(t1);

	if (tree_sort(array, 12)){
		printf("Tree sort OK\n\n");
	} else {
		printf("Tree sort BAD\n\n");
	}

	printf("Tree height: %d\n", height(t1));
	printf("Path length of 22 is: %d\n", path_length(t1, 22));
	printf("Parent array of 22:\n");
	print_array(parent_array(t1, 22), path_length(t1, 22));

	printf("Press enter to continue ");
	getchar();

	return 0;
}