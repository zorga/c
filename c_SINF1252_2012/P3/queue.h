#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	void* data;
	struct queue* next;
	struct queue* previous;
}queue_t;
	
queue_t* queue_init(void);

void enqueue(queue_t* q, void* data);
void* dequeue(queue_t* q);
void queue_free(queue_t* q);

