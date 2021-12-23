#include "stack.h"

int main(){
	stack* testStack = new_stack(10);
	push(testStack, 5);
	push(testStack, 8);
	push(testStack, 3);
	int popValue;
	pop(testStack, &popValue);
	printf("popped: %d\n", popValue);

	printf("Press any key to continue ");
	getchar();
	
	return 0;
}