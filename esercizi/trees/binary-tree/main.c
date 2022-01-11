#include "tree.h"

int main()
{
	tree testTree = NULL;

	set_root(&testTree, 100);

	node* l = add_left(testTree, 50);
	node* ll = add_left(l, 25);
	node* lr = add_right(l, 75);
	node* r = add_right(testTree, 150);
	node* rl = add_left(r, 125);
	node* rr = add_right(r, 175);

	printf("Only left: %d\n\n", only_left(testTree));
	printf("Only right: %d\n\n", only_right(testTree));
	
	printf("150 is present: %d\n\n", traversal_postorder(testTree, 150));
	printf("150 is present: %d\n\n", traversal_preorder(testTree, 150));
	printf("150 is present: %d\n\n", traversal_inorder(testTree, 150));

	printf("Node count: %d\n", count(testTree));
	printf("Tree height: %d\n", height(testTree));
	printf("The tree is a path: %d\n", is_path(testTree));
	printf("Sumof values: %d\n", sum(testTree));
	printf("Average value: %f\n\n", average(testTree));
	
	tree test2 = NULL;
	set_root(&test2, 16);

	node* l1 = add_left(test2, 8);
	node* l2 = add_left(l1, 4);
	node* l3 = add_left(l2, 2);
	node* l4 = add_left(l3, 1);
	
	printf("Node count: %d\n", count(test2));
	printf("Tree height: %d\n", height(test2));
	printf("The tree is a path: %d\n", is_path(test2));	
	printf("Sumof values: %d\n", sum(test2));
	printf("Average value: %f\n\n", average(test2));

	printf("Press enter to continue ");
	getchar();

	return 0;
}