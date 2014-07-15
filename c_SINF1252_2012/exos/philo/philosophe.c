#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include "philosophe.h"

#define PHILOSOPHES 3

pthread_t phil [PHILOSOPHES];
pthread_mutex_t baguette [PHILOSOPHES];
int arguments[PHILOSOPHES];

void mange (int id) {
	printf ("Philosophe [%d] mange\n", id);
	for (int i = 0 ; i < rand(); i++) {
		// philosophe mange...
	}
}

void* philosophe (void* arg){
	int* id = (int*) arg;
	int left = *id;
	int right = (left +1) % PHILOSOPHES;
	int i = 0;
	
	while (true) {
		printf ("Philosophe [%d] pense\n", *id);
		if (right < left ) {
			pthread_mutex_lock (&baguette [right]);
			printf ("Philosophe [%d] possede la baguette gauche [%d]\n", *id, left);
			pthread_mutex_lock (&baguette [left]);
			printf ("Philosophe [%d] possede la baguette droite [%d]\n", *id, right);
		}
		else {
			pthread_mutex_lock (&baguette[left]);
			printf ("Philosophe [%d] possede la baguette droite [%d]\n", *id, right);
			pthread_mutex_lock (&baguette[right]);
			printf ("Philosophe [%d] possede la baguette gauche [%d]\n", *id, left);
		}
		mange (*id);
		pthread_mutex_unlock (&baguette[right]);
		printf ("Philosophe [%d] a libere baguette gauche [%d]\n", *id, left);
		pthread_mutex_unlock (&baguette[left]);
		printf ("Philosophe [%d] a libere baguette droite [%d]\n", *id, right);
		i++;
	}
	
	return NULL;
}

int main (int argc, char** argv) {

	int err = 0;
	for (int i = 0 ; i < PHILOSOPHES ; i++) {
		arguments[i] = i;
		err = pthread_create (&(phil[i]), NULL, &philosophe, (void*) &(arguments[i])); 
		if (err != 0) printf ("Erreur a la creation du philosophe [%d]\n", i);
	}
	for (int i = 0 ; i < 100000 ; i++) {
		/* ... */
	}
	for (int i = 0 ; i < PHILOSOPHES ; i++) {
		err = pthread_join (phil[i], NULL);
		if (err != 0) printf ("Erreur avec le join du philosophe [%d]\n", i);
	}
	return 0;
}
	
