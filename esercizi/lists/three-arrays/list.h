#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

#define INVALID -1

typedef struct LIST
{
	int* 	next;	// Array containing the indices of the next elements
	int* 	info;	// Array containing the data
	int* 	prev;	// Array containing the indices of the previous elements
	int		head;	// First allocated index
	int		free;	// First free index
	int		len;	// Length of the arrays
} list;

// Prints an array
void print_array(int * a, int len);

// Prints a list
void print_list(list* list);

// Allocate a new list
list* new_list(int maxSize);

// Returns true if the list is empty
int is_empty(list* list);

// Get the size of the list
int size(list* list);

// Return the index of the requested value
int search(list* list, int value);

// Get a free index from the array
int allocate_column(list* list);

// Return a free index to the array
void free_column(list* list, int index);

// Add a value to the head of the list
void insert(list* list, int value);

// Add a value to the tail of the list
void add(list* list, int value);

// Delete the element at a specified index
void delete_index(list* list, int index);

// Delete the first element with the specified value
void delete_value(list* list, int value);

#endif