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
};
node_t *create_queue(void);
node_t *enqueue(void * d);
void* get_calf_pkt(void);
node_t *create_queue_tx(void);
node_t *send_calf_pkt(void * d);
void* dequeue_tx(void);
#endif
