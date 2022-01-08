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
		printf("HEAD == LAST = %d\n", l->head==l->last);
		printf("HEAD == NULL = %d\n", l->head==NULL);
		printf("LAST == NULL = %d\n\n", l->last==NULL);
	}
	else {
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

	l->head == NULL;
	l->last == NULL;

	print_list(l);
}

void add_head(list* l, int a)
{
	listItem* add = allocate_object(a);
	add->next = l->head;
	if(is_empty(l)) l->last = add;
	if(!is_empty(l)) l->head->prev = add;
	l->head = add;
	printf("%d has been added to the head.\n", add->data);
	
	print_list(l);
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
	
	print_list(l);
}

void delete_element(list* l, listItem* i)
{
	printf("%d has been deleted.\n", i->data);
	
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
	listItem* i = l->head;
	delete_element(l , i);
}

void delete_tail(list* l)
{
	listItem* i = l->last;
	delete_element(l , i);
}