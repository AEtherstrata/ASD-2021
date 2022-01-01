#include "test.h"

int test_enqueue(queue* queue, int exp)
{
	enqueue(queue, exp);
	if (queue->tail-1 == -1) return exp == queue->data[queue->len-1];
	return exp == queue->data[queue->tail-1];
}

int test_dequeue(queue* queue , int exp)
{
	int dequeued = dequeue(queue);
	return exp == dequeued;
}

void test_queue(queue* queue, osuProfile* osuID)
{
	int good = 0;
	int qCount = 0;

	// Add all array values to queue
	for (int i = 0; i < osuID->len; i++) 
	{
		good = test_enqueue(queue, osuID->data[i]);
		if (!good) goto end;
	
		// Pop an ID once in a while
		if(rand()%7==0){
			good = test_dequeue(queue, osuID->data[qCount]);
			if (!good) goto end;
			qCount++;
		}
	}

	end:
	if (good) {
		printf("QUEUE :   OK\n");
	} else {
		printf("QUEUE : FAILED\n");
	}
}