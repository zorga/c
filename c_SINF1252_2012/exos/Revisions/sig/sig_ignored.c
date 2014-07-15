#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>

static void sig_handler (int signum)
{
	
}

int main (int argc, char** argv)
{

	while (true)
	{
		signal (SIGINT, sig_handler); // Impossible d'arrêter le processus !!!
		/* Tapez top dans un terminal pour récupérer le pid du processus et le tuer en faisant "kill -9 pid" */
	}

	if (argc <= 1)
	{
		printf ("Ce programme requiert un argument\n");
		exit (EXIT_FAILURE);
	}
	
	int signum = atoi (argv[1]);

	if (signal (signum, NULL) == SIG_IGN)
	{
		printf ("true\n");
		return 1;
	}
	else if (signal (signum, NULL) == SIG_ERR)
	{
		perror ("signal");
		exit (EXIT_FAILURE);
	}
	else if (signal (SIGINT, sig_handler) == SIG_ERR)
	{
		perror ("signal");
		exit (EXIT_FAILURE);
	}
	else
	{
		printf ("false\n");
		return 0;
	}

	printf ("Fin du processus\n");


	exit (EXIT_SUCCESS);
}


