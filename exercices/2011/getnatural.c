#include <stdio.h>
#include <stdlib.h>
#include "getnatural.h"
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{	
	char string[] = "Coucou 1000";
	result* resultat = (result*) malloc(sizeof(result));//ne pas oublier d'allouer un espace mémoire pour la structure!!!
	getnatural(string, resultat);
	printf("%d \n", resultat->b);
	printf("%d \n", resultat->a);
	free(resultat);//ne pas oublier le free quand on n'a plus besoinn de la structure !!!
	return 0;		
}

int getnatural(char chaine[], result* resultat)
{	
	int i = 0;
	int pos = 0;
	char number[strlen(chaine)];
	int x = 0;
	char current_caract = 0;
	int boulet = 0;
	do
	{	//On parcourt le tableau de caractère jusqu'à trouver un premier chiffre et on le met dans la chaine qui contiendra le nombre final.
		current_caract = chaine[i];
		if(isNumeric(current_caract))
		{
			boulet = 1;
			pos = i;
			number[x] =  current_caract;
			x++;
			int j = i;
			j++;
			//Tant que le caractère suivant le premier chiffre trouvé est un chiffre aussi, on le rajoute dans la chaine qui contiendra le nombre.
			while(isNumeric(chaine[j]))
			{
				number[x] = chaine[j];
				j++;
				x++;
			}
		i = j;
			
		}
		i++;
	}
	while(current_caract != '\0');
	if(boulet == 0) //Si on a n'a pas trouvé de nombre, la fonction retourne -1
	{
		return -1;
	}
	unsigned int numb = strtol(number, NULL, 10); //Convertion de la chaine qui contient le nombre en int
	resultat->a = pos;//modification de la structure avec le nombre et sa position
	resultat->b = numb;	
	return 0;
}

int isNumeric(char a)//test si le charactère passé en argument est un chiffre ou non
{
	int u = 0;
	if( (a=='0') || (a=='1') || (a=='2') || (a=='3') || (a=='4') || (a=='5') || (a=='6') || 
(a=='7') || (a=='8') || (a=='9') )
	{
		u = 1;
	}
	return u;
}

