#include "stack.h"

stack* new_stack(int size)
{
	// Allocate a new stack and set its fields
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->data = (int*)malloc(size*sizeof(int));
	newStack->top = -1;
	newStack->len = size;

	// Initialise all indices to 0
	for (int i = 0; i < newStack->len; i++) {
		newStack->data[i] = 0;
	}

	return newStack;
}

void print_stack(stack* stack)
{
	printf("STACK: [ ");
	if (stack->len == 0) {
		printf("]\n");
	} else {
		for (int i = 0; i < stack->len-1; i++) {
			printf("%d | ", stack->data[i]);
		}
		printf("%d ]\n", stack->data[stack->len-1]);
	}
}

int is_empty(stack* stack)
{	
	return stack->top == -1;
}

void push(stack* stack, int value)
{
	if (stack->top == stack->len-1)	{
		printf("OVERFLOW: The stack is full. Expanding...\n");
		stack->data = (int*)realloc(stack->data, stack->len * 2);

		/* Set all new indices to 0 */
		for (int i = stack->len; i < stack->len * 2; i++) {
			stack->data[i] = 0;
		}

		stack->len *= 2;
		printf("      The array can now contain %d elements.\n", stack->len);
	} 
	printf("[PUSH] (%d) ", value);
	stack->top++;
	stack->data[stack->top] = value;
	printf("%d has been pushed to the stack.\n", value);
	printf("      The stack is now %d elements long.\n", size(stack));
	print_stack(stack);
}

int pop(stack* stack)
{
	printf("[POP] ");

	if(stack->top == -1){
		printf("UNDERFLOW: The stack is already empty.\n");
		print_stack(stack);
		return INVALID; // This is an arbitrary number. It should be an invalid value for the stack.
	} else {
		stack->top--;
		printf("%d has been popped from the stack.\n", stack->data[stack->top+1]);
		printf("     The stack is now %d elements long.\n", size(stack));
		print_stack(stack);
		return stack->data[stack->top+1];
	}
}

int top(stack* stack)
{
	return stack->data[stack->top];
}

void empty(stack* stack)
{
	stack->top = -1;
}

int size(stack* stack)
{
	return stack->top + 1;
}
