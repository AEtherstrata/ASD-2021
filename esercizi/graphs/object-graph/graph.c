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
			printf("Node %d | %lu : Color %d\n", x->info->id, x->info, x->info->color);
			x = x->next;
		}
	}
	
	if (g->edgeCount > 0)
	{
		printf("\nEdge list:\n");
		edgeList* y = g->edges;
		while (y != NULL)
		{
			printf("Edge %d | %lu\n", y->info->id, y->info);
			printf("     from %d\n", y->info->from->id);
			printf("       to %d\n", y->info->to->id);
			y = y->next;
		}
	}
}

void decolor_graph(graph* g)
{
	nodeList* x = g->nodes;
	while (x != NULL)
	{
		x->info->color = 0;
		x = x->next;
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

void breadth_first_search(graph* g, node* n)
{
	/* Set all nodes' color to 0 and initialize a new visit queue */

	decolor_graph(g);
	queue* q = new_queue(4);

	/* Color the starting node and add it to the queue */

	n->color = 1;
	enqueue(q, n);

	/* 	Until no more new nodes are discovered, 
		search and color the adjacent nodes     */

	while (!is_queue_empty(q))
	{
		/* 	Take the first element of the queue and go through all edges
			Color all adjacent nodes and add them to the queue if uncolored  */

		node* current = dequeue(q);

		edgeList* currentEdge = current->edges;

		while (currentEdge != NULL)
		{
			/* Select the right node */

			node* other = currentEdge->info->from;
          	if( other == current ) {
            	other = currentEdge->info->to;
        	}

			/* If the discovered node has no color, color it and add it to the queue */

			if (other->color == 0)
			{
				other->color = 1;
				enqueue(q, other);
			}

			currentEdge = currentEdge->next;
		}
	}
}

int bfs_connected(graph* g)
{
	if (g->nodeCount == 0)
	{
		printf("The graph is empty! Exiting...\n");
		exit(1);
	}
	
	breadth_first_search(g, g->nodes->info);

	nodeList* x = g->nodes;
	while (x != NULL)
	{
		if (x->info->color == 0) {
			return 0;					// If something is not colored, the graph is not connected
		}
		x = x->next;
	}
	
	return 1;
}

int bfs_component_count(graph* g)
{
	if (g->nodeCount == 0)
	{
		printf("The graph is empty! Exiting...\n");
		exit(1);
	}

	decolor_graph(g);
	
	int count = 0;
	nodeList* x = g->nodes;

	while (x != NULL)
	{
		if (x->info->color == 0)
		{
			count++;
			breadth_first_search(g, x->info);
		}
		x = x->next;
	}
	
	return count;
}
