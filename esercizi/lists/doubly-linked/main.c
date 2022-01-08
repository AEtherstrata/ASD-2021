#include "list.h"

int main()
{
	list* test = new_list();

	print_list(test);

	add_head(test, 69);
	add_head(test, 64);
	add_tail(test, 45);
	add_tail(test, 17);
	add_head(test, 35);
	delete_head(test);
	add_tail(test, 50);
	add_head(test, 95);
	add_tail(test, 42);
	delete_head(test);
	delete_tail(test);
	print_list(test);
	empty(test);
	add_head(test, 69);
	add_head(test, 64);
	add_tail(test, 45);
	add_tail(test, 17);
	add_head(test, 35);
	delete_head(test);
	add_tail(test, 50);
	add_head(test, 95);
	add_tail(test, 42);
	delete_head(test);
	delete_tail(test);
	print_list(test);

	printf("Press enter to continue ");
	getchar();

	return 0;
}