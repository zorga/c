#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_calculator(const char*, const char*, const char*, char*);

int str_replace(const char*, const char*, const char*, char*);


int main(int argc, char* argv)
{
	const char* search = "Pierre-Yves";
	const char* replace = "Nicolas";
	const char* subject = "Pierre-Yves est beau et incroyablement sexy";
	char* result;
	str_replace(search, replace, subject, result);
}

int str_replace(const char* search, const char* replace, const char* subject, char* result)
{	

	int lobelle = size_calculator(search, replace, subject, result);
	size_t total_size = (size_t) malloc(sizeof(subject-(lobelle*sizeof(search))+(lobelle*sizeof(replace))));
        result = (char *) malloc(total_size*sizeof(char));
	


	
	if(result==NULL) { return -1; }
	int count = 0;
	int i;
	int j;
	int k;
	int occ = 0;

	for(i=0 ; i < strlen(subject) ; i++)
	{
		if(subject[i] == search[0])
		{
			char* buf = (char*) malloc(sizeof(search));
			count = 0;
			for(j=i, k=0 ; k < strlen(search) ; j++, k++)
			{
				if(subject[j] == search[k])
				{
					count++;
				}
				buf[k] = subject[j];
			}
			if(count == strlen(search))
			{
				strcat(result, replace);
				occ++;
				free(buf);
			}
			else
			{
				strcat(result, buf);
				free(buf);
			}
			i = --j;
		}
		else
		{
			char * tmp2 = (char *) malloc(2*sizeof(char));
			tmp2[0] = subject[i];
			tmp2[1] = '\0';
			strcat(result, tmp2);
			free(tmp2);
		}
		printf("%s \n", result);
	}
	return occ;
}

int size_calculator(const char* search, const char* replace, const char* subject, char* result)
// calcule le nombre d'occurence de "search" dans "subject"
{
	int j;
	int i;
	int count;
	int k;
	int occ = 0;
        for(i=0 ; i < strlen(subject) ; i++)
       	{
		count = 0;
               	if(subject[i] == search[0])
               	{
                       	for(j=i, k=0 ; k < strlen(search) ; j++, k++)
                       	{
                               	if(subject[j] == search[k])
                               	{
                                       	count++;
                                       	i++;
                               	}
                       	}
                       	if(count == strlen(search))
                       	{       
                               	occ++;
                       	}
               	}
       	}
	return occ;
}	
 


