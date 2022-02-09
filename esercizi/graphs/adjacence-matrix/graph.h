#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct GRAPH 
{
	int 		n;			// Number of nodes
	int**		matrix;		// Adjacence matrix

} graph;

// Create a new graph with specified node count
graph* new_graph(int size);

// Print the matrix to console
void print_graph(graph* graph);

// Add an edge between two nodes
void add_oriented_edge(graph* graph, int node1, int node2);

// Add an edge between two nodes both ways
void add_not_oriented_edge(graph* g, int n1, int n2);

// Resize the graph when more nodes need to be stored
graph* resize_matrix(graph* graph, int new_size);

// Get the exit rank of a node
int exit_rank(graph* graph, int node);

// Get the entry rank of a node
int entry_rank(graph* graph, int node);

// Check if the graph is a simple graph (has no loops)
int is_simple(graph* graph);

#endif