#include "graph.h"

int main()
{
	graph* test = new_graph();

	print_graph(test);
	printf("\n\n");

	node* nodes[10];  // I'll just store the pointers to objects in an array
	edge* edges[10];

	nodes[0] = add_node(test, 69);
	nodes[1] = add_node(test, 34);
	nodes[2] = add_node(test, 727);	
	nodes[3] = add_node(test, 10);
	nodes[4] = add_node(test, 44);
	nodes[5] = add_node(test, 21);
	nodes[6] = add_node(test, 1);
	nodes[7] = add_node(test, 15);

	edges[0] = add_edge(test, 5, nodes[2], nodes[0]);
	edges[1] = add_edge(test, 15, nodes[6], nodes[7]);
	edges[2] = add_edge(test, 65, nodes[3], nodes[4]);
	edges[3] = add_edge(test, 77, nodes[3], nodes[0]);
	edges[4] = add_edge(test, 21, nodes[5], nodes[1]);
	edges[5] = add_edge(test, 62, nodes[2], nodes[1]);
	edges[6] = add_edge(test, 59, nodes[0], nodes[6]);
	edges[7] = add_edge(test, 32, nodes[4], nodes[4]);
	edges[8] = add_edge(test, 11, nodes[1], nodes[5]);
	edges[9] = add_edge(test, 99, nodes[7], nodes[6]);

	print_graph(test);

	printf("The graph is connected: %d\n", bfs_connected(test));
	printf("Number of components: %d\n", bfs_component_count(test));

	print_tree(parent_array(test));

	return 0;
}