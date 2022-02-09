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

void add_not_oriented_edge(graph* graph, int n1, int n2);

void add_oriented_edge(graph* graph, int n1, int n2);

int exit_rank(graph* graph, int node);

int entry_rank(graph* graph, int node);

float average_exit_rank(graph* graph);

int is_simple(graph* graph);

int check_for_edge(graph* graph, int node1, int node2);

#endif