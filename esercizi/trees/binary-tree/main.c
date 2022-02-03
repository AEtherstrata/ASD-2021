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

	symmetrical_parenthetical(testTree);
	preorder_parenthetical(testTree);
	printf("Two children node count: %d\n", two_children_count(testTree));
	printf("Four grandchildren node count: %d\n", four_grandchildren_count(testTree));
	printf("Parent of %d: %d\n", lr->data, parent(testTree, lr)->data);
	printf("Only left: %d\n", only_left(testTree));
	printf("Only right: %d\n\n", only_right(testTree));
	
	printf("150 is present (POST): %d\n\n", traversal_postorder(testTree, 150));
	printf("150 is present (PRE): %d\n\n", traversal_preorder(testTree, 150));
	printf("150 is present (SYM): %d\n\n", traversal_inorder(testTree, 150));
	printf("150 is present (BIN): %d\n\n", binary_search(testTree, 150));

	printf("Node count: %d\n", count(testTree));
	printf("Tree height: %d\n", height(testTree));
	printf("The tree is a path: %d\n", is_path(testTree));
	printf("Sum of values: %d\n", sum(testTree));
	printf("Average value: %f\n", average(testTree));
	printf("Is complete: %d\n\n", is_complete(testTree));	
	
	printf("Trunk height to 1...\n");
	trunk_height(&testTree, 1);
	print_tree(testTree);

	tree test2 = NULL;
	set_root(&test2, 16);

	node* l1 = add_left(test2, 8);
	node* l2 = add_left(l1, 4);
	node* l3 = add_left(l2, 2);
	node* r3 = add_right(l2, 6);
	node* lr3 = add_left(r3, 5);
	node* rr3 = add_right(r3, 7);
	node* l4 = add_left(l3, 1);
	node* r4 = add_right(l3, 3);
	
	symmetrical_parenthetical(test2);
	preorder_parenthetical(test2);

	printf("Only left: %d\n", only_left(test2));
	printf("Only right: %d\n\n", only_right(test2));

	printf("Two children node count: %d\n", two_children_count(test2));
	printf("Four grandchildren node count: %d\n", four_grandchildren_count(test2));
	printf("Node count: %d\n", count(test2));
	printf("Tree height: %d\n", height(test2));
	printf("The tree is a path: %d\n", is_path(test2));	
	printf("Sum of values: %d\n", sum(test2));
	printf("Average value: %f\n", average(test2));
	printf("Is complete: %d\n", is_complete(test2));
	printf("Parent of %d: %d\n\n", l4->data, parent(test2, l4)->data);
	print_list(path(test2, r4));
	printf("Relatedness of %d and %d: %d\n\n", l4->data, rr3->data, relatedness(test2, l4, rr3));
	
	tree testCopy = copy_tree(test2);
	print_tree(testCopy);

	tree test3 = NULL;
	print_tree(test3);
	printf("Node count: %d\n", count(test3));
	printf("Tree height: %d\n", height(test3));
	printf("The tree is a path: %d\n", is_path(test3));	
	printf("Sum of values: %d\n", sum(test3));
	printf("Average value: %f\n", average(test3));
	printf("Is complete: %d\n\n", is_complete(test3));
	
	set_root(&test3, 3);

	node* _3l = add_left(test3, 3);
	node* _3ll = add_left(_3l, 3);
	node* _3lll = add_left(_3ll, 3);
	node* _3llll = add_left(_3lll, 3);
	printf("Count of nodes that have same value as grandparent: %d\n", same_as_grandparent(test3));

	tree test4 = NULL;
	set_root(&test4, 0);
	node* _4l = add_left(test4, 1);
	node* _4ll = add_left(_4l, 2);
	node* _4lll = add_left(_4ll, 3);
	node* _4llll = add_left(_4lll, 3);
	print_tree(test4);
	printf("Number of nodes that have their data equal to their height: %d\n", height_as_info(test4));

	printf("Press enter to continue ");
	getchar();

	return 0;
}