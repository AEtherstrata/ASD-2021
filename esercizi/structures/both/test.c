#include <time.h>
#include "test.h"

int test_add_head(both* both, int exp)
{
	add_head(both, exp);
	return exp == front(both);
}

int test_add_tail(both* both, int exp)
{
	add_tail(both, exp);
	if (both->tail == 0) return exp == both->data[both->len-1];
	return exp == top(both);
}

int test_delete_head(both* both, int exp)
{
	int deleted = delete_head(both);
	return deleted == exp;
}

int test_delete_tail(both* both, int exp)
{
	int deleted = delete_tail(both);
	return deleted == exp;
}

void test_both_struct(both* both, osuProfile* osuID)
{
	srand(time(0));
	int good = 0;
	int lastAddedHead = osuID->data[0];
	int lastAddedTail = osuID->data[0];

	// Add all array values to struct
	for (int i = 0; i < osuID->len; i++) 
	{
		if (rand()%2==0) {
			good = test_add_head(both, osuID->data[i]);
			lastAddedHead = front(both);
			printf("      lastAddedHead = %d\n", lastAddedHead);
			printf("      lastAddedTail = %d\n", lastAddedTail);
			printf("  /---------------------/\n");
			if (!good) goto end;
		} else { 
			good = test_add_tail(both, osuID->data[i]);
			lastAddedTail = top(both);		
			printf("      lastAddedHead = %d\n", lastAddedHead);	
			printf("      lastAddedTail = %d\n", lastAddedTail);
			printf("  /---------------------/\n");
			if (!good) goto end;
		}

		if (rand()%5==0)
		{
			good = test_delete_head(both, lastAddedHead);
			lastAddedHead = front(both);
			printf("      lastAddedHead = %d\n", lastAddedHead);
			printf("      lastAddedTail = %d\n", lastAddedTail);
			printf("  /---------------------/\n");
			if (!good) goto end;
		}
	
		if(rand()%7==0){
			good = test_delete_tail(both, lastAddedTail);
			lastAddedTail = top(both);
			printf("      lastAddedHead = %d\n", lastAddedHead);
			printf("      lastAddedTail = %d\n", lastAddedTail);
			printf("  /---------------------/\n");
			if (!good) goto end;
		}
	}

	end:
	if (good) {
		printf("STRUCT :   OK\n");
	} else {
		printf("STRUCT : FAILED\n");
	}
}