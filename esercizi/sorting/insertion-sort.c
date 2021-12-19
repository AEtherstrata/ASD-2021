#include "insertion-sort.h"

void insertion_sort(int* a, int len)
{
	for (int i=0; i<len; i++){
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
	}
}