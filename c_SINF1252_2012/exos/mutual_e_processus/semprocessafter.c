#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>

sem_t* semaphore;

void after() {
	
	sem_wait (semaphore);
	
	for (int i = 0; i < 1000000; i++) {
	}
	printf ("after done, pid = %d\n", (int) getpid());
}

int main (int argc, char** argv) {
	int err;

	semaphore = sem_open ("lsinf1252", 0);
	if (semaphore == SEM_FAILED) {
		perror ("sem_open");
	}
	after();
	
	err = sem_close (semaphore);
	if (err != 0)
		perror ("sem_close");

	err = sem_unlink ("lsinf1252");
	if (err != 0)
		perror ("sem_unlink");
	
	return (EXIT_SUCCESS);
	
}
