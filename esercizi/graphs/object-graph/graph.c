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

void print_array(compArray* a)
{
	for (int i = 0; i < a->len; i++)
	{
		printf("[%d] = %d\n", i, a->array[i]);
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
	if (g == NULL)
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
	if (g == NULL)
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
			breadth_first_search(g, x->info);
			count++;
		}
		x = x->next;
	}

	return count;
}

void depth_first_search_ric(node* n)
{
	if (n->color != 0) return;

	n->color = 1;		// Color the current node

	/* Go through all edges and recall this function on the first uncolored node */

	edgeList* edges = n->edges;

	while (edges != NULL)
	{
		node* other = (edges->info->from == n) ? edges->info->to : edges->info->from;

		/* If the discovered node has no color, start a new search */

		depth_first_search_ric(other);

		edges = edges->next;
	}
}

void depth_first_search_color(node* n, int c)
{
	if (n->color != 0) return;

	n->color = c;		// Color the current node

	/* Go through all edges and recall this function on the first uncolored node */

	edgeList* edges = n->edges;

	while (edges != NULL)
	{
		node* other = (edges->info->from == n) ? edges->info->to : edges->info->from;

		/* If the discovered node has no color, start a new search */

		depth_first_search_color(other, c);

		edges = edges->next;
	}
}

void depth_first_search(graph* g)
{
	if (g == NULL)
	{
		printf("The graph is empty! Exiting...\n");
		exit(1);
	}

	decolor_graph(g);
	depth_first_search_ric(g->nodes->info);
}

void create_parent_array(treeNode* t, node* n)
{
	n->color = 1;

	/* Go through all edges and recall this function on the first uncolored node */

	edgeList* edges = n->edges;

	while (edges != NULL)
	{
		node* other = (edges->info->from == n) ? edges->info->to : edges->info->from;

		/* If the discovered node has no color, start a new search */

		if (other->color == 0)
		{
			add_child(t, other);
			t = t->left;

			create_parent_array(t, other);
		}

		edges = edges->next;
	}
}

// Implies the graph is connected
treeNode* parent_array(graph* g)
{
	if (g == NULL)
	{
		printf("The graph is empty! Exiting...\n");
		exit(1);
	}

	decolor_graph(g);

	treeNode* root = allocate_node(g->nodes->info);

	create_parent_array(root, g->nodes->info);

	return root;
}

int biggest_compontent_node_count(graph* g)
{
	compArray* data = component_count_array(g);

	int max = 0;
	for (int i = 0; i < data->len; i++)
	{
		max = (data->array[i] > max) ? data->array[i] : max;
	}

	return max;
}

int dfs_component_count(graph* g)
{
	if (g == NULL)
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
			depth_first_search_color(x->info, count);
		}
		x = x->next;
	}

	return count;
}

void color_all_nodes(graph* g)
{
	if (g == NULL)
	{
		printf("The graph is empty! Exiting...\n");
		exit(1);
	}

	decolor_graph(g);

	int color = 0;
	nodeList* x = g->nodes;

	while (x != NULL)
	{
		if (x->info->color == 0)
		{
			color++;
			depth_first_search_color(x->info, color);
		}
		x = x->next;
	}
}

compArray* component_count_array(graph* g)
{
	if (g == NULL)
	{
		printf("The graph is empty! Exiting...\n");
		exit(1);
	}

	compArray* component_array = (compArray*)malloc(sizeof(compArray));

	component_array->len = dfs_component_count(g)+1;
	component_array->array = (int*)calloc(component_array->len, sizeof(int));

	nodeList* x = g->nodes;
	while (x != NULL)
	{
		component_array->array[x->info->color]++;
		x = x->next;
	}

	return component_array;
}