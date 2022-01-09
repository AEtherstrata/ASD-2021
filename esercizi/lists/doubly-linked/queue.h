#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.h"

typedef list queue;

queue* new_queue();

void enqueue(queue* q, int a);

int dequeue(queue* q);

#endif