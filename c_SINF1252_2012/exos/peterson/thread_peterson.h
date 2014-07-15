#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

void criticalSection ();
void* satan_A (void* param);
void* satan_B (void* param);
