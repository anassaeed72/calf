/*lock_free.h*/
#ifndef _LOCK_FREE_H_
#define _LOCK_FREE_H_    
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct node_s node_t;
struct node_s {
    node_t *next;
    void *data;
    uint32_t tag;
};
typedef struct list_s list;
struct list_s
{
	node_t *head;
	node_t *tail;
};

list *create_queue(void);
node_t* enqueue(void *d, list *_list);

void* dequeue(list* list);
#endif
