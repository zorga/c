#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "access.h"

#define NTHREADS 2

pthread_t threads[NTHREADS];

int main (int argc, char** argv) {
	static int sVar = 0;
	void** retour = NULL;
	int err = 0;

	for (int i = 0 ; i < NTHREADS ; i++) {
		err = pthread_create (&(threads [i]), NULL, &func, (void*) &sVar);
		if (err != 0) {
			printf ("ERREUR !!!\n");
		}
	}

	for (int i = 0; i < 10000 ; i++) {
		//wait...
	}

	for (int i = 0; i < NTHREADS ; i++) {
		err = pthread_join (threads [i], (void**) retour);
		if (err != 0) {
			printf ("ERREUR !!!\n");
		}
	}
	int* retval = (int*) *retour;
	printf ("Le contenu de la variable statique est : [%d]\n", (int) *retval);
	free (*retour);
	return 0;
}

void* func (void* param) {
	int* var = malloc (sizeof (int));
	var  = (int*) param;
	(*var)++;
	return (void*) var;
}


