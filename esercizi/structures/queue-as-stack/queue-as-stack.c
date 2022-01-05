#include "queue-as-stack.h"

qas* new_queue_as_stack(int maxsSize)
{
	qas* newQaS = (qas*)malloc(sizeof(qas));
	newQaS->entranceStack = new_stack(maxsSize);
	newQaS->exitStack = new_stack(maxsSize);
	newQaS->lastOp=0;
	return newQaS;
}

void flip_stack(stack* s1, stack* s2)
{
	empty(s1);  // Prepare the destination stack
	int stackSize = size(s2); // Look how many elements need to be copied

	/*  size(stack) can't be directly used in the for loop declaration because it changes mid-loop.
		It will make the loop copy only half the stack because each pop() the size is lowered by 1. */
	for (int i = 0; i < stackSize; i++)	
		push(s1, pop(s2));
}

void enqueue(qas* queue, int value)
{
	printf("\n|========= %d WILL BE ENQUEUED =========|\n\n", value);

	if (queue->lastOp == 2) {
		printf("The entranceStack is out of sync. Copying the elements...\n\n");
		flip_stack(queue->entranceStack, queue->exitStack);	
	}
	
	push(queue->entranceStack, value);	
	queue->lastOp = 1;

	printf("\n|========= %d HAS BEEN ENQUEUED =========|\n\n", queue->entranceStack->data[queue->entranceStack->top]);
}

int dequeue(qas* queue)
{
	printf("\n|========= DEQUEUE FIRST ELEMENT =========|\n\n");

	if (queue->lastOp == 1)	{
		printf("The exitStack is out of sync. Copying the elements...\n\n");
		flip_stack(queue->exitStack, queue->entranceStack);
	}

	int dequeued = pop(queue->exitStack);

	printf("\n|========= %d HAS BEEN DEQUEUED =========|\n\n", dequeued);
	queue->lastOp = 2;
	return dequeued;
}