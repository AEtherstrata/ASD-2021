#include "test.h"

int test_array(arrayList* test)
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

int test_counting_sort(arrayList* test)
{
	printf("/---- Counting Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;

	while(test!=NULL){
		// Do the sorting
		begin_counting_sort(test->original, test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_bucket_sort(arrayList* test)
{
	printf("/---- Bucket Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;

	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);

		begin_bucket_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

int test_radix_sort(arrayList* test)
{
	printf("/---- Radix Sort ----\\\n\n");
	
	int listCount = 0;
	int sortedCount = 0;

	while(test!=NULL){
		// Do the sorting
		copy_array(test->original, test->result, test->len);

		begin_radix_sort(test->result, test->len);
		
		// Keep count of sorted arrays
		listCount++;
		sortedCount += test_array(test);

		// Go to next array
		test=test->next;
	}

	if(listCount==sortedCount) return 1;
	else return 0;
}

void test_all_sort(arrayList* test)
{
	int result = 0;

	// Test all sorting algorithms and store the result code
	if (test_counting_sort(test)) set_bit(&result, 1);
	if (test_bucket_sort(test)) set_bit(&result, 2);
	if (test_radix_sort(test)) set_bit(&result, 3);

	// Display results
	printf("  /------------ SUMMARY -----------\\\n");

	if ((result & (1 << (1%32) )) != 0)
		 printf("  |  COUNTING SORT         :   OK  |\n");
	else printf("  |  COUNTING SORT         :   FAILED\n");

	if ((result & (1 << (2%32) )) != 0)
		 printf("  |  BUCKET SORT (R)       :   OK  |\n");
	else printf("  |  BUCKET SORT           :   FAILED\n");

	if ((result & (1 << (3%32) )) != 0)
		 printf("  |  RADIX SORT            :   OK  |\n");
	else printf("  |  RADIX SORT            :   FAILED\n");

	printf("  \\--------------------------------/\n\n");
}
