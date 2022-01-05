#ifndef _QUEUE_AS_STACK_H
#define _QUEUE_AS_STACK_H

#include "../stack/stack.h"

typedef struct QUEUE_AS_STACK{
	stack* entranceStack;
	stack* exitStack;
	int lastOp;
} qas;

qas* new_queue_as_stack(int maxsSize);

void swap(stack* s1, stack* s2);

void enqueue(qas* queue, int value);

int dequeue(qas* queue);

#endif