#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    int* p = malloc (3 * sizeof (*p));
    if (p==NULL)
        perror("malloc()");
    
    p[3] = 0;
    free(p);
    return 0;
}

