#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <semaphore.h>
#include <pthread.h>

#define NTHREADS 2

static long global = 0;
static int even = 0;
static int err = 0;

void test_even (int i);
int increment (int i);
void* inc (void* param);
void* is_even (void* param);

static sem_t sem;
#endif /* __GLOBAL_H__ */
