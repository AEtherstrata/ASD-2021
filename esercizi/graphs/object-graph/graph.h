#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* Forward declarations */

typedef struct NODE_STRUCT node;
typedef struct EDGE_STRUCT edge;

typedef struct NODE_LIST nodeList;
typedef struct EDGE_LIST edgeList;

/* * * * * * * * * * * */

/* Minimal implementation of a graph structure */

typedef struct NODE_STRUCT {

	int				id;
	int				color;
	edgeList*		edges;		// List of edges associated with this node
	nodeList*		pos;		// Position of this node in the nodes list

} node;

typedef struct EDGE_STRUCT {

	int				id;				
	node*			from;		// Source node pointer
	node*			to;			// Target node pointer
	edgeList*		pos;		// Position of this edge in the graph edges list
	edgeList*		frompos;	// Position of this edge in the source node edges list
	edgeList*		topos;		// Position of this edge in the target node edges list

} edge;

typedef struct NODE_LIST {

	node*			info;
	nodeList*		next;
	nodeList*		prev;
	
} nodeList;

typedef struct EDGE_LIST {
	
	edge*			info;
	edgeList*		next;
	edgeList*		prev;

} edgeList;

typedef struct GRAPH_STRUCT {

	int				nodeCount;
	int				edgeCount;
	nodeList*		nodes;
	edgeList*		edges;

} graph;

graph* new_graph();

void print_graph(graph* graph);

void decolor_graph(graph* graph);

void insert_node(node* node, nodeList** list);

void insert_edge(edge* edge, edgeList** list);

node* add_node(graph* graph, int id);

edge* add_edge(graph* g, int id, node* from, node* to);

void breadth_first_search(graph* g, node* n);

int bfs_connected(graph* graph);

int bfs_component_count(graph* g);

#endif