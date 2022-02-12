#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "object.h"
#include "queue.h"
#include "tree.h"

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