#ifndef _TEST_H
#define _TEST_H

#include "selection-sort.h"
#include "insertion-sort.h"
#include "common.h"
#include "merge-sort.h"

void test_array(list* test);

void test_selection_sort(list* test);

void test_recursive_selection_sort(list* test);

void test_insertion_sort(list* test);

void test_recursive_insertion_sort(list* test);

void test_merge_sort(list* test);

#endif
