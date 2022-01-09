#ifndef _STACK_H
#define _STACK_H

#include "list.h"

typedef list stack;

stack* new_stack();

void push(stack* s, int a);

int pop(stack* s);

#endif