#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include "thread_peterson.h"

#define NTHREADS 2
#define A 0
#define B 1

pthread_t satanA;
pthread_t satanB;
int flag[] = {false, false};
int turn;
int global = 0;

void criticalSection () {
	printf ("Hello, I'm in my critical section !\n");
	for (int i = 0; i < 10000 ; i++) {
		global++;
	}
}

void* satan_A (void* param) {
	printf ("Hail SatanA !\n");
	flag[A] = true;
	turn = B;
	while ( (flag[B] == true) && (turn == B) ) {

	}
	criticalSection ();
	flag[A] = false;
	printf ("Auf Wieder Sehn SatanA !\n");
	
	pthread_exit (NULL);
}

void* satan_B (void* param) {
	printf ("Hail SatanB !\n");
	flag[B] = true;
	turn = A;
	while ( (flag[A] == true) && (turn == A) ) {

	}
	criticalSection ();
	flag[B] = false;
	printf ("Auf Wieder Sehn SatanB !\n");
	
	pthread_exit (NULL);
}

int main (int argc, char** argv) {
	int err = 0;
	err = pthread_create (&satanA, NULL, &satan_A, NULL);
	if (err != 0) {
		return -1;
	}
	err = pthread_create (&satanB, NULL, &satan_B, NULL);
	if (err != 0) {
		return -1;
	}

	for (int i = 0 ; i < 10000 ; i++) {
		/* wait... */
	}
	
	err = pthread_join (satanA, NULL);
	if (err != 0) {
		return -1;
	}
	err = pthread_join (satanB, NULL);
	if (err != 0) {
		return -1;
	}
	printf ("la valeur de la variable global est : [%d]\n", global);
	printf ("fin\n");
	return (EXIT_SUCCESS);	
}
