#include "tree.h"

int main()
{
	tree test = NULL;
	set_root(&test, 1);

	node* t1 = add_child(test, 10);
	node* t2 = add_child(test, 20);
	node* g1 = add_child(t1, 110);
	node* g2 = add_child(t2, 220);
	print_tree(test);

	return 0;
}