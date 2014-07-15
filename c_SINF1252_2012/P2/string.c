#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
//TESTS
{

	printf("Veuillez taper une commande (strlen, strcat, ou strcasecmp) : ");
	char* entry;
	entry = malloc(100*sizeof(char));
	scanf("%s", entry);
	if(strcmp(entry,"strlen")==0)
	{
		char* str = malloc(100*sizeof(char));
		printf("Veuillez entrer une chaine de caractères : ");
		scanf("%s", str);
		printf("%ld\n", strlen(str));
		free(str);
	}
	else if(strcmp(entry, "strcat")==0)
	{
		char* str = malloc(100*sizeof(char));
		char* str2 = malloc(100*sizeof(char));	
		char* result;
		printf("Entrez la première chaine : ");
		scanf("%s", str);
		printf("Entrez la deuxieme chaine : ");
		scanf("%s", str2);
		result = strcat(str, str2);
		printf("%s\n", result);
		free(str);
		free(str2);
		free(result);
	}
	else if(strcmp(entry, "strcasecmp")==0)
	{
		char* str = malloc(100*sizeof(char));
		char* str2 = malloc (100*sizeof(char));
		printf("Cette fonction renvoie -1 si la premiere chaine est inférieure, 0 si elles sont egales, et 1 si la premiere est superieure.\n");
		printf("Entrez la première chaine a comparer : ");
		scanf("%s", str);
		printf("Et maintenant, la deuxieme : ");
		scanf("%s", str2);
		printf("%d\n", strcasecmp(str, str2));
		free(str);
		free(str2);
	}
	else
	{
		printf("Erreur : vous avez entre une mauvaise commande\n");
	}


	free(entry);	
	return(EXIT_SUCCESS);
}
	

size_t strlen(const char* s)
{
	size_t i = 0;
	while(!s[i]=='\0')
	{
		i++;
	}
	return i;
}

char* strcat(char* dest, const char* src)
{
	size_t destsize = sizeof(dest);
	size_t srcsize = sizeof(src);
	char* result = malloc(destsize+srcsize);

	int i = 0;
	size_t siz = strlen(dest);
	int z = 0;
	do
	{	
		if(!dest[i]=='\0')
		{
			result[z]=dest[i];
		}
		else if(dest[i]=='\0')
		{
			int j = 0;
			while(!src[j]=='\0')
			{
				char a = src[j];
				result[z]=a;
				j++; z++;
			}
		}
		i++; z++;
	}while(!(i==siz+1));


	return result;	
}

int strcasecmp(const char* s1, const char* s2)
{
	int i = 0;
	int count = 0;
	size_t s1size = strlen(s1);
	size_t s2size = strlen(s2);
	if(s1size < s2size){ return -1;}
	else if(s1size > s2size){ return 1;}
	else if(s1size==s2size)
	{
		for(i=0; i<s1size ; i++)
		{
			if( s1[i]==s2[i] || (s1[i]==toupper(s2[i]) ) )
			{
				count++;
			}
			else if ( toupper(s1[i])==s2[i])
			{
				count++;
			}
		}
		if(count == s1size) {return 0;}
		else if (!(count==s1size)) {return -1;}
	}	
	return(EXIT_FAILURE); 
}
