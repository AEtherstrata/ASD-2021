#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct LIST_ITEM {
	int data;
	struct LIST_ITEM* next;
	struct LIST_ITEM* prev;
} listItem;

typedef struct LIST {
	listItem* head;
	listItem* last;
} list;

list* new_list();

listItem* allocate_object(int value);

void print_list(list* l);

int is_empty(list* list);

void empty(list* list);

listItem* search(list* list, int value);

void add_head(list* list, int value);

void add_tail(list* list, int value);

void add_before(list* list, listItem* item, int value);

void add_after(list* list, listItem* item, int value);

void insert_ordered(list* list, int value);

void delete_element(list* list, listItem* item);

void delete_head(list* list);

void delete_tail(list* list);

void delete_value(list* list, int value);

int common(list* list1, list* list2);

list* reverse(list* list);

void list_enqueue(list* l1, list* l2);

list* sort(list* l);

list* merge(list* l1, list* l2);

#endif