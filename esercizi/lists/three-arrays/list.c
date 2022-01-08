#include "list.h"

void print_array(int* a, int len)
{
	printf("{");
	if(len>0){
		for(int i=0; i<len-1; i++)
			printf(" %d,", a[i]);
		printf(" %d ", a[len-1]);
	}
	printf("}\n");
}

void print_list(list* list)
{
	printf("NEXT: ");
	print_array(list->next, list->len);
	
	printf("INFO: ");
	print_array(list->info, list->len);
	
	printf("PREV: ");
	print_array(list->prev, list->len);

	printf("HEAD: %d\n", list->head);
	printf("FREE: %d\n", list->free);
	printf("SIZE: %d\n", size(list));

	printf("\n");
}

list* new_list(int maxSize)
{
	list* newList = (list*)calloc(1, sizeof(list));
	newList->next = (int*)calloc(maxSize, sizeof(int));
	newList->info = (int*)calloc(maxSize, sizeof(int));
	newList->prev = (int*)calloc(maxSize, sizeof(int));

	for (int i = 0; i < maxSize-1; i++) {
		newList->prev[i] = i-1;
		newList->next[i] = i+1;
	}

	newList->next[maxSize-1] = -1;
	newList->len = maxSize;
	newList->head = -1;
	newList->free = 0;
}

int is_empty(list* l)
{
	return l->head == -1;
}

int size(list* l)
{
	if (is_empty(l)) return 0;

	int a = 0;
	int i = l->head;
	while (i != -1) {
		i = l->next[i];
		a++;
	}
	return a;	
}

int search(list* l, int a)
{
	if (is_empty(l)) return INVALID;
	
	int i = l->head;
	while (i != -1) {
		if (l->info[i] == a) {
			printf("Found %d at index: %d\n", a, i);
			return i;
		}
		i = l->next[i];
	}

	printf("%d was not found.\n", a);
	return 0;
}

int allocate_column(list* l)
{
	if (l->free == -1) return INVALID;
	
	int i = l->free;
	l->free = l->next[l->free];
	if (l->free != -1) l->prev[l->free] = -1;
	
	return i;
}

void free_column(list* l, int i)
{
	l->prev[i] = -1;
	l->next[i] = l->free;
	if (l->free != -1) l->prev[l->free] = i;
	l->free = i;	
}

void insert(list* l, int a)
{
	printf("Adding %d to the list.\n", a);

	int i = allocate_column(l);
	l->info[i] = a;
	l->prev[i] = -1;
	l->next[i] = l->head;
	if (l->head != -1) l->prev[l->head] = i;
	l->head = i;
	
	printf("Took index n: %d\n", i);
}

void add(list* l, int a)
{
	if(is_empty(l)) {
		insert(l, a);
		return;
	}

	printf("Adding %d to the list.\n", a);
	int free = allocate_column(l);

	// Go to the last element of the list
	int i = l->head;
	while (l->next[i] != -1) {
		i = l->next[i];
	}
	l->next[i]=free;

	l->info[free] = a;
	l->prev[free] = i;
	l->next[free] = -1;

	printf("Took index n: %d\n", free);
}

void delete_index(list* l, int i)
{
	printf("Delete the element at index: %d\n", i);
	
	l->next[l->prev[i]] = l->next[i];
	l->prev[l->next[i]] = l->prev[i];
	free_column(l, i);
}

void delete_value(list* l, int a)
{
	printf("Delete the first element with value: %d\n", a);

	int i = search(l, a);

	if(i == INVALID) {
		printf("%d is not contained in the list.\n", a);
		return;
	}

	delete_index(l, i);
}

