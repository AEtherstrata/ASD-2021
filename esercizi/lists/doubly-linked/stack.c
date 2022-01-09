#include "stack.h"

stack* new_stack()
{ 
	return new_list(); 
}

void push(stack* s, int a)
{
	add_tail(s, a);
}

int pop(stack* s)
{
	if(!is_empty(s)){
		int a = s->last->data;
		delete_tail(s);
		return a;
	}

	return -1;
}