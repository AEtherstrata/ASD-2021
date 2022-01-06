#include "contains.h"
#include <time.h>

// Define the random numbers' range

#define LOW 5153250		// Lowest chosen osuID
#define HIGH 20339031	// Highest chosen osuID

typedef struct USER_ID_ARRAY {
	int* data;
	int len;
} osuProfile;

int random_within_range();

void push_all(stack* testStack, osuProfile* osuID);

int test_contains(stack* stack, int value, int exp);

void test_stack_contains(stack* testStack, osuProfile* osuID);