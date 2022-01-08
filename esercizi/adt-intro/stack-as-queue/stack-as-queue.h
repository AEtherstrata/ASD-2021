#ifndef _STACK_AS_QUEUE_H
#define _STACK_AS_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../queue/queue.h"

typedef struct STACK_AS_QUEUE {
	queue* q1;
	queue* q2;
} saq;

saq* new_stack_as_queue(int maxSize);

queue* push(saq* stack, int value);

int pop(saq* stack);

#endif