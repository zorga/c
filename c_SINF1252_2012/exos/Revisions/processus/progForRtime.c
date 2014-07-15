#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char** argv)
{
	printf ("Execution du programme qui a le pid %d\n", getpid());
	for (int i = 0; i < 10; i++)
	{
		printf ("caca\n");
	}
	exit (EXIT_SUCCESS);
}
