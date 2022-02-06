#include "radix-sort.h"

// Use counting sort to sort elements in the basis of significant places
void radix_sort(int* arr, int len, int place)
{
	int output[len];
    int i = 0;
	int count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < len; i++) {
        count[(arr[i] / place) % 10]++;
	}
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
	}
    // Build the output array
    for (i = len - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    } 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < len; i++) {
        arr[i] = output[i];
	}
}

void begin_radix_sort(int* a, int len)
{
	if (len <= 1) return; //The as is already sorted

	int max = max_value(a, len);

	for (int digit = 1; max/digit > 0; digit *= 10)
	{
		radix_sort(a, len, digit);
	}	
}