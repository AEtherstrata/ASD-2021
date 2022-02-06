#ifndef _TEST_H
#define _TEST_H

#include "common.h"

#include "counting-sort.h"
#include "bucket-sort.h"
#include "radix-sort.h"

int test_array(arrayList* test);

int test_counting_sort(arrayList* test);

int test_bucket_sort(arrayList* test);

int test_radix_sort(arrayList* test);

void test_all_sort(arrayList* test);

#endif