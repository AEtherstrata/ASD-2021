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
	add_oriented_edge(test, 5, 5);		// Comment this to make the graph simple
	add_oriented_edge(test, 5, 8);

	//add_not_oriented_edge(test, 10, 2);

	printf("\n");
	print_graph(test);

	printf("Exit rank of 5: %d\n", exit_rank(test, 5));
	printf("Entry rank of 5: %d\n", entry_rank(test, 5));

	printf("Is simple: %d\n", is_simple(test));

	return 0;
}