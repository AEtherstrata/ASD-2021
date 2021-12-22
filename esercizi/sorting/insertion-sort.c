#include "insertion-sort.h"

void insertion_sort(int* a, int len)
{
	for (int i=0; i<len; i++){
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void insertion_sort_ric(int* a, int len)
{
	if(len<=1) return;
	
	insertion_sort_ric(a, len-1);
	
	int last = a[len-1];
	int j = len-2;

	while(j>=0 && a[j]>last)
	{
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = last;
}
