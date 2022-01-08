#include "list.h"

int main()
{
	list* testList = new_list(10);

	// Add some test values
	insert(testList, 99);
	insert(testList, 79);
	add(testList, 39);
	insert(testList, 59);
	add(testList, 19);
	insert(testList, 29);
	add(testList, 49);
	delete_index(testList, 2);
	delete_index(testList, 6);
	add(testList, 89);
	delete_value(testList, 99);
	insert(testList, 69);

	print_list(testList);

	return 0;
}