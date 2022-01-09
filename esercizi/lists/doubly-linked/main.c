#include "list.h"

int main()
{
	list* test1 = new_list();
	list* test2 = new_list();
	list* test3 = new_list();

	add_tail(test1, 19);
	add_before(test1, search(test1, 19), 9);
	add_tail(test1, 29);
	add_tail(test1, 59);
	add_before(test1, search(test1, 59), 49);
	add_after(test1, search(test1, 59), 69);
	add_tail(test1, 79);
	add_tail(test1, 89);
	add_after(test1, search(test1, 29), 39);
	print_list(test1);

	test2 = reverse(test1);
	print_list(test2);

	list_enqueue(test1, test2);
	print_list(test1);

	// Insert test code here

	printf("Press enter to continue ");
	getchar();

	return 0;
}