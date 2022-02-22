#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "object.h"
#include "queue.h"
#include "tree.h"

graph* new_graph();

void print_graph(graph* graph);

void print_array(compArray*);

void decolor_graph(graph* graph);

void insert_node(node* node, nodeList** list);

void insert_edge(edge* edge, edgeList** list);

node* add_node(graph* graph, int id);

edge* add_edge(graph* graph, int id, node* from, node* to);

void breadth_first_search(graph* g, node* n);

int bfs_connected(graph* graph);

int bfs_component_count(graph* graph);

void depth_first_search_ric(node* node);

void depth_first_search_color(node* node, int color);

void depth_first_search(graph* g);

void create_parent_array(treeNode* t, node* n);

treeNode* parent_array(graph* g);

int biggest_compontent_node_count(graph* g);

int dfs_component_count(graph* g);

void color_all_nodes(graph* g);

compArray* component_count_array(graph* graph);

#endif