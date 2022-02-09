#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "../../lists/doubly-linked/list.h"

typedef struct GRAPH 
{
	int 			n;			// Number of nodes
	list**		edgeList;		// Adjacence list

} graph;

// Create a new graph with specified node count
graph* new_graph(int size);

// Print the matrix to console
void print_graph(graph* graph);

void print_source_well_prop(int* a, int len);

void add_not_oriented_edge(graph* graph, int n1, int n2);

void add_oriented_edge(graph* graph, int n1, int n2);

int exit_rank(graph* graph, int node);

int entry_rank(graph* graph, int node);

float average_exit_rank(graph* graph);

int is_simple(graph* graph);

int check_for_edge(graph* graph, int node1, int node2);

int check_all_not_oriented(graph* g);

int is_well(graph* g, int n);

int is_source(graph* g, int n);

int* create_source_well_list(graph* g);

int check_union_for_edge(graph* g1, graph* g2, int n1, int n2);

int check_union_all_pairs(graph* g1, graph* g2);

int check_for_complementary_nodes(graph* g1, graph* g2);

#endif