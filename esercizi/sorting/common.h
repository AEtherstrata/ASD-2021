#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ARRAY_LIST {
	int* original;
	int* expected;
	int* result;
	int len;
	struct ARRAY_LIST* next; 
} list;

void swap(int *x, int *y);

void print_array(int* a, int len);

void copy_array(int* origin, int* destination, int len);

void add_array_to_list(list** l, int* original, int* expected, int len);

#endif