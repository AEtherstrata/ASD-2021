#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct OVERFLOW_LIST_ELEMENT
{
	int									key;
	char*								string;
	struct OVERFLOW_LIST_ELEMENT*		next;

} OFListItem;

typedef struct HASH_TABLE
{
	int									m;				// Hash table size
	int									n;				// Number of inserted keys
	float								a;				// Ratio of occupied cells (n/m)
	OFListItem**						table;			// Pointer to the associative array
	double								irr;			// Irrational number used to hash the keys

} hashTable;

// Create a new empty table
hashTable* new_table();

// Print the table to console
void print_table(hashTable* table);

// Double the table size when needed
hashTable* expand_table(hashTable* table);

// Calculate the hash from a given key
int hash(hashTable* table, int key);

// Add a key to the table
void add_table(hashTable* table, int key, char* value);

// Get the value corresponding to the given key
char* get_value(hashTable* table, int key);

#endif
