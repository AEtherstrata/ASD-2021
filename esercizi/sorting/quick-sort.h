#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include "common.h"

int partition(int* a, int begin, int end);

void quick_sort(int* a, int begin, int end);

void begin_quick_sort(int* a, int len);

#endif