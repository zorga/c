#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h" /* Fichier Header */

/*********************************************
* les variables sont définies
* dans le fichier header du même nom que
* ce fichier c !!
*
* Written by Nicolas Ooghe
**********************************************/
int main (int argc, char** argv) {
	
	pthread_t threads[NTHREADS];

	sem_init (&sem, 0, 1);

	err = pthread_create (&threads[0], NULL, &inc, NULL);
	if (err != 0)
		return (EXIT_FAILURE);

	err = pthread_create (&threads[1], NULL, &is_even, NULL);
	if (err != 0)
		return (EXIT_FAILURE);

	for (int i = 0; i<100000000; i++) {
		/*...*/
	}

	err = pthread_join (threads[0], NULL);
	if (err != 0)
		return (EXIT_FAILURE);

	err = pthread_join (threads[1], NULL);
	if (err != 0)
		return (EXIT_FAILURE);

	sem_destroy (&sem);

	printf ("global: %ld, even: %d\n", global, even);

	
}

void test_even (int i) {
	if ((i%2)==0)
		even++;
}

int increment (int i) {
	return i+1;
}

void* inc (void* param) {
	sem_wait (&sem);

	for (int j=0; j < 1000000; j++) {
		global = increment (global);
	}
	sem_post (&sem);

	pthread_exit (NULL);
}

void* is_even (void* param) {
	sem_wait (&sem);

	for (int j=0; j < 1000000; j++) {
			test_even (global);
	}
	sem_post (&sem);
	pthread_exit (NULL);
}
