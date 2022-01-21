#include "heap.h"

int main()
{
	heap* test = new_heap(10);
	insert(test, 45);
	insert(test, 65);
	insert(test, 48);
	insert(test, 86);
	insert(test, 32);
	insert(test, 99);
	insert(test, 24);
	print_heap(test);
	return 0;
}