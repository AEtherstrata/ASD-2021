#include "hash.h"

int main()
{

	hashTable* tab = new_table();

	add_table(tab, 42, "Incolla");
	add_table(tab, 32, "Pronunciare");
	add_table(tab, 34, "Innocente");
	add_table(tab, 58, "Guadagni");
	add_table(tab, 57, "Ragazza");
	add_table(tab, 91, "Dodici");
	add_table(tab, 87, "Blu");
	add_table(tab, 65, "Sete");
	add_table(tab, 76, "Guado");
	add_table(tab, 29, "Integrale");

	print_table(tab);

	printf("Press enter to continue ");
	getchar();

	return 0;
}