#include "stack.h"

stack* new_stack(int size)
{
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->data = (int*)malloc(size*sizeof(int));
	newStack->top = -1;
	newStack->len = size;
	return newStack;
}

void push(stack* stack, int value)
{
	if (stack->top == stack->len-1)	{
		printf("OVERFLOW: The stack is full.\n");
	} else {
		stack->top++;
		stack->data[stack->top] = value;
	}
}

void pop(stack* stack, int* target)
{
	if(stack->top == -1){
		printf("UNDERFLOW: The stack is already empty.\n");
	} else {
		stack->top--;
		*target = stack->data[stack->top+1];
	}
}