#ifndef _STRUCT_H
#define _STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// INVALID is an arbitraty value that cannot reside in the queue.
// In this example the queue contains a list of userids and 
// they are expected to be positive integers.

#define INVALID -1

typedef struct BOTH_STRUCT {
	int* data;	// Data array
	int head;	// Index of the first element
	int tail;	// Index of the first free cell
	int top;	// Index of the last element
	int len;	// Total length of the array
} both;

both* new_struct(int maxSize);

void print_struct(both* both);

int size(both* both);

int top(both* both);

int front(both* both);

void add_head(both* both, int value);

void add_tail(both* both, int value);

int delete_head(both* both);

int delete_tail(both* both);

#endif