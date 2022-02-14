#include "tree.h"

int main()
{
	tree test = NULL;
	set_root(&test, 1);

	node* t1 = add_child(test, 10);
	node* t2 = add_child(test, 20);
	node* g1 = add_child(t1, 110);
	node* g2 = add_child(t2, 220);
	node* ss4 = add_sibling(g2, 404);
	node* ss2 = add_sibling(g1, 300);

	print_tree(test);

	int h = height(test);

	printf("Height is: %d\n", h);

	printf("Node count for each depth level:\n");
	print_array(count_nodes_foreach_depth_level(test, h+1), h+1);

	return 0;
}