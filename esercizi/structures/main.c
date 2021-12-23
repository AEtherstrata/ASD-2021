#include "stack.h"

int main()
{
	// Create a new stack
	stack* testStack = new_stack(10);

	push(testStack, 11139199);	
	push(testStack, 10527981);
	push(testStack, 12317880);
	push(testStack, 17703611);
	push(testStack, 20339031);
	push(testStack, 6680297);
	push(testStack, 7537836);
	push(testStack, 10657916);
	push(testStack, 11307288);
	push(testStack, 14766959);
	push(testStack, 9506297);
	push(testStack, 9093999);
	push(testStack, 14802064);
	push(testStack, 13134974);
	push(testStack, 18722281);
	push(testStack, 10668442);
	push(testStack, 12699783);
	push(testStack, 15153250);
	push(testStack, 11514124);

	printf("Press enter to continue ");
	getchar();

	return 0;
}