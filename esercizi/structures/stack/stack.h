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
	int top; // Index of the last element
	int len; // Length of the data array
} stack;

// Create a new stack and return its pointer
stack* new_stack(int maxsize);

// Prints a given stack
void print_stack(stack* stack);

// Returns true if the stack is empty, false otherwise
int is_empty(stack* stack);

// Adds a value to the stack
void push(stack* stack, int value);

// Removes a value from the stack and returns it
int pop(stack* stack);

// Returns the surface value
int top(stack* stack);

// Sets the stack to empty
void empty(stack* stack);

// Returns the size of the stack
int size(stack* stack);

#endif