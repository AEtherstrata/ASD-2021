#include "queue.h"

queue* new_queue(int s)
{
	queue* newQ = (queue*)malloc(sizeof(queue));

	newQ->head = 0;
	newQ->tail = 0;
	newQ->size = s;

	newQ->array = (node**)calloc(s, sizeof(node*));

	return newQ;
}

void print_queue(queue* q)
{
	printf("{ ");
	
	for (int i = 0; i < q->size; i++)
	{
		if (i == q->head) {
			printf(">");
		}
		
		printf("%lu ",q->array[i]);

		if (i == q->tail) {
			printf("<");
		}

		if (i !=  q->size-1) {
			printf(",");
		}
	}

	printf("}\n");
}

void expand_queue(queue** q)
{
	(*q)->size *= 2;
	(*q)->array = (node**)realloc((*q)->array, (*q)->size);

	if ((*q)->tail < (*q)->head)
	{
		int i;
		for (i = 0; i < (*q)->tail; i++)
		{
			(*q)->array[(*q)->size/2 + i] = (*q)->array[i];
		}
		(*q)->tail = (*q)->size/2 + i;
	}
}

void enqueue(queue* q, node* n)
{
	if ((q->tail == q->head-1) || 
		(q->tail == q->size-1 && q->head == 0))	{		
		expand_queue(&q);
	}
	
	q->array[q->tail] = n;
	q->tail++;

	if (q->tail == q->size)	{
		q->tail = 0;
	}
}

node* dequeue(queue* q)
{
	if (q->head == q->tail)
	{
		printf("The queue is already empty! Exiting...\n");
		exit(1);
	}
	
	node* output = q->array[q->head];
	q->head++;
	if (q->head == q->size)
	{
		q->head = 0;
	}
	
	return output;
}

int is_queue_empty(queue* q)
{
	return q->head == q->tail;
}