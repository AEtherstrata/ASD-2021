#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include "object.h"

queue* new_queue(int size);

void print_queue(queue* q);

void expand_queue(queue** q);

void enqueue(queue* queue, node* node);

node* dequeue(queue* queue);

int is_queue_empty(queue* queue);

#endif