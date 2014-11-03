/*
 * Implementation of a Singly Linked List
 * Author : Nicolas Ooghe
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "LList.h"

node_t* newNode (void* pData, node_t* next)
{
    node_t* newNode = (node_t*) malloc (sizeof (node_t));
    if (! newNode)
        perror ("malloc() : newNode");

    newNode->data = pData;
    newNode->next = next;
    return newNode;
}

llist_t* init_list (void* pData)
{
    llist_t* llist = (llist_t*) malloc (sizeof (llist_t));
    if (! llist)
        perror ("malloc(): init");

    /* At initialisation, there's only the "head" node followed by a NULL pointer */
    node_t* head = newNode (pData, NULL);
    llist->head = head;
    /* At initialisation, the list size is 1 ! */
    llist->size = 1;
    return llist;
}

void add (llist_t* list, void* pData)
{
    if (! list)
        perror ("list is NULL");
    
    node_t* new = newNode (pData, list->head);
    list->head = new;
    list->size = (list->size)+1;
}

void removeHead (llist_t* list)
{
    if (! list)
        perror ("list is NULL");

    node_t* tmp = list->head;
    list->head = list->head->next;
    free (tmp);
    list->size = (list->size)-1;
}

void free_list (llist_t* list)
{
    if (! list)
        perror ("list is NULL");

    while (list->head->next)
    {
        removeHead (list);
    }
    free (list->head);
    list->head = NULL;
    free (list);
    list = NULL;
}

void printList (llist_t* list)
{
    node_t* curr = list->head;
    while (curr)
    {
        printf ("%d\n", *(curr->data));
        curr = curr->next;
    }
}


