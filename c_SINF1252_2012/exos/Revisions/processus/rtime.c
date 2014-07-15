#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char** argv)
{
	const char* path = argv[1];
	printf ("Execution du processus %s qui a le pid %d\n", argv[0], getpid());
	char* arguments[argc-1];
	char* environnement[] = {"LANG=fr", NULL};

	for (int i = 0; i < argc-1; i++)
	{
		arguments[i] = argv[i+1];
	}
	printf ("Lancement de %s ...\n", path);
	int err = execve (path, arguments, environnement);
	if (err != 0)
	{
		perror ("execve");
		exit (EXIT_FAILURE);
	}
	
	
	

	//message normalement jamais atteint
	printf ("... Fin de l'Execution du processus %s\n", argv[0]);
	return 0;	
}
