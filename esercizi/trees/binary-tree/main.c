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

	printf("Only left: %d\n", only_left(testTree));
	printf("Only right: %d\n", only_right(testTree));
	
	printf("Press enter to continue ");
	getchar();

	return 0;
}