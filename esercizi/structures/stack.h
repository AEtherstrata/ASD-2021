#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

// Stacks make a LIFO storage
// (Last-in - First-out)
// This example is an integer array stack

// INVALID is an arbitraty value that cannot reside in the stack.
// In this example the stack contains a list of userids and 
// they are expected to be positive integers.

#define INVALID -1;

typedef struct STACK_STRUCT {
	int* data;
	int top;
	int len;
} stack;

stack* new_stack(int maxsize);

void print_stack(stack* stack);

int is_empty(stack* stack);

void push(stack* stack, int value);

int pop(stack* stack);

int top(stack* stack);

void empty(stack* stack);

int size(stack* stack);

#endif