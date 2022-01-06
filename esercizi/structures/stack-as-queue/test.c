#include "test.h"

int test_push(saq* stack, int exp)
{
	queue* queue = push(stack, exp);
	return exp == queue->data[queue->tail-1];
}

int test_pop(saq* stack, int exp)
{
	int popped = pop(stack);
	return exp == popped;
}

void test_stack_as_queue(saq* stack, osuProfile* osuID)
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
		printf("STACK AS QUEUE :   OK\n");
	} else {
		printf("STACK AS QUEUE : FAILED\n");
	}
}