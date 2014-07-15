#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
        size_t capacity;
        size_t n_items;
        void* items;
        pthread_mutex_t* mutex;
} pqueue;

int pqueue_push (pqueue* queue, void* data)
{
        int err = pthread_mutex_lock (queue->mutex);
        if (err !=0)
                return -1;
        
        if ((queue->capacity) <= (queue->n_items))
        {
                printf ("la file est pleine !");
                return -1;
        }
        
        else
        {
                (queue->n_items)++;
                if ( (queue->items) == NULL )
                {
                        (queue->items) = (void*) malloc ((queue->capacity)*sizeof (data));
                        if ( (queue->items) == NULL )
                        {
                                perror ("malloc pqueue_push");
                                exit (EXIT_FAILURE);
                        }
                }
                /*
                 * lorsqu'on a un char* qui represente un string, on fait char* +1 pour acceder au char suivant
                 * ici, pour acceder au dernier element, on part du pointeur auquel on rajoute n_items fois (moins un car le premier element a l'indice 0) la taille de data 
                 */
                void* lastdata=queue->items+(((queue->n_items)-1)*sizeof(data));
                lastdata=data;
                
        }
        
        
        
        err = pthread_mutex_unlock (queue->mutex);
        if (err!=0)
                return -1;
        return 0;
}


void pqueue_free (pqueue* queue)
{
        /*
         * for (int i = 0; i < (queue->n_items); i++)
         * {
         *      free ((queue->items) [i]);
         * }
         * err = pthread_mutex_destroy (&(queue->mutex));
         * free (queue);
         * Il faut liberer la memoire pour tous les n_items elements de la queue
         */
}

pqueue* pqueue_new (size_t capacity)
{
        pqueue* queue = (pqueue*) malloc (sizeof (pqueue));
        if (queue == NULL)
        {
                perror ("malloc");
                exit (EXIT_FAILURE);
        }

        queue->capacity = capacity;
        queue->n_items = 0;
        queue->items = NULL;

        int err = pthread_mutex_init (queue->mutex, NULL);

        if (err != 0)
        {
                perror ("mutex");
                pqueue_free (queue);
                exit (EXIT_FAILURE);
        }

        return queue;
}

int main (int argc, char** argv)
{
        return 0;
}





