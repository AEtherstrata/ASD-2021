#include "test.h"

int test_push(stack* stack, int exp)
{
	push(stack, exp);
	return exp == stack->data[stack->top];
}

int test_pop(stack* stack , int exp)
{
	int popped = pop(stack);
	return exp == popped;
}

void test_stack(stack* stack, osuProfile* osuID)
{
	int good = 0;

	// Add all array values to stack
	for (int i = 0; i < osuID->len; i++) 
	{
		good = test_push(stack, osuID->data[i]);
		if (!good) goto end;
	
		// Pop an ID once in a while
		if(rand()%7==0){
			good = test_pop(stack, osuID->data[i]);
			if (!good) goto end;
		}
	}

	end:
	if (good) {
		printf("STACK :   OK\n");
	} else {
		printf("STACK : FAILED\n");
	}
}