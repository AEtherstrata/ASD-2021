#include "common.h"

/* Swap two integer values */
void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Print an array */
void print_array(int * a, int len)
{
	printf("{");
	if(len>0){
		for(int i=0; i<len-1; i++)
			printf(" %d,", a[i]);
		printf(" %d ", a[len-1]);
	}
	printf("}\n");
}

/* Makes a copy of the original array to work with */
void copy_array(int* a, int* b, int len)
{
	for (int i=0; i<len; i++){
		b[i]=a[i];
	}
}

/* Add a new array to the head of the test list */
void add_array_to_list(list** l, int* original, int* expected, int len)
{
	list* newElement = (list*)malloc(sizeof(list)); // Allocate a new list node
	
	int* result = (int*)malloc(sizeof(int)*len);    // Allocate space for a mirrored origin array
	
	newElement->original=original;
	newElement->expected=expected;
	newElement->result=result;
	newElement->len=len;
	newElement->next=*l;
	*l=newElement;
}