#include "list.h"

list* new_list()
{
	list* newList = (list*)malloc(sizeof(list));
	newList->head = NULL;
	newList->last = NULL;
	return newList;
}

listItem* allocate_object(int a)
{
	listItem* newObj = (listItem*)malloc(sizeof(listItem));
	newObj->data = a;
	newObj->next = NULL;
	newObj->prev = NULL;
	return newObj;
}

void print_list(list* l)
{
	if(is_empty(l)) {
		printf("Empty list.\n");
	} else {
		listItem* i = l->head;
		while (i->next != NULL)
		{
			printf("%d -> ", i->data);
			i = i->next;
		}
		printf("%d\n", i->data);
	}
}

void print_list_verbose(list* l)
{
	if(is_empty(l)) {
		printf("Empty list.\n");
	} else {
		listItem* i = l->head;
		while (i != NULL)
		{
			printf("%d -> ", i->data);
			i = i->next;
		}
		printf("NULL\n");	
		printf("HEAD : %d  /  LAST : %d\n\n", l->head->data, l->last->data);	
	}
}

int is_empty(list* l)
{
	return l->head == NULL;
}

void empty(list* l)
{
	listItem* p = l->head;
	
	while (l->head != NULL)
	{
		l->head = l->head->next;
 
        free(p);
        p = l->head;
	}
}

listItem* search(list* l, int a)
{
	listItem* i = l->head;
	while (i != NULL) {
		if ( i->data == a )
			return i;
		i = i->next;
	}
	return NULL;
}

void add_head(list* l, int a)
{
	listItem* add = allocate_object(a);
	add->next = l->head;
	if(is_empty(l)) l->last = add;
	if(!is_empty(l)) l->head->prev = add;
	l->head = add;
}

void add_tail(list* l, int a)
{
	if(is_empty(l)) {
		add_head(l, a);
		return;
	}

	listItem* add = allocate_object(a);
	l->last->next = add;
	add->prev = l->last;
	l->last = add;
}

void add_before(list* l, listItem* i, int a)
{
	if(is_empty(l)) {
		add_head(l, a);
		return;
	}

	listItem* add = allocate_object(a);

	if (i->prev != NULL) {
		add->prev = i->prev;
		add->next = i;
		i->prev->next = add;
		i->prev = add;
	} else {
		add_head(l, a);
	}
}

void add_after(list* l, listItem* i, int a)
{
	if(is_empty(l)) {
		add_head(l, a);
		return;
	}

	listItem* add = allocate_object(a);

	if (i->next != NULL){		
		add->prev = i;
		add->next = i->next;
		i->next->prev = add;
		i->next = add;
	} else {
		add_tail(l, a);
	}
}

void delete_element(list* l, listItem* i)
{
	if( i == NULL ) return;

	if (i->prev != NULL) {
		i->prev->next = i->next;
	} else {
		l->head = i->next;
	}

	if (i->next != NULL){
		i->next->prev = i->next;
	} else {
		l->last = i->prev;
	}

	free(i);
}

void delete_head(list* l)
{
	delete_element(l , l->head);
}

void delete_tail(list* l)
{
	delete_element(l , l->last);
}

void delete_value(list* l, int a)
{
	delete_element(l, search(l, a));
}

int common(list* l1, list* l2)
{
	if (is_empty(l1) || is_empty(l2)) return 0;

	int count = 0;

	listItem* i = l1->head;
	while (i != NULL) {
		if(search(l2, i->data) != NULL) count++;
		i = i->next;
	}

	return count;
}

list* reverse(list* l)
{
	if(is_empty(l)) return NULL;

	list* reverseList = new_list();

	listItem* i = l->head;
	while (i != NULL) {
		add_head(reverseList, i->data);
		i = i->next;
	}

	return reverseList;
}

void list_enqueue(list* l1, list* l2)
{
	if (is_empty(l2)) return;

	listItem* i = l2->head;
	while (i != NULL) {
		add_tail(l1, i->data);
		i = i->next;
	}
}

void insert_ordered(list* l, int a)
{
	if(is_empty(l)) {
		add_head(l, a);
		return;
	}

	listItem* i = l->head;
	while ( i != NULL ) {
		if(	i->data > a){
			add_before(l, i ,a);
			return;
		}
		if( i->next == NULL ){
			add_tail(l, a);
			return;
		}
		i = i->next;
	}
}

list* sort(list* l)
{
	list* sorted = new_list();
	listItem* i = l->head;

	while (i != NULL) {
		insert_ordered(sorted, i->data);
		i = i->next;
	}

	empty(l);
	return sorted;
}

list* merge(list* l1, list* l2)
{
	list* merged = new_list();
	listItem* i1 = l1->head;
	listItem* i2 = l2->head;

	if (is_empty(l1) && is_empty(l2)) return NULL;

	while (i1 != NULL && i2 != NULL)
	{
		if (i1->data <= i2->data) // Precedence yielded to list1
		{
			add_tail(merged, i1->data);
			i1 = i1->next;
		} else {
			add_tail(merged, i2->data);
			i2 = i2->next;
		}
		
	}
	while (i1 != NULL)
	{
		add_tail(merged, i1->data);
		i1 = i1->next;
	}
	while (i2 != NULL)
	{
		add_tail(merged, i2->data);
		i2 = i2->next;
	}
	
	return merged;
}

int first_equals_last(list* l)
{
	if (is_empty(l))
	{
		printf("The list is empty! Exiting...\n");
		exit(1);
	}
	
	int first = l->head->data;
	int last = l->last->data;

	return (first == last) ? 1 : 0;
}

int first_equals_last_no_pointer(list* l)
{
	if (is_empty(l))
	{
		printf("The list is empty! Exiting...\n");
		exit(1);
	}

	listItem* x = l->head;
	while (x->next != NULL)
	{
		x = x->next;
	}

	return (l->head->data == x->data) ? 1 : 0;
}