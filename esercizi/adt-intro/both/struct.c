#include "struct.h"

both* new_struct(int size)
{
	both* newBoth = (both*)malloc(sizeof(both));
	newBoth->data = (int*)malloc(sizeof(int)*size);
	newBoth->head = -1;
	newBoth->tail = 0;
	newBoth->len = size;

	// Initialise all indices to 0
	// To get theta(1) remove this or use calloc instead of malloc
	for (int i = 0; i < newBoth->len; i++) {
		newBoth->data[i] = 0;
	}

	printf("A new both has been created at %d and can contain %d elements.\n", newBoth, newBoth->len);
	
	return newBoth;
}

void print_struct(both* both)
{
	printf("STRUCT: [ ");
	if (both->len == 0) {
		printf("]\n");
	} else {
		for (int i = 0; i < both->len-1; i++) {
			if (i==both->head) printf(">");			
			printf("%d", both->data[i]);
			if (i==both->top) printf("<");
			printf(" | ");
		}
		if (both->len-1==both->head) printf(">");			
		printf("%d", both->data[both->len-1]);
		if (both->len-1==both->top) printf("<");
		printf(" ]\n");
	}

	printf("FRONT : [%d] => %d\n", both->head, front(both));
	printf("TOP   : [%d] => %d\n", both->top, top(both));
	printf("TAIL  : [%d]\n", both->tail);
}

int is_empty(both* both)
{
	return (both->head == both->tail) || (both->head == -1 && both->tail == 0);
} 

void empty(both* both)
{
	both->head = -1;
	both->top = -1;
	both->tail = 0;
}

int size(both* both)
{
	if (both->tail>=both->head) return both->tail - both->head;
	else return both->len + both->tail - both->head;
}

int top(both* both)
{
	return both->data[both->top];
}

int front(both* both)
{
	return both->data[both->head];
}

void expand(both* both)
{
	both->data = (int*)realloc(both->data, both->len * 2);

	if (both->tail < both->head) {
		for (int i = both->head; i < both->len; i++) {
			both->data[i+both->len] = both->data[i];
		}
		both->head = both->head + both->len;
		
		/* Set all new indices to 0 */
		// To get theta(1) remove this
		for (int i = both->tail; i < both->head; i++) {
			both->data[i] = 0;
		} 
	} else {
		/* Set all new indices to 0 */
		// To get theta(1) remove this
		for (int i = both->len; i < both->len * 2; i++) {
			both->data[i] = 0;
		}
	}

	both->len *= 2;
}

void add_head(both* both, int value)
{
	if (size(both) == both->len-1) {
		printf("[ADD    HEAD] (%d) OVERFLOW: The structure is full. Expanding...\n", value);
		expand(both);
		printf("      The array can now contain %d elements.\n", both->len);
		print_struct(both);
		printf("  /---------------------/\n");
	}

	printf("[ADD    HEAD] (%d) ", value);

	if (is_empty(both)) {
		both->head = 0;
		both->top = 0;
		both->tail = 1;
	} else if (both->head == 0) {
		both->head = both->len-1;
	} else {
		both->head--;
	}
	both->data[both->head] = value;

	printf("%d has been added to the head of the structure.\n", value);
	printf("      The structure is now %d elements long.\n", size(both));
	print_struct(both);
	printf("  /---------------------/\n");
}

void add_tail(both* both, int value)
{
	if (size(both) == both->len-1) {
		printf("[ADD    TAIL] (%d) OVERFLOW: The structure is full. Expanding...\n", value);
		expand(both);
		printf("      The array can now contain %d elements.\n", both->len);
		print_struct(both);
		printf("  /---------------------/\n");
	}

	if (is_empty(both)) both->head=0;
	printf("[ADD    TAIL] (%d) ", value);
	both->data[both->tail] = value;

	if (is_empty(both)) {
		both->head = 0;
		both->top = 0;
		both->tail = 1;
	} else {
		if (both->tail+1 == both->len) {
			both->tail=0;
		} else {
			both->tail++;
		}

		if (both->top+1 == both->len) {
			both->top=0;
		} else {
			both->top++;
		}
	}
	
	printf("%d has been pushed to the structure.\n", value);
	printf("      The structure is now %d elements long.\n", size(both));
	print_struct(both);
	printf("  /---------------------/\n");
}

int delete_head(both* both)
{
	printf("[DELETE HEAD] ");

	if (is_empty(both)) {
		printf("UNDERFLOW: The structure is already empty.\n");
		print_struct(both);
		printf("  /---------------------/\n");
		return INVALID; // This is an arbitrary number. See struct.h for info.
	} else {
		int value = front(both);

		if (both->head == both->len-1)	{
			both->head = 0;
		} else if (both->head != both->top) {			
			both->head++;
		}

		printf("%d has been deleted from the structure.\n", value);
		printf("     The structure is now %d elements long.\n", size(both));
		print_struct(both);
		printf("  /---------------------/\n");
		return value;
	}
}

int delete_tail(both* both)
{
	printf("[DELETE TAIL] ");

	if(is_empty(both)){
		printf("UNDERFLOW: The structure is already empty.\n");
		print_struct(both);
		printf("  /---------------------/\n");
		return INVALID; // This is an arbitrary number. See both.h for info.
	} else {
		int value = top(both);

		if (both->tail == 0) {
			both->tail = both->len-1;
		} else {
			both->tail--;
		}

		if (both->top == 0) {
			both->top = both->len-1;
		} else {
			both->top--;
		}

		printf("%d has been popped from the structure.\n", both->data[both->top+1]);
		printf("     The structure is now %d elements long.\n", size(both));
		print_struct(both);
		printf("  /---------------------/\n");
		return value;
	}
}