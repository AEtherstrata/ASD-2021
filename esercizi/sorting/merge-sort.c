#include "merge-sort.h"

/* This function merges the split arrays */
void merge(int* a, int begin, int medium, int end)
{
	int l1 = medium - begin + 1;
	int l2 = end - medium;
	int i, j, k;
	
	// Create temp arrays
	int left[l1], right[l2];
	
	// Copy data to temp arrays
	for(i=0; i<l1; i++)
		left[i] = a[begin+i];
		
	for(j=0; j<l2; j++)
		right[j] = a[medium+1+j];
	
	// Reset the counters
	i = 0;
	j = 0;
	k = begin;
	
	//Merge the temp arrays
	while(i<l1 && j<l2){
		if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
		k++;
	}
	
	// Copy the remaining elements
	while(i<l1){
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<l2){
		a[k]=right[j];
		j++;
		k++;
	}
}

/* This function splits the array */
void merge_sort(int* a, int begin, int end)
{
	if (begin<end){
		int medium = (begin + end) / 2;
		merge_sort(a, begin, medium);
		merge_sort(a, medium+1, end);
		merge(a, begin, medium, end);
	}
}

void begin_merge_sort(int* a, int len)
{
	merge_sort(a, 0, len-1);
}