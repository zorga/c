#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char** argv)
{
	int x = 1;
	int y = 2;
	int z = 3;
	int w = 4;
	
	queue_t* queue1 = queue_init();
	enqueue(queue1, &x);
	enqueue(queue1, &y);
	enqueue(queue1, &z);
	enqueue(queue1, &w);
	
	int* ptr1 = (int*) queue1->data;
	printf("%i\n", *ptr1);
	int* ptr2 = (int*) (queue1->previous)->data;
	printf("%i\n", *ptr2);
	queue_free(queue1);
	ptr1 = (int*) queue1->data;
	printf("%i\n", *ptr1);
	ptr2 = (int*) (queue1->previous)->data;
	printf("%i\n", *ptr2);
	return 0;
}

queue_t* queue_init(void)
{
	queue_t* t = (queue_t*) malloc(sizeof(queue_t));
	if(t==NULL){
			exit(EXIT_FAILURE);
	}
	t->data = NULL;
	t->next = NULL;
	t->previous = NULL;
	return t;
}

void enqueue(queue_t* q, void* data)
{
	if((q->data)==NULL){ q->data=data; }
	else
	{
		queue_t* t = queue_init();
		t->data = data;
		t->previous = q->previous;
		t->next = q;
		q->previous = t;
	}
}

void* dequeue(queue_t* q)
{	
	printf("bite");
	queue_t* prev = q->previous;
	prev->next = NULL;
	void* dat = q->data;
	free(prev);
	free(prev->next);
	return dat;
}

void queue_free(queue_t* q)
{
	while(!q->next)
	{
		dequeue(q);
	}	
}

