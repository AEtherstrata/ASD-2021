#include "selection-sort.h"

void selection_sort(int* a, int l)
{
	for(int i=0; i<l-1; i++)
	{
		int min = i;
		for(int j=i+1; j<l; j++)
		{
			if(a[j]<a[min]){
				min = j;
			}
		}
		swap(&a[i], &a[min]);
	}
}