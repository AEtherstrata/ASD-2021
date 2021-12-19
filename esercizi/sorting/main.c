#include "test.h"

int main(int argc, char **argv)
{
	list* arrayList = NULL;
	
	int empty[0];
	add_array_to_list(&arrayList, empty, empty, 0);
	
	int a[10]={0, -1, 4, 5, 1, 8, 8, 5, 3, -6};
	int a_s[10]={-6, -1, 0, 1, 3, 4, 5, 5, 8, 8};
	add_array_to_list(&arrayList, a, a_s, 10);
	
	int b[10]={85, 10, 63, 38, 89, 65, 65, 1, 99, 57};
	int b_s[10]={1, 10, 38, 57, 63, 65, 65, 85, 89, 99};
	add_array_to_list(&arrayList, b, b_s, 10);
	
	int c[10]={19, 74, 79, 16, 57, 44, 87, 11, 5, 39};
	int c_s[10]={5, 11, 16, 19, 39, 44, 57, 74, 79, 87};
	add_array_to_list(&arrayList, c, c_s, 10);
	
	int d[10]={44, 27, 58, 66, 81, 77, 37, 82, 7, 65};
	int d_s[10]={7, 27, 37, 44, 58, 65, 66, 77, 81, 82};
	add_array_to_list(&arrayList, d, d_s, 10);
	
	int e[10]={45, 6, 9, 43, 69, 34, 26, 90, 88, 22};
	int e_s[10]={6, 9, 22, 26, 34, 43, 45, 69, 88, 90};
	add_array_to_list(&arrayList, e, e_s, 10);
	
	int f[10]={-53, -86, -98, -26, 1, -26, 82, -67, -33, -34};
	int f_s[10]={-98, -86, -67, -53, -34, -33, -26, -26, 1, 82};
	add_array_to_list(&arrayList, f, f_s, 10);
	
	int g[10]={-32, -91, 45, -14, 2, 38, 70, 13, 89, 77};
	int g_s[10]={-91, -32, -14, 2, 13, 38, 45, 70, 77, 89};
	add_array_to_list(&arrayList, g, g_s, 10);
	
	test_selection_sort(arrayList);
	test_insertion_sort(arrayList);
	
	//TODO: merge sort
	
	return 0;
}
