#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

static void sig_handler (int);

int main (int argc, char** argv) {

	char c;
	printf ("Tapez return en moins de 5 secondes !\n");
	fflush (stdout);
	if (signal (SIGALRM, sig_handler) == SIG_ERR) {
		perror ("signal");
		exit (EXIT_FAILURE);
	}
	
	//sigalarm interrompt les appels systemes
	if (siginterrupt (SIGALRM, true) < 0) {
		perror ("siginterrupt");
		exit (EXIT_FAILURE);
	}

	alarm (5);
	int r = read (STDIN_FILENO, &c, 1);
	if ((r == 1) && (c == '\0')) {
		alarm (0); //reset timer
		printf ("Gagne !\n");
		exit (EXIT_SUCCESS);
	}
	printf ("Perdu !\n");
	exit (EXIT_FAILURE);
}

static void sig_handler (int signum) {
	//rien a faire, read sera interrompu
}

		
