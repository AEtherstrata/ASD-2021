#include "test.h"

int random_within_range()
{
	return (rand()*rand()) % (HIGH - LOW + 1) + LOW;
}

void push_all(stack* testStack, osuProfile* osuID)
{
	for (int i = 0; i < osuID->len; i++) {
		push(testStack, osuID->data[i]);
	}
}

int test_contains(stack* stack, int value, int exp)
{
	return contains(stack, value) && exp;
}

void test_stack_contains(stack* testStack, osuProfile* osuID)
{
	srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		int exp = 0;
		int result = 0;
		int selected = 0;

		// Take some samples from the original set
		if (i%10 == 0) {
			exp = 1;
			selected = osuID->data[i/10];
			result = test_contains(testStack, selected, exp);
		} else {
		
			int random = random_within_range();

			// If the random number is contained in the original array set expected result to true
			for (int i = 0; i < osuID->len; i++) {
				if (random == osuID->data[i]) {
					exp = 1;
					break;
				}
			}
			
			selected = random;
			result = test_contains(testStack, random, exp);			
		}

		if (result){
				printf("%d is contained in the stack.\n", selected);
			} else {
				printf("%d is NOT contained in the stack.\n", selected);
			}
	}
}