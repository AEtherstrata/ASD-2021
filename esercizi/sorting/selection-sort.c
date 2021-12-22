#include "selection-sort.h"

void selection_sort(int* a, int len)
{
	for(int i=0; i<len-1; i++)
	{
		int min = i;
		for(int j=i+1; j<len; j++)
		{
			if(a[j]<a[min]){
				min = j;
			}
		}
		swap(&a[i], &a[min]);
	}
}

void selection_sort_ric(int* a, int len, int i)
{
	if (i<len){
		int min = i;
		for (int j=i+1; j<len; j++){
			if (a[j] < a[min])
				min = j;
		}
		swap(&a[i], &a[min]);
		selection_sort_ric(a, len, i+1);
	}
}

void begin_recursive_selection_sort(int* a, int len){
	selection_sort_ric(a, len, 0);
}