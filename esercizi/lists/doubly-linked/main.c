#include "list.h"

int main()
{
	list* test1 = new_list();
	list* test2 = new_list();
	list* test3 = new_list();
	list* test4 = new_list();

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
	test1 = sort(test1);
	print_list(test1);
	print_list(test2);

	test3 = merge(test1, test2);
	print_list(test3);

	insert_ordered(test4, 9);
	insert_ordered(test4, 2);
	insert_ordered(test4, 0);
	insert_ordered(test4, 2);
	insert_ordered(test4, 5);
	insert_ordered(test4, 6);
	insert_ordered(test4, 4);
	insert_ordered(test4, 8);
	add_head(test4, 9);

	print_list(test4);
	printf("Last is equal to first value: %d\n", first_equals_last(test4));

	printf("Press enter to continue ");
	getchar();

	return 0;
}