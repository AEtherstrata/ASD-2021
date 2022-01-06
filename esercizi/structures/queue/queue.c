#include "queue.h"

queue* new_queue(int maxSize)
{
	queue* newQueue = (queue*)malloc(sizeof(queue));
	newQueue->data = (int*)malloc(sizeof(int)*maxSize);
	newQueue->head = -1;
	newQueue->tail = 0;
	newQueue->len = maxSize;

	// Initialise all indices to 0
	// To get theta(1) remove this or use calloc instead of malloc
	for (int i = 0; i < newQueue->len; i++) {
		newQueue->data[i] = 0;
	}

	printf("A new queue has been created at %d and can contain %d elements.\n", newQueue, newQueue->len);
	
	return newQueue;
}

void print_queue(queue* queue)
{
	printf("QUEUE: [ ");
	if (queue->len == 0) {
		printf("]\n");
	} else {
		for (int i = 0; i < queue->len-1; i++) {
			if (i==queue->head) printf(">");			
			printf("%d", queue->data[i]);
			if (i==queue->tail) printf("<");
			printf(" | ");
		}
		if (queue->len-1==queue->head) printf(">");			
		printf("%d", queue->data[queue->len-1]);
		if (queue->len-1==queue->tail) printf("<");
		printf(" ]\n");
	}
}

int is_empty(queue* queue)
{
	return (queue->head == queue->tail) || (queue->head == -1 && queue->tail == 0);
} 

void enqueue(queue* queue, int value)
{
	if (size(queue) == queue->len-1) {
		printf("[ENQUEUE] (%d) OVERFLOW: The queue is full. Expanding...\n", value);
		queue->data = (int*)realloc(queue->data, queue->len * 2);

		if (queue->tail < queue->head) {
			for (int i = queue->head; i < queue->len; i++) {
				queue->data[i+queue->len] = queue->data[i];
			}
			queue->head = queue->head + queue->len;
			
			/* Set all new indices to 0 */
			// To get theta(1) remove this
			for (int i = queue->tail; i < queue->head; i++) {
				queue->data[i] = 0;
			} 
		} else {
			/* Set all new indices to 0 */
			// To get theta(1) remove this
			for (int i = queue->len; i < queue->len * 2; i++) {
				queue->data[i] = 0;
			}
		}

		queue->len *= 2;
		printf("      The array can now contain %d elements.\n", queue->len);
		print_queue(queue);
		printf("  /---------------------/\n");
	}

	if (is_empty(queue)) queue->head=0;
	printf("[ENQUEUE] (%d) ", value);
	queue->data[queue->tail] = value;
	if (queue->tail+1 >= queue->len) {
		queue->tail=0;
	} else {
		queue->tail++;
	}
	
	printf("%d has been pushed to the queue.\n", value);
	printf("      The queue is now %d elements long.\n", size(queue));
	print_queue(queue);
	printf("  /---------------------/\n");
}

int dequeue(queue* queue)
{
	printf("[DEQUEUE] ");

	if (is_empty(queue)) {
		printf("UNDERFLOW: The queue is already empty.\n");
		print_queue(queue);
		printf("  /---------------------/\n");
		return INVALID; // This is an arbitrary number. See queue.h for info.
	} else {
		queue->head++;
		printf("%d has been dequeued from the queue.\n", queue->data[queue->head-1]);
		printf("     The queue is now %d elements long.\n", size(queue));
		print_queue(queue);
		printf("  /---------------------/\n");
		return queue->data[queue->head-1];
	}
}

int front(queue* queue)
{
	return queue->data[queue->head];
}

void empty(queue* queue)
{
	queue->head = -1;
	queue->tail = 0;
}

int size(queue* queue)
{
	if (queue->tail>=queue->head) return queue->tail - queue->head;
	else return queue->len + queue->tail - queue->head;
}