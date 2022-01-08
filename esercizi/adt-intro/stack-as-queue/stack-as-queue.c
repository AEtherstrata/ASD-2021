#include "stack-as-queue.h"

saq* new_stack_as_queue(int maxSize)
{
	saq* newSaQ = (saq*)malloc(sizeof(saq));
	newSaQ->q1 = new_queue(maxSize);
	newSaQ->q2 = new_queue(maxSize);
	return newSaQ;
}

queue* push(saq* stack, int value)
{
	printf("\n|========= %d WILL BE PUSHED =========|\n\n", value);

	queue* select = NULL;

	if (is_empty(stack->q1)) {
		enqueue(stack->q2, value);
		select = stack->q2;
	} else {
		enqueue(stack->q1, value);
		select = stack->q1;
	}
	
	printf("\n|========= %d HAS BEEN PUSHED =========|\n\n", select->data[select->tail-1]);

	return select;
}

int pop(saq* stack)
{
	printf("\n|========= POP LAST ELEMENT =========|\n\n");

	if (is_empty(stack->q1) == 0 && is_empty(stack->q2) == 0)	{
		printf("UNDERFLOW: The stack is empty!\n\n");
		return INVALID;
	}

	int popped;
	queue* emptyQueue = NULL;
	queue* fullQueue = NULL;

	if (is_empty(stack->q1)) {
		emptyQueue = stack->q1;
		fullQueue = stack->q2;
	} else {
		emptyQueue = stack->q2;
		fullQueue = stack->q1;
	}

	empty(emptyQueue);

	while(1) {
		popped = dequeue(fullQueue);
		if (is_empty(fullQueue)) {	
			printf("\n|========= %d HAS BEEN POPPED =========|\n\n",popped);
			return popped;
		}
		enqueue(emptyQueue, popped);
	}
}