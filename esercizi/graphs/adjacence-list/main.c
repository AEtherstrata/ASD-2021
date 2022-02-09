#include "graph.h"

int main()
{
	graph* test = new_graph(10);

	add_not_oriented_edge(test, 2, 6);
	add_oriented_edge(test, 1, 9);
	add_not_oriented_edge(test, 5, 3);
	add_oriented_edge(test, 5, 5);		// Comment this to make the graph simple		
	add_oriented_edge(test, 5, 8);
	add_oriented_edge(test, 2, 8);
	add_oriented_edge(test, 8, 1);
	add_oriented_edge(test, 7, 4);
	add_not_oriented_edge(test, 3, 4);
	add_not_oriented_edge(test, 6, 3);
	add_oriented_edge(test, 2, 0);

	print_graph(test);

	printf("Exit rank of 5: %d\n", exit_rank(test, 5));
	printf("Entry rank of 5: %d\n", entry_rank(test, 5));
	printf("Average exit rank: %.2f\n", average_exit_rank(test));
	printf("Is simple: %d\n\n", is_simple(test));

	printf("Edge between 5 and 3: %d\n", check_for_edge(test, 5, 3));
	printf("Edge between 1 and 9: %d\n", check_for_edge(test, 1, 9));
	printf("Edge between 6 and 2: %d\n", check_for_edge(test, 6, 2));
	printf("Edge between 8 and 5: %d\n\n", check_for_edge(test, 8, 5));

	printf("The graph is not oriented: %d\n", check_all_not_oriented(test));
	printf("9 is a well: %d\n", is_well(test, 9));
	printf("9 is a source: %d\n\n", is_source(test, 9));

	print_source_well_prop(create_source_well_list(test), test->n);
	printf("\n/- -- -- -- -- -- -- -- -- -/\n\n");

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	graph* test2 = new_graph(10);

	add_not_oriented_edge(test2, 0, 9);
	add_not_oriented_edge(test2, 2, 1);
	add_not_oriented_edge(test2, 2, 6);
	add_not_oriented_edge(test2, 7, 0);
	add_oriented_edge(test2, 4, 7);
	add_oriented_edge(test2, 8, 2);
	add_oriented_edge(test2, 1, 8);
	add_oriented_edge(test2, 9, 1);
	add_oriented_edge(test2, 8, 5);
	add_oriented_edge(test2, 8, 8);
	add_oriented_edge(test2, 1, 0);
	add_oriented_edge(test2, 4, 4);

	print_graph(test2);

	printf("Average exit rank: %.2f\n", average_exit_rank(test2));
	printf("Is simple: %d\n\n", is_simple(test2));

	printf("Check union for edges on every pair: %d\n", check_union_all_pairs(test, test2));

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	graph* test3 = new_graph(10);

	add_oriented_edge(test3, 0, 7);
	add_oriented_edge(test3, 9, 7);

	print_source_well_prop(create_source_well_list(test3), test3->n);

	printf("Check for complementary sources and wells: %d\n", check_for_complementary_nodes(test, test3));

	return 0;
}