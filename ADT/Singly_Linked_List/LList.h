/*
 * Implementation of a Singly Linked List
 * Author : Nicolas Ooghe
 */

#ifndef _LLIST_H_
#define _LLIST_H_

typedef struct node
{
    int* data;
    struct node* next;
} node_t;

typedef struct llist
{
    node_t* head;
    int size;
} llist_t;

/*
 * Create a new Node with the node "next" as next pointer and pData as data
 */
node_t* newNode (void* pData, node_t* next);

/*
 * Create a new SLinked List with a new node "head" with pData and NULL next pointer
 */
llist_t* init_list (void* pData);

/*
 * Create a new Node with pData and add it at the head of the list (this node become head)
 */
void add (llist_t*, void*);

/*
 * Remove the head node of the list and return it
 */
void removeHead (llist_t* list);

/*
 * Remove and free the entire list
 */
void free_list (llist_t* list);

/*
 * Print the whole list
 */
void printList (llist_t* list);
#endif /* _LLIST_H_ */
