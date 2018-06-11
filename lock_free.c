/*lock_free.c*/
#include "lock_free.h"
node_t *head = NULL;
node_t *tail = NULL;
node_t *create_queue(void)
{
    if (head != NULL)
        return head;
    head = (node_t*)malloc(sizeof(node_t));
    if (!head) {
        fprintf(stderr, "malloc error\n");
        return NULL;
    }
    head->next = NULL;
    head->data = NULL;
    tail = head;
    return head;
}
node_t* enqueue(void *d)
{
    node_t *p = (node_t*)malloc(sizeof(node_t));
    if (!p) {
        fprintf(stderr, "malloc error\n");
        return NULL;
    }
    p->next = NULL;
    p->data = d;
    node_t *q;
    do {
        q = tail;
    } while (!__sync_bool_compare_and_swap(&(q->next), NULL, p));
    __sync_bool_compare_and_swap(&tail, q, p);
    return p;
}
void* get_calf_pkt(void)
{
    node_t *p;
    void *res;
    do {
        p = head;
        if (p->next == NULL)
            return NULL;
         res = p->next->data;
    } while(!__sync_bool_compare_and_swap(&head, p, p->next));
    if (p) {
        free(p);
        p = NULL;
    }
    return res;
}



node_t *head_tx = NULL;
node_t *tail_tx = NULL;
node_t *create_queue_tx(void)
{
    if (head_tx != NULL)
        return head_tx;
    head_tx = (node_t*)malloc(sizeof(node_t));
    if (!head_tx) {
        fprintf(stderr, "malloc error\n");
        return NULL;
    }
    head_tx->next = NULL;
    head_tx->data = NULL;
    tail_tx = head_tx;
    return head_tx;
}
node_t* send_calf_pkt(void *d)
{
    node_t *p = (node_t*)malloc(sizeof(node_t));
    if (!p) {
        fprintf(stderr, "malloc error\n");
        return NULL;
    }
    p->next = NULL;
    p->data = d;
    node_t *q;
    do {
        q = tail_tx;
    } while (!__sync_bool_compare_and_swap(&(q->next), NULL, p));
    __sync_bool_compare_and_swap(&tail_tx, q, p);
    return p;
}
void* dequeue_tx(void)
{
    node_t *p;
    void *res;
    do {
        p = head_tx;
        if (p->next == NULL)
            return NULL;
         res = p->next->data;
    } while(!__sync_bool_compare_and_swap(&head_tx, p, p->next));
    if (p) {
        free(p);
        p = NULL;
    }
    return res;
}
