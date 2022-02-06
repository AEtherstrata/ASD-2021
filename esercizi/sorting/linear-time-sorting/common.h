#ifndef _COMMON_H
#define _COMMON_H

#include "../../lists/doubly-linked/list.h"

typedef struct ARRAY_LIST {
	int* original;
	int* expected;
	int* result;
	int len;
	struct ARRAY_LIST* next; 
} arrayList;

typedef list bucket;

typedef listItem bucketItem;

void swap(int *x, int *y);

void print_array(int * a, int len);

void copy_array(int* a, int* b, int len);

void add_array_to_list(arrayList** l, int* original, int* expected, int len);

void set_bit(int* var, int k);

int max_value(int* a, int len);

#endif