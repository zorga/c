#include <stdlib.h>
#include <stdio.h>

int main (int argc, char** argv)
{
	
}

int* init1252 ()
{
	int* val = (int*) malloc (sizeof (int));
	if (val!=0)
		perror ("malloc");
	
	*val = 1252;
	return val;
}

int[] initTab1252 ()
{
	
}
