#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/* Forward declarations */

typedef struct NODE_STRUCT node;

typedef struct GRAPH_STRUCT graph;

/* * * * * * * * * * * */

typedef	struct QUEUE_STRUCT {
	
	int			head;		
	int			tail;		
	node**		array;		
	int			size;		

} queue;

queue* new_queue(int size);

void print_queue(queue* q);

void expand_queue(queue** q);

void enqueue(queue* queue, node* node);

node* dequeue(queue* queue);

int is_queue_empty(queue* queue);

#endif