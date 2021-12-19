#include "test.h"

void test_array(list* test)
{
	printf("Original: ");
	print_array(test->original, test->len);
	
	printf("Expected: ");
	print_array(test->expected, test->len);
	
	printf("Got:      ");
	print_array(test->result, test->len);
	
	int bad = 0;
	for(int i=0; i<test->len; i++){
		if(test->expected[i]!=test->result[i])
			bad = 1;
	}
	
	if(bad){
		printf("Bad sorting!\n\n");
	} else {
		printf("Good sorting!\n\n");
	}
	
}

void test_selection_sort(list* test)
{
	printf("/---- Selection Sort ----\\\n\n");
	
	while(test!=NULL){
		copy_array(test->original, test->result, test->len);
		selection_sort(test->result, test->len);
		test_array(test);
		test=test->next;
	}
}

void test_insertion_sort(list* test)
{
	printf("/---- Insertion Sort ----\\\n\n");
	
	while(test!=NULL){
		copy_array(test->original, test->result, test->len);
		insertion_sort(test->result, test->len);
		test_array(test);
		test=test->next;
	}
}

