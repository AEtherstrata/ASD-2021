#include "bucket-sort.h"

void bucket_sort(int* a, int len, int max)
{
	if (len <= 1) return; // The array is already sorted

	max++;

	bucket* bucketArray[max];

	// Initialize all buckets to NULL
	for (int i = 0; i < max; i++)
	{
		bucketArray[i] = new_list();
	}
	
	// Add the values to the corresponding bucket
	for (int i = 0; i < len; i++)
	{
		add_tail(bucketArray[a[i]], a[i]);
	}

	// Now put the values from the bucket array to the right place
	int i = len-1;
	for (int j = max-1; j > 0; j--)
	{
		while (!is_empty(bucketArray[j]))
		{
			a[i] = bucketArray[j]->head->data;
			delete_tail(bucketArray[j]);
			i--;
		}
	}
}

void begin_bucket_sort(int* a, int len)
{
	if (a == NULL) return;
	int max = max_value(a, len);
	bucket_sort(a, len, max);	
}