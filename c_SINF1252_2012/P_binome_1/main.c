#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define SIZE 400

int main (int argc, char** argv)
{
	struct string* sString = string_alloc_str ("Hello_World!");
	struct string* sString0 = string_alloc_str ("Hello_World!");
	struct string* sString1 = string_alloc_str ("Hello_WORLD!");
	struct string* sString2 = string_alloc_str ("SINF1252");
	struct string* sString3 = string_alloc_str ("+Hello ! How are you ?");
	struct string* sString4;
	printf ("Adresse du string : %p\n", sString);
	printf ("Contenu du string : ");
	printf ("\nLongueur du string : %d\n", string_printf (sString));
	printf ("Comparaison de 'Hello_World!' et 'Hello_World!' (même variable): %d\n", string_equals (sString, sString));
	printf ("Comparaison de 'Hello_World!' et 'Hello_World!': %d\n", string_equals (sString, sString0));
	printf ("Comparaison de 'Hello_World!' et 'Hello_WORLD!': %d\n", string_equals (sString, sString1));
	printf ("Comparaison de 'Hello_WORLD!' et 'SINF1252': %d\n", string_equals (sString1, sString2));
	sString4 = string_concat (sString, sString3);
	printf ("Concatenation de 'Hello_World' et '+Hello ! How are you ?' : ");
	string_printf (sString4);
	printf ("\n");
	string_free (sString);
	string_free (sString0);
	string_free (sString1);
	string_free (sString2);
	string_free (sString3);
	string_free (sString4);
	struct string* sString5 = string_alloc_str ("");
	printf ("Adresse d'une string vide : %p\n", sString5);
	printf ("Contenu d'une string vide : ");
	printf ("\nLongueur d'une string vide : %d\n", string_printf (sString5));
	string_free (sString5);
	sString5 = string_alloc_str (NULL);
	printf ("Adresse d'une string NULL : %p\n", sString5);
	printf ("Contenu d'une string NULL : ");
	printf ("\nLongueur d'une string NULL : %d\n", string_printf (sString5));
	string_free (sString5);

	return EXIT_SUCCESS;
}

