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
    printf("In enqueue\n");
    if (_list == NULL)
    {
        /* code */
        printf("List is null in enque\n");
    } else{
        printf("List is NOT null in enque\n");
    }
    node_t *p = (node_t*)malloc(sizeof(node_t));
    if (!p) {
        fprintf(stderr, "malloc error\n");
        printf("Node not allocated\n");
        return NULL;
    } else {
        printf("Node allocated\n");
    }
    p->next = NULL;
    p->data = d;
    printf("Data set for node\n");
    node_t *q;
    printf("After node q creation\n");
    do {
        node_t *tmp = _list->tail;
        q =  tmp;
        printf("after q set to tail\n");
    } while (!__sync_bool_compare_and_swap(&(q->next), NULL, p));
    printf("after while loop\n");
    // node_t *tail_tmp = _list->tai
    __sync_bool_compare_and_swap( &(_list->tail), q, p);
    printf("Before return in enque\n");

    // dequeue(*_list);

    return p;
}



void* dequeue(list *_list)
{
    node_t *p;
    void *res;
    if (_list ==NULL)
    {
        /* code */
        printf("List is null in dequeue\n");
    }
    if (_list->head != NULL)
    {
        /* code */
        // printf("Head data is %s\n",_list->head->data );
    }
    do {
        p = _list->head;
        if (p->next == NULL){
            printf("Head next is null\n");
            return NULL;
        }
         res = p->next->data;
    } while(!__sync_bool_compare_and_swap(&_list->head, p, p->next));
    if (p) {
        free(p);
        p = NULL;
    }
    if (res ==NULL)
    {
        /* code */
        printf("res is null\n");
    }
    return res;
}