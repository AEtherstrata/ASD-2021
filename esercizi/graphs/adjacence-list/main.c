#include "graph.h"

int main()
{
	graph* test = new_graph(10);

	add_not_oriented_edge(test, 2, 6);
	add_oriented_edge(test, 1, 9);
	add_not_oriented_edge(test, 5, 7);
	add_not_oriented_edge(test, 5, 3);
	add_oriented_edge(test, 5, 5);		// Comment this to make the graph simple		
	add_oriented_edge(test, 5, 8);

	print_graph(test);

	printf("Exit rank of 5: %d\n", exit_rank(test, 5));
	printf("Entry rank of 5: %d\n", entry_rank(test, 5));
	printf("Average exit rank: %.2f\n", average_exit_rank(test));
	printf("Is simple: %d\n", is_simple(test));
	printf("Edge between 5 and 3: %d\n", check_for_edge(test, 5, 3));
	printf("Edge between 1 and 9: %d\n", check_for_edge(test, 1, 9));
	printf("Edge between 6 and 2: %d\n", check_for_edge(test, 6, 2));
	printf("Edge between 8 and 5: %d\n", check_for_edge(test, 8, 5));
	return 0;
}