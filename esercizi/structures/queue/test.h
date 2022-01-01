#include "queue.h"

typedef struct USER_ID_ARRAY {
	int* data;
	int len;
} osuProfile;

// Test queue

int test_enqueue(queue* queue, int exp);

int test_dequeue(queue* queue ,int exp);

void test_queue(queue* queue, osuProfile* osuID);
