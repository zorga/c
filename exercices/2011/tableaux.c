#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"

int i = 0;

int main(int argc, char *argv[])
{
	int tableau[10];
	tableau[0] = 987;
	tableau[1] = 4;
	tableau[2] = 89;
	tableau[3] = 342;
	sort(tableau, 4);
	display(tableau, 4);
	return 0;
}

void display(int* tableau, int tailleTableau)
{
	int j;
	for(j=0; j<tailleTableau ; j++)
	{
		printf("La valeur courante est : %d \n", *(tableau+j));
	}	
}

void sort(int tableau[], int tailleTableau)
{
	int i; int j; int k;
	for(i=0; i<tailleTableau; i++)
	{
		if(tableau[i]>tableau[i+1])
		{
			j = tableau[i+1];
			k = tableau[i];
			tableau[i]=j;
			tableau[i+1]=k;
		}	
		else{}
	}	
}

