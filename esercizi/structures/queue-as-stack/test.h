#ifndef _TEST_H
#define _TEST_H

#include "queue-as-stack.h"

typedef struct USER_ID_ARRAY {
	int* data;
	int len;
} osuProfile;

int test_enqueue(qas* queue, int exp);

int test_dequeue(qas* queue, int exp);

void test_queue_as_stack(qas* queue, osuProfile* osuID);

#endif