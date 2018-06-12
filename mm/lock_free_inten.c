#include "lock_free_inten.h"

list *create_queue(void){
	list* _list =NULL;
	// printf("After list null\n");
	_list = (list*)malloc(sizeof(list));
	// printf("After list head allocation\n");
 //    if (!_list) {
 //        fprintf(stderr, "malloc error\n");
 //        return NULL;
 //    } else {
 //    	printf("Head allocated if cond\n");
 //    }
 //    printf("Head config pre\n");
 //    _list->head->next = NULL;
 //    printf("Head config1\n");
 //    _list->head->data = NULL;
 //    printf("Head config2\n");
 //    _list->tail=_list->head;
	node_t *head = NULL;
	node_t *tail = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (!head) {
        fprintf(stderr, "malloc error\n");
        return NULL;
    }
    head->next = NULL;
    head->data = NULL;
    tail = head;
    _list->head = head;
    _list->tail = head;
    return _list;
}



node_t* enqueue(void *d, list *_list)
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
        q =  _list->tail;
    } while (!__sync_bool_compare_and_swap(&(q->next), NULL, p));
    __sync_bool_compare_and_swap(& _list->tail, q, p);
    return p;
}



void* dequeue(list *_list)
{
    node_t *p;
    void *res;
    do {
        p = _list->head;
        if (p->next == NULL)
            return NULL;
         res = p->next->data;
    } while(!__sync_bool_compare_and_swap(&_list->head, p, p->next));
    if (p) {
        free(p);
        p = NULL;
    }
    return res;
}