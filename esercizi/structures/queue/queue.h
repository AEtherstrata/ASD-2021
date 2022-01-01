#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Queues make a FIFO storage
// (First-in - First-out)
// This example is an integer array queue

// INVALID is an arbitraty value that cannot reside in the queue.
// In this example the queue contains a list of userids and 
// they are expected to be positive integers.

#define INVALID -1;

typedef struct QUEUE_STRUCT {
	int* data;
	int head;
	int tail;
	int len;
} queue;

// Create a new queue and return its pointer
queue* new_queue(int maxSize);

// Prints a given queue
void print_queue(queue* queue);

// Returns true if the queue is empty, false otherwise
int is_empty(queue* queue);

// Adds a value to the queue
void enqueue(queue* queue, int value);

// Removes a value from the queue and returns it
int dequeue(queue* queue);

// Returns the oldest value
int front(queue* queue);

// Sets the queue to empty
void empty(queue* queue);

// Returns the size of the queue
int size(queue* queue);

#endif