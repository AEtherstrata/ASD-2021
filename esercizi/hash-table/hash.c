#include "hash.h"

hashTable* new_table()
{
	hashTable* newTable = (hashTable*)malloc(sizeof(hashTable));

	newTable->m = 10;
	newTable->n = 0;
	newTable->a = 0;
	newTable->irr = (sqrt(5.0)-1.0)*0.5;
	newTable->table = (OFListItem**)calloc(newTable->m, sizeof(OFListItem*));
	return newTable;
}

void print_table(hashTable* t)
{
	printf("Hash table: n=%d, m=%d, a=%.2f\n", t->n, t->m, t->a);

	for (int i = 0; i < t->m; i++)
	{
		printf("[%d]", i);
		OFListItem* x = t->table[i];
		while (x != NULL)
		{
			printf(" -> k=%d, v='%s'", x->key, x->string);
			x = x->next;
		}
		printf("\n");
	}
}

hashTable* expand_table(hashTable* t)
{
	OFListItem** oldArray = t->table;
	int oldSize = t->m;

	/* Double the size of the table */
	
	t->m *= 2;
	t->table = (OFListItem**)calloc(t->m, sizeof(OFListItem*));

	/* Move the stored values to the new corresponding places */

	for (int i = 0; i < oldSize; i++)				// Iterate all array indices
	{
		while (oldArray[i] != NULL)					// Iterate all list elements
		{
			int index = hash(t, oldArray[i]->key);	// Calculate the new hash of the key
			oldArray[i]->next = t->table[index];	// Move the element to the right list
			t->table[index] = oldArray[i];			// And add it to its head

			oldArray[i] = oldArray[i]->next;
		}
	}
	free(oldArray);									// Delete the old table now
	t->a = (float)t->n / t->m;

	return t;
}

int hash(hashTable* t, int k)
{
	double hash = k * t->irr;
	hash = hash - (int)hash;	// Leaves only the decimal part of the number (0...1)

	hash = hash * t->m;			// Now multiply it for the table size and get the associated cell

	return hash;				// Implicit cast to int
}

void add_table(hashTable* t, int k, char* v)
{
	if (t->a >= 2) {						// Double the table size
		t = expand_table(t);
	}

	int i = hash(t, k);					// Calculate the index of the array to put the new key in
	printf("Key %d has hash: %d\n", k, i);

	OFListItem* x = t->table[i];		// Initialize the iterator

	while (x != NULL)					// Scroll all the list elements until the end
	{
		if (x->key == k) {				// If the key has a corresponding value already, overwrite it
			x->string = v;
			return;
		}

		x = x->next;
	}

	/* If the code is here it means the key is not in the array already. Add it to the head */

	OFListItem* newElem = (OFListItem*)malloc(sizeof(OFListItem));
	newElem->key = k;
	newElem->string = v;
	newElem->next = t->table[i];
	t->table[i] = newElem;
	t->n++;
	t->a = (float)t->n / t->m;

	printf("New node with info: k=%d, v=%s\n", newElem->key, newElem->string);
}

char* get_value(hashTable* t, int k)
{
	int i = hash(t, k);					// Calculate the index of the array to look into
	OFListItem* x = t->table[i];		// Initialize the iterator

	while (x != NULL)					// Scroll all the list elements to search the desired key
	{
		if (x->key == k)				// Return the corresponding string if found
			return x->string;

		x = x->next;
	}

	return NULL;						// Else return NULL
}	