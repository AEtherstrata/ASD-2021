#include "test.h"

int test_enqueue(qas* queue, int exp)
{
	enqueue(queue, exp);
	return exp == queue->entranceStack->data[queue->entranceStack->top];
}

int test_dequeue(qas* queue, int exp)
{
	int dequeued = dequeue(queue);
	return exp == dequeued;
}

void test_queue_as_stack(qas* queue, osuProfile* osuID)
{
	int good = 0;
	int qCount = 0;

	// Add all array values to queue
	for (int i = 0; i < osuID->len; i++) 
	{
		good = test_enqueue(queue, osuID->data[i]);
		if (!good) goto end;
	
		// Dequeue an ID once in a while
		if(rand()%5==0){
			good = test_dequeue(queue, osuID->data[qCount]);
			if (!good) goto end;
			qCount++;
		}
	}

	end:
	if (good) {
		printf("QUEUE AS STACK :   OK\n");
	} else {
		printf("QUEUE AS STACK : FAILED\n");
	}
}
