#include <stdio.h>
#include <stdlib.h>
#include "LList.h"

int main (int argc, char** argv)
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int init = 42;

    llist_t* list = init_list (&init);
    add (list, &a);
    add (list, &b);
    add (list, &c);
    add (list, &d);
    add (list, &e);
    printList (list);
    removeHead (list);
    removeHead (list);
    printList (list);
    free_list (list);
    return 0;
}
