#include "counting-sort.h"

void counting_sort(int* in, int* out, int len, int max)
{
	if (len <= 1) return; //The arrays is already sorted

	max++;

	int equals[max]; //Number of elements with value = index
	int lower[max];  //Number of elements with value < index

	// Set all indices to 0
	for (int i = 0; i < max; i++) {
		equals[i] = 0;
		lower[i] = 0;
	}
	
	// Count all elements that equals the array index
	for (int i = 0; i < len; i++)
	{
		equals[in[i]]++;
	}

	// Sum all elements that are lower than the array index
	for (int i = 1; i < max; i++)
	{
		lower[i] = equals[i-1] + lower[i-1];
	}
	
	// Make the output array
	for (int i = 0; i < len; i++)
	{
		out[lower[in[i]]] = in[i];
		lower[in[i]] = lower[in[i]] + 1;
	}
}

void begin_counting_sort(int* in, int* out, int len)
{
	if (in == NULL) return;
	int max = max_value(in, len);
	counting_sort(in, out, len, max);
}