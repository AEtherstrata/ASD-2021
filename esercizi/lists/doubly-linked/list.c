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
		printf("Empty list.\n\n");
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

	printf("Emptying the list:\n");
	
	while (l->head != NULL)
	{
		l->head = l->head->next;
 
        printf("Deleting %d\n", p->data);
        free(p);
        p = l->head;
	}

	print_list(l);
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
	printf("%d has been added to the head.\n", add->data);
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

	printf("%d has been added to the tail.\n", add->data);
}

void delete_element(list* l, listItem* i)
{
	printf("%d has been deleted.\n\n", i->data);
	
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