#include "list.h"

int main()
{
	list* test1 = new_list();
	list* test2 = new_list();
	list* test3 = new_list();

	insert_ordered(test1, 9);
	insert_ordered(test1, 39);
	insert_ordered(test1, 89);
	insert_ordered(test1, 59);
	insert_ordered(test1, 29);
	insert_ordered(test1, 49);
	insert_ordered(test1, 79);
	insert_ordered(test1, 69);
	print_list(test1);


	test2 = reverse(test1);
	print_list(test2);

	test2 = sort(test2);
	print_list(test2);

	test3 = merge(test1, test2);
	print_list(test3);
	// Insert test code here

	printf("Press enter to continue ");
	getchar();

	return 0;
}