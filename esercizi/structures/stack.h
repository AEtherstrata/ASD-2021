#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

// Stacks make a LIFO storage
// (Last-in - First-out)
// This example is an integer stack

typedef struct STACK_STRUCT {
	int* data;
	int top;
	int len;
} stack;

stack* new_stack(int maxsize);

int is_empty(stack* stack);

void push(stack* stack, int value);

void pop(stack* stack, int* target);

void top(stack* stack);

void empty(stack* stack);

void size(stack* stack);

#endif