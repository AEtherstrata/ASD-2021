#include "graph.h"

graph* new_graph(int s)
{
	graph* newG = (graph*)malloc(sizeof(graph));
	newG->n = s;

	newG->matrix = (int**)malloc(s * sizeof(int*));

	for (int i = 0; i < s; i++)
	{
		newG->matrix[i] = (int*)calloc(s, sizeof(int));
	}
	
	return newG;
}

void print_graph(graph* g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("[%d]",g->matrix[i][j]);
		}
		printf("\n");
	}
}

void add_oriented_edge(graph* g, int n1, int n2)
{
	g->matrix[n1][n2] = 1;
}

void add_not_oriented_edge(graph* g, int n1, int n2)
{
	g->matrix[n1][n2] = 1;	
	g->matrix[n2][n1] = 1;
}

graph* resize_matrix(graph* g, int s)
{
	graph* newG = new_graph(s);

	for (int i = 0; i < newG->n; i++)
	{
		if (i < g->n)
		{
			for (int j = 0; j < newG->n; j++)
			{
				if (j < g->n)
				{
					newG->matrix[i][j] = g->matrix[i][j];
				}				
			}
		}		
	}

	free(g);
	return newG;
}

int exit_rank(graph* g, int n)
{
	int count = 0;
	for (int i = 0; i < g->n; i++)
	{
		if (g->matrix[n][i] == 1)
		{
			count++;
		}		
	}
	return count;
}

int entry_rank(graph* g, int n)
{
	int count = 0;
	for (int i = 0; i < g->n; i++)
	{
		if (g->matrix[i][n] == 1)
		{
			count++;
		}		
	}
	return count;
}