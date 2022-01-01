#include "test.h"

int main()
{
	// Store the test values in an array
	osuProfile* osuID = (osuProfile*)malloc(sizeof(osuProfile));
	int array[19] = {11139199, 10527981, 12317880, 17703611, 20339031, 6680297,
					 7537836,  10657916, 11307288, 14766959, 9506297,  9093999,
					 14802064, 13134974, 18722281, 10668442, 12699783, 15153250,
					 11514124};

	osuID->data = array;
	osuID->len = 19;

	// Create a new stack
	stack* testStack = new_stack(10);

	// Test the stack
	test_stack(testStack, osuID);

	printf("Press enter to continue ");
	getchar();

	return 0;
}