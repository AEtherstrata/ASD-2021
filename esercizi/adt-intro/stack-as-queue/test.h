#ifndef _TEST_H
#define _TEST_H

#include "stack-as-queue.h"

typedef struct USER_ID_ARRAY {
	int* data;
	int len;
} osuProfile;

int test_push(saq* queue, int exp);

int test_pop(saq* queue, int exp);

void test_stack_as_queue(saq* queue, osuProfile* osuID);

#endif