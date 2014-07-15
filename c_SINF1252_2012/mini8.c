#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>
#include <time.h>
#include <errno.h> // errno
#include <string.h> // strerror

#define N_ITERATIONS	(100)
#define N_CONSUMERS	(4)
#define N_PRODUCERS	(2)
#define N_RETRIEVES	((N_ITERATIONS) * (N_PRODUCERS) / (N_CONSUMERS))
#define MIN(a, b)	((a) > (b) ? (b) : (a))
#define N_BUFFER    (4)

#define TRUE 1
#define FALSE 0
#define IF_ERROR(_message) if (err != 0)\
	fprintf (stderr, "Problème %d avec %s: %s\n", err, _message, strerror (errno));
#define DEBUG

sem_t pSemBufferPlacesProducers; // nombre de places dans le buffer pour les producteurs (assez de places?)
sem_t pSemBufferPlacesConsumers; // nombre de places dans le buffer pour les conso (buffer avec données?)
pthread_mutex_t pMuterBuffer; // pour protéger la zone critique du buffer (lecture/écriture)
int iBuffer [N_BUFFER]; // Buffer
int iBufferBusy [N_BUFFER]; // ce serait mieux avec une liste chainée mais un tableau fera l'affaire


/* 
 * Insert val in the bounded-buffer. Should wait if there are no empty spaces
 * available.
 */
void insert(int val)
{
	int i, err;
	//printf ("Insert: wait\n");
	err = sem_wait (&pSemBufferPlacesProducers); // place?
	IF_ERROR ("sem_wait")
	//printf ("Insert: lock\n");
	err = pthread_mutex_lock (&pMuterBuffer); // lock --> write
	IF_ERROR ("pthread_mutex_lock")
	for (i = 0; i < N_BUFFER; i++)
	{
		if (iBufferBusy [i] == FALSE) // place dispo
			break;
	}
	iBuffer [i] = val;
	iBufferBusy [i] = TRUE;
	err = pthread_mutex_unlock (&pMuterBuffer); // unlock
	IF_ERROR ("pthread_mutex_unlock")
	err = sem_post (&pSemBufferPlacesConsumers); // place pour conso
	IF_ERROR ("sem_post")
	#ifdef DEBUG
	printf ("Insert: insert %d dans l'entrée %d\n", val, i);
	#endif
}

/* 
 * Returns and removes the next element from the bounded buffer.
 */
int retrieve(void)
{
	int i, iVal, err;
	//printf ("Retrieve: wait\n");
	err = sem_wait (&pSemBufferPlacesConsumers); // place?
	IF_ERROR ("sem_wait")
	//printf ("Retrieve: lock\n");
	err = pthread_mutex_lock (&pMuterBuffer); // lock --> read
	IF_ERROR ("pthread_mutex_lock")
	for (i = 0; i < N_BUFFER; i++)
	{
		if (iBufferBusy [i] == TRUE) // valeur pouvant être utilisée
			break;
	}
	iBufferBusy [i] = FALSE;
	iVal = iBuffer [i];
	err = pthread_mutex_unlock (&pMuterBuffer); // unlock
	IF_ERROR ("pthread_mutex_unlock")
	err = sem_post (&pSemBufferPlacesProducers); // place pour un producteur
	IF_ERROR ("sem_post")
	#ifdef DEBUG
	printf ("Retrieve: valeur %d de l'entrée %d\n", iVal, i);
	#endif
	return iVal;
}


void *producer(void *arg)
{
	int i, val;
	
	for (i = 0; i < N_ITERATIONS; ++i) {
		/* sleep for few miliseconds */
		struct timespec sleep;
		sleep.tv_sec = 0;
		sleep.tv_nsec = (long) rand() % 100000000;
		nanosleep(&sleep, NULL);
		
		/* generate a value and insert it in the buffer */
		val = abs(rand());
		insert(val);
	}
	return NULL;
}

void *consumer(void *arg)
{
	int i, *min = (int *)arg, iMin, tmp;
	iMin = *min; // variable locale...
	
	for (i = 0; i < N_RETRIEVES; ++i) {
		/* sleep for few miliseconds */
		struct timespec sleep;
		sleep.tv_sec = 0;
		sleep.tv_nsec = (long) rand() % 150000000; // a bit slower than a producer
		nanosleep(&sleep, NULL);
		
		/* maintain the minimum value up to now */
		tmp = retrieve();
		iMin = MIN(iMin, tmp);
		#ifdef DEBUG
		printf ("%d - %d - %d\n", i, tmp, iMin);
		#endif
	}
	#ifdef DEBUG
	printf ("\n== Fin de ce thread avec la valeur: %d ==\n\n", iMin);
	#endif
	*min = iMin;
	return (void *)min;
}

int main (int argc, char const *argv[])
{
	int i, min = INT_MAX, *ret;
	pthread_t producers[N_PRODUCERS];
	pthread_t consumers[N_CONSUMERS];
	int returns[N_CONSUMERS];
	int err;
	
	/* seed the PRNG */
	srand(time(NULL));

	// init du tableau des places dispo dans le buffer
	for (i = 0; i < N_BUFFER; i++)
		iBufferBusy [i] = FALSE;

	// Sem
	err = sem_init (&(pSemBufferPlacesProducers), 0, N_BUFFER); // 4 places dispo
	if (err)
		goto error;
	err = sem_init (&(pSemBufferPlacesConsumers), 0, 0); // aucune place dispo dès l'init
	if (err)
		goto error;

	// Mutex
	err = pthread_mutex_init (&(pMuterBuffer), NULL);
	if (err)
		goto error;
	
	for (i = 0; i < N_PRODUCERS; ++i) {
		err = pthread_create(&producers[i], NULL, producer, NULL);
		if (err)
			goto error;
	}
	
	for (i = 0; i < N_CONSUMERS; ++i) {
		returns[i] = min; // c'est mieux quand c'est initialisé :)
		err = pthread_create(&consumers[i], NULL, consumer, &returns[i]);
		if (err)
			goto error;
	}

	for (i = 0; i < N_PRODUCERS; ++i) {
		err = pthread_join(producers[i], NULL);
		if (err)
			goto error;
	}

	for (i = 0; i < N_CONSUMERS; ++i) {
		err = pthread_join(consumers[i], (void **)&ret);
		if (err)
			goto error;
		min = MIN(min, *ret);
	}

	// destruction
	err = sem_destroy (&pSemBufferPlacesProducers);
	if (err)
		goto error;
	err = sem_destroy (&pSemBufferPlacesConsumers);
	if (err)
		goto error;
	err = pthread_mutex_destroy (&pMuterBuffer);
	if (err)
		goto error;
	
	printf("The minimal value generated is %d.\n", min);
	
	return (EXIT_SUCCESS);

error:
	perror("Error happened:\n");
	return (EXIT_FAILURE);
}
