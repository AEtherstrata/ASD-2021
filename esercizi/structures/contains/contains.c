#include "contains.h"

int contains(stack* stack, int value)
{
	for (int i = 0; i <= stack->top; i++) {
		if (value == stack->data[i]) {
			return 1;
		}
	}
	return 0;
}