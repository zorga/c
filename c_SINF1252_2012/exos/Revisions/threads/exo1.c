#include <stdio.h>
#include <stdlib.h>

#define SIZE 2

typedef struct fraction
{
	int num;
	int den;
} fraction_t;

fraction_t a = {1, 2};
fraction_t b = {1, 4};
fraction_t* array[SIZE] = {&a, &b};

void print_array (fraction_t* array[])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf ("Element [%d] : [%d/%d]\n", i, array[i]->num, array[i]->den);
		printf ("i : [%d]\n", i);
	}
}

int cmp (const void* ptr1, const void* ptr2)
{
	fraction_t* fract1 = (fraction_t*) ptr1;
	fraction_t* fract2 = (fraction_t*) ptr2;
	int i = (fract1->num)*(fract2->den);
	int j = (fract2->num)*(fract1->den);

	if (i == j)
		return 0;

	else if (i > j)
		return 1;

	else if (i < j)
		return -1;

	exit (EXIT_SUCCESS);
}

int main (int argc, char** argv)
{
	printf ("Avant qsort : \n\n");
	print_array (array);
	qsort (array, SIZE, sizeof (fraction_t), cmp);
	printf ("Après qsort : \n\n");
	print_array (array);
}
