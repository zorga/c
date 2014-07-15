#include <stdio.h>
#include <stdlib.h>

void print_var (char* var) {
	char* val = getenv (var);
	if (val != NULL) 
		printf("La variable %s a la valeur : %s\n", var, val);
	else
		printf("La variable %s n'a pas été assignée\n", var);
}

int main (int argc, char* argv[]) {
	char *old_path = getenv ("PATH");
	print_var ("PATH");

	if (unsetenv ("PATH") != 0) {
		fprintf (stderr, "Erreur unsetenv\n");
		exit (EXIT_FAILURE);
	}

	print_var ("PATH");
	
	if (setenv ("PATH", old_path, 1) != 0) {
		fprintf (stderr, "Erreur setenv\n");
		exit (EXIT_FAILURE);
	}

	print_var ("PATH");

	return (EXIT_SUCCESS);
}

