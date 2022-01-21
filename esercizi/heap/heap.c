#include "heap.h"

void print_heap(heap* h)
{
	if(is_heap_empty(h)){
		printf("Heap is empty!\n");
		return;
	}

	printf("{");
	for (int i = 0; i < h->size-1; i++)
	{
		printf(" %d |", h->array[i]);
	}
	printf(" %d }\n\n", h->array[h->size-1]);
	
	int i=0, c=0, t=1;
	while (i < h->size) {
		while(c<t) {
			printf("%d ", h->array[i]);
			i++;
			c++;
		}
		t*=2;
		c=0;
		printf("\n");
	}
}

heap* new_heap(int maxSize)
{
	heap* newHeap = (heap*)malloc(sizeof(heap));
	newHeap->size = 0;
	newHeap->len = maxSize;
	newHeap->array = (int*)calloc(maxSize, sizeof(int));
}

int h_parent(int i)
{
	return (i-1)/2;
}

int h_left(int i)
{
	return 2*i+1;
}

int h_right(int i)
{
	return 2*i+2;
}

int is_heap_empty(heap* h)
{
	return h->size == 0;
}

int maximum(heap* h)
{
	return h->array[0];
}

void swap_cells(int* a, int i1, int i2)
{
	int tmp = a[i1];
	a[i1] = a[i2];
	a[i2] = tmp;
}

void max_heap(heap* h, int i)
{
	if (i>(h->size/2)-1) return;	

	int l = h_left(i);
	int r = h_right(i);
	int max = i;
	if (l<=h->size-1 && h->array[l] > h->array[i]) max = l;
	if (r<=h->size-1 && h->array[r] > h->array[i]) max = r;
	if (max!=i){
		swap_cells(h->array, i, max);
		max_heap(h, max);
	}
}

void build_max_heap(heap* h)
{
	h->size = h->len;
	for (int i = (h->len/2)-1; i>0; i--)
	{
		max_heap(h, i);
	}
}

int return_max(heap* h)
{
	if(is_heap_empty(h)){
		printf("UNDERFLOW: Heap is already empty!\n");
		exit(1);
	}

	int max = h->array[0];
	h->array[0] = h->array[h->size-1];
	h->size = h->size-1;
	max_heap(h, 0);
	return max;
}

void insert(heap* h, int key)
{
	if(h->size == h->len){
		h->len *= 2;
		h->array = realloc(h->array, h->len);
	}

	int i = h->size;
	h->size++;

	while(i>0 && h->array[h_parent(i)] < key){
		h->array[i] = h->array[h_parent(i)];
		i = h_parent(i);
	}
	h->array[i] = key;
}

void heap_sort(int* a, int len)
{
	heap* temp = (heap*)malloc(sizeof(heap));
	temp->array = a;
	temp->size = len;
	temp->len = len;
	build_max_heap(temp);
	for (int i = temp->size-1; i > 0; i--)	{
		swap_cells(temp->array, 0, i);
		temp->size--;
		max_heap(temp, 0);
	}
	
}