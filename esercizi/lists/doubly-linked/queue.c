#include "queue.h"

queue* new_queue()
{
	return new_list();
}

void enqueue(queue* q, int a)
{
	add_tail(q, a);
}

int dequeue(queue* q)
{
	if(!is_empty(q)){
		int a = q->head->data;
		delete_head(q);
		return a;
	}

	return -1;
}