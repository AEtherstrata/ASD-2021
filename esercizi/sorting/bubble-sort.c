#include "bubble-sort.h"

void bubble_sort(int* a, int len)
{
	for (int i = 0; i < len-1; i++){
		for(int j = 0; j<len-i-1; j++){
			if(a[j]>a[j+1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

void bubble_sort_ric(int* a, int len)
{
	if (len <= 1) return;

	for (int i = 0; i < len-1; i++){
		if (a[i] > a[i+1]){
			swap(&a[i],&a[i+1]);
		}
	}

	bubble_sort_ric(a, len-1);
}
