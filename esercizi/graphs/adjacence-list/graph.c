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

void print_source_well_prop(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("Node #%d: ", i);

		if (a[i] == 2) {
			printf(" Alone\n");
		} else if (a[i] == 1) {
			printf(" Source\n");
		} else if (a[i] == -1) {
			printf(" Well\n");
		} else {
			printf(" Node\n");
		}		
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

int check_all_not_oriented(graph* g)
{	
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			if(check_for_edge(g, i, j) != check_for_edge(g, j, i)){
				return 0;
			}
		}	
	}
	return 1;
}

int is_well(graph* g, int n)
{
	if (is_empty(g->edgeList[n])) {
		return 1;
	}
	return 0;
}

int is_source(graph* g, int n)
{
	for (int i = 0; i < g->n; i++)
	{
		if(check_for_edge(g, i, n)) {
			return 0;
		}
	}
	return 1;
}

int* create_source_well_list(graph* g)
{
	int* data = (int*)calloc(g->n, sizeof(int));

	for (int i = 0; i < g->n; i++)
	{
		if (is_well(g, i) && is_source(g, i)) {
			data[i] = 2;
		} else if (is_well(g, i)) {
			data[i] = -1;
		}
		else if (is_source(g, i)) {
			data[i] = 1;
		}
	}
	
	return data;
}

int check_union_for_edge(graph* g1, graph* g2, int n1, int n2)
{
	return (check_for_edge(g1, n1, n2) || check_for_edge(g2, n1, n2));
}

int check_union_all_pairs(graph* g1, graph* g2)
{
	if (g1->n != g2->n)
	{
		printf("g1->n = %d\n", g1->n);
		printf("g2->n = %d\n", g2->n);
		printf("The graphs must have the same size! Exiting...\n");
		exit(1);
	}

	for (int i = 0; i < g1->n; i++)
	{
		for (int j = 0; j < g1->n; j++)
		{
			// The exercise didn't specify whether loops are to be considered. I chose to not include them
			if (i != j)	{
				if(!(check_union_for_edge(g1, g2, i, j)) && !(check_union_for_edge(g1, g2, j, i))){
					return 0;
				}
			}
		}	
	}
	return 1;
	
}

int check_for_complementary_nodes(graph* g1, graph* g2)
{
	int* a1 = create_source_well_list(g1);
	int* a2 = create_source_well_list(g2);

	for (int i = 0; i < g1->n; i++)
	{
		if ((a1[i]==1 || a1[i]==-1) 
			&& (a2[i]==1 || a2[i]==-1) 
			&& (!(a1[i]==1 && a2[i]==-1) 
			&& !(a1[i]==-1 && a2[i]==1))) 
		{
			printf("%d is not complementary!\n", i);
			return 0;
		}
		
	}
	return 1;
}
