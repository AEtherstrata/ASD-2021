#ifndef _TEST_H
#define _TEST_H

#include "common.h"

#include "bubble-sort.h"
#include "selection-sort.h"
#include "insertion-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"

void test_array(list* test);

void test_bubble_sort(list* test);
void test_recursive_bubble_sort(list* test);

void test_selection_sort(list* test);
void test_recursive_selection_sort(list* test);

void test_insertion_sort(list* test);
void test_recursive_insertion_sort(list* test);

void test_merge_sort(list* test);

void test_quick_sort(list* test);

#endif
