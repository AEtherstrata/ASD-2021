#ifndef _TEST_H
#define _TEST_H

#include "struct.h"

typedef struct USER_ID_ARRAY {
	int* data;
	int len;
} osuProfile;

int test_add_head(both* both, int exp);

int test_add_tail(both* both, int exp);

int test_delete_head(both* both, int exp);

int test_delete_tail(both* both, int exp);

void test_both_struct(both* both, osuProfile* osuID);

#endif