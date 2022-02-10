#include "graph.h"

graph* new_graph()
{
	graph* newG = (graph*)malloc(sizeof(graph));
	newG->edgeCount = 0;
	newG->nodeCount = 0;
	newG->edges = NULL;
	newG->nodes = NULL;

	return newG;
}

void print_graph(graph* g)
{
	printf("Graph: %d nodes ][ %d edges\n", g->nodeCount, g->edgeCount);

	if (g->nodeCount > 0)
	{
		printf("Node list:\n");
		nodeList* x = g->nodes;
		while (x != NULL)
		{
			printf("Node %d: Color %d\n", x->info->id, x->info->color);
			x = x->next;
		}
	}
	
	if (g->edgeCount > 0)
	{
		printf("\nEdge list:\n");
		edgeList* y = g->edges;
		while (y != NULL)
		{
			printf("Edge %d\n", y->info->id);
			printf("     from %d\n", y->info->from->id);
			printf("       to %d\n", y->info->to->id);
			y = y->next;
		}
	}
}

void insert_node(node* node, nodeList** list)
{
	nodeList* listItem = (nodeList*)malloc(sizeof(nodeList));
	listItem->info = node;
	listItem->prev = NULL;
	listItem->next = (*list);

	if ((*list) != NULL) // There is a node already, link it to the new node
	{
		(*list)->prev = listItem;
	}

	(*list) = listItem; // Make it the new head
	node->pos = listItem;
}

void insert_edge(edge* edge, edgeList** list)
{
	edgeList* listItem = (edgeList*)malloc(sizeof(edgeList));
	listItem->info = edge;
	listItem->prev = NULL;
	listItem->next = (*list);
	
	if ((*list) != NULL)
	{
		(*list)->prev = listItem;
	}
	
	(*list) = listItem;
}

node* add_node(graph* g, int id)
{
	node* n = (node*)malloc(sizeof(node));

	n->id = id;
	n->color = 0;
	n->edges = NULL;

	/* Add the new node to the head of the nodes list */
	insert_node(n, &(g->nodes));

	g->nodeCount++; 
	return n;
}

edge* add_edge(graph* g, int id, node* from, node* to)
{
	edge* e = (edge*)malloc(sizeof(edge));

	e->id = id;
	e->from = from;
	e->to = to;

	/* Add the new edge to the head of the edges list */
	insert_edge(e, &(g->edges));
	e->pos = g->edges;

	/* Add the new edge to the source node edges lists */
	insert_edge(e, &(from->edges));
	e->frompos = from->edges;

	/* Add the new edge to the target node edges lists */
	insert_edge(e, &(to->edges));
	e->topos = to->edges;

	g->edgeCount++;

	return e;
}