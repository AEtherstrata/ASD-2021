#include "graph.h"

graph* new_graph(int n)
{
	graph* newG = (graph*)malloc(sizeof(graph));

	newG->n = n;
	newG->edgeList = (list**)calloc(n, sizeof(list*));

	for (int i = 0; i < newG->n; i++) {
		newG->edgeList[i] = new_list();
	}
	
	return newG;
}

void print_graph(graph* g)
{
	printf("Graph size: %d\n", g->n);
	for (int i = 0; i < g->n; i++)
	{
		printf("[%d] -> ", i);
		print_list(g->edgeList[i]);
	}
}

void add_oriented_edge(graph* g, int n1, int n2)
{
	add_head(g->edgeList[n1], n2);
}

void add_not_oriented_edge(graph* g, int n1, int n2)
{
	add_head(g->edgeList[n1], n2);
	add_head(g->edgeList[n2], n1);
}

int exit_rank(graph* g, int n)
{
	if (is_empty(g->edgeList[n])) {
		return 0;
	}
	
	int count = 0;
	listItem* i = g->edgeList[n]->head;

	while (i != NULL)
	{
		count++;
		i = i->next;
	}

	return count;	
}

int entry_rank(graph* g, int n)
{
	int count = 0;

	for (int i = 0; i < g->n; i++)
	{
		listItem* j = g->edgeList[i]->head;

		while (j != NULL)
		{
			if (j->data == n) {
				count++;
			}
			j = j->next;
		}	
	}
	
	return count;
}

float average_exit_rank(graph* g)
{
	float average = 0;

	for (int i = 0; i < g->n; i++) {
		average += exit_rank(g, i);
	}

	return average / g->n;
}

int is_simple(graph* g)
{
	for (int i = 0; i < g->n; i++)
	{
		if (search(g->edgeList[i], i) != NULL)
		{
			return 0;
		}
	}
	return 1;
}

int check_for_edge(graph* g, int n1, int n2)
{
	if (is_empty(g->edgeList[n1]))
	{
		return 0;
	}
	
	if (search(g->edgeList[n1], n2) != NULL)
	{
		return 1;
	}
	
	return 0;
}