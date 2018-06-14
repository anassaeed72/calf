#include <stdlib.h>
#include <string.h>
#include "../mm/lock_free_inten.h"
#include "nf.c"


static (*fun_ptr)(int) = &nf_func;

void mainFunc(list _list){
	printf("In Scduler mainFunc\n");
	// void *data = dequeue(&_list);
	printf(" after data in mainFunc\n");
	(*fun_ptr)(10);
	printf("trying to get data\n");
	// if (data ==NULL)
	// {
	// 	/* code */
	// 	printf("data is NULL\n");
	// } else {
	// 	 printf("%d", *(int *)data);
	// }

}

