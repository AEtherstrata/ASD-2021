#include "stack.h"

typedef struct USER_ID_ARRAY {
	int* data;
	int len;
} osuProfile;

// Test stack

int test_push(stack* stack, int exp);

int test_pop(stack* stack ,int exp);

void test_stack(stack* stack, osuProfile* osuID);
