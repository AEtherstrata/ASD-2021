#include "graph.h"

int main()
{
	graph* test = new_graph(10);
	printf("New empty graph:\n");
	print_graph(test);

	add_not_oriented_edge(test, 2, 6);
	add_oriented_edge(test, 1, 9);
	add_not_oriented_edge(test, 5, 7);
	add_not_oriented_edge(test, 5, 3);
	add_oriented_edge(test, 5, 5);
	add_oriented_edge(test, 5, 8);

	printf("\n");
	print_graph(test);

	printf("Exit rank of 5: %d\n", exit_rank(test, 5));
	
	printf("Entry rank of 5: %d\n", entry_rank(test, 5));

	return 0;
}