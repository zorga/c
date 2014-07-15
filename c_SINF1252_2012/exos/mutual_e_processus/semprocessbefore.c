#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

sem_t* semaphore;

void before () {
	for (int i = 0; i < 1000000; i++) {
		
	}
	printf ("before done, pid = %d\n", (int) getpid());
	sem_post (semaphore);
}

int main (int argc, char** argv) {
	int err;

	semaphore = sem_open ("lsinf1252", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (semaphore == SEM_FAILED) { 
		perror ("sem_open");
	}
	sleep (20);
	before();
	err = sem_close (semaphore);
	if (err != 0) {
		perror ("sem_close");
	}
	
	return (EXIT_SUCCESS);
}
