#include "test.h"

int test_array(list* test)
{
	printf("Original: ");
	print_array(test->original, test->len);
	
	printf("Expected: ");
	print_array(test->expected, test->len);
	
	printf("Got:      ");
	print_array(test->result, test->len);
	
	int isSorted = 1;
	for(int i=0; i<test->len; i++){
		if(test->expected[i]!=test->result[i]){
			isSorted = 0;
			break;
		}
	}
	
	if(isSorted){
		printf("Good sorting!\n\n");
	} else {
		printf("Bad sorting!\n\n");
	}
	
	return isSorted;
}

int test_bubble_sort(list* test)
{
	printf("/---- Bubble Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		bubble_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_recursive_bubble_sort(list* test)
{
	printf("/---- Bubble Sort (R) ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		bubble_sort_ric(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_selection_sort(list* test)
{
	printf("/---- Selection Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		selection_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_recursive_selection_sort(list* test)
{
	printf("/---- Selection Sort (R) ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		begin_recursive_selection_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_insertion_sort(list* test)
{
	printf("/---- Insertion Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		insertion_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_recursive_insertion_sort(list* test)
{
	printf("/---- Insertion Sort (R) ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		insertion_sort_ric(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_merge_sort(list* test)
{
	printf("/---- Merge Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;
	
	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		begin_merge_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test_array(test);
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_quick_sort(list* test)
{
	printf("/---- Quick Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;

	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);
		begin_quick_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

void test_all_sort(list* test)
{
	int result = 0;

	// Test all sorting algorithms and store the result code
	if (test_bubble_sort(test)) set_bit(&result, 1);
	if (test_recursive_bubble_sort(test)) set_bit(&result, 2);
	if (test_selection_sort(test)) set_bit(&result, 3);
	if (test_recursive_selection_sort(test)) set_bit(&result, 4);
	if (test_insertion_sort(test)) set_bit(&result, 5);
	if (test_recursive_insertion_sort(test)) set_bit(&result, 6);
	if (test_merge_sort(test)) set_bit(&result, 7);
	if (test_quick_sort(test)) set_bit(&result, 8);

	// Display results
	printf("  /------------ SUMMARY -----------\\\n");

	if ((result & (1 << (1%32) )) != 0)
		 printf("  |  BUBBLE SORT           :   OK  |\n");
	else printf("  |  BUBBLE SORT           :   FAILED\n");

	if ((result & (1 << (2%32) )) != 0)
		 printf("  |  BUBBLE SORT (R)       :   OK  |\n");
	else printf("  |  BUBBLE SORT (R)       :   FAILED\n");

	if ((result & (1 << (3%32) )) != 0)
		 printf("  |  SELECTION SORT        :   OK  |\n");
	else printf("  |  SELECTION SORT        :   FAILED\n");

	if ((result & (1 << (4%32) )) != 0)
		 printf("  |  SELECTION SORT (R)    :   OK  |\n");
	else printf("  |  SELECTION SORT (R)    :   FAILED\n");

	if ((result & (1 << (5%32) )) != 0)
		 printf("  |  INSERITION SORT       :   OK  |\n");
	else printf("  |  INSERITION SORT       :   FAILED\n");

	if ((result & (1 << (6%32) )) != 0)
		 printf("  |  INSERITION SORT (R)   :   OK  |\n");
	else printf("  |  INSERITION SORT (R)   :   FAILED\n");

	if ((result & (1 << (7%32) )) != 0)
		 printf("  |  MERGE SORT            :   OK  |\n");
	else printf("MERGE SORT            :   FAILED\n");

	if ((result & (1 << (8%32) )) != 0)
		 printf("  |  QUICK SORT            :   OK  |\n");
	else printf("  |  QUICK SORT            :   FAILED\n");

	printf("  \\--------------------------------/\n\n");
}
