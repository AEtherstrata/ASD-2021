#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../trees/binary-tree/tree.h"

typedef struct HEAP_STRUCT {
	int		size;
	int 	len;
	int*	array;
} heap;

void print_heap(heap* h);

heap* new_heap(int size);

int h_parent(int index);

int h_left(int index);

int h_right(int index);

int is_heap_empty(heap* heap);

int maximum(heap* heap);

void swap_cells(int* array, int index1, int index2);

void max_heap(heap* heap, int index);

void build_max_heap(heap* heap);

int return_max(heap* h);

void insert(heap* h, int key);

#endif