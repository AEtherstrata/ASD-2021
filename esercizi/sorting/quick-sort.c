#include "quick-sort.h"

int partition(int* a, int begin, int end)
{
	int pivot = a[end];
	int i = (begin-1);

	for (int j = begin; j < end; j++)
	{
		if (a[j]<pivot)
		{			
			i++;
			swap(&a[i], &a[j]);
		}

	}

	swap(&a[i+1], &a[end]);
	return i+1;
}

void quick_sort(int* a, int begin, int end)
{
	if (begin<end)
	{
		// Partitioning index
		int idx = partition(a, begin, end);

		// Sort elements before and after the partition
		quick_sort(a, begin, idx-1);
		quick_sort(a, idx+1, end);
	} 
}

void begin_quick_sort(int*a, int len)
{
	quick_sort(a, 0, len-1);
}