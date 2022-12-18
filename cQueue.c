#include <stdio.h>
#include "cQueue.h"

typedef struct cQueue{
	int* arr;
	int front;
	int rear;
	unsigned int size;
}cQueue_t;

void cQueue_create(cQueue_handle_t me, int arr[], int size){
	if (cQueue_isFULL(me) != FULL){
		me->front = 0;
		me->rear = -1;
		me->arr = arr;
		me->size = size;
	}
}

buffer_status cQueue_isEMPTY(cQueue_handle_t me){
	return !(me->size) ? EMPTY : NOT_EMPTY;
}

buffer_status cQueue_isFULL(cQueue_handle_t me){
	return ((me->rear == me->size))? FULL : NOT_FULL;
}

void cEnqueue(cQueue_handle_t me, int value){
	if (cQueue_isFULL(me) != FULL){
		me->rear = (me->rear + 1) % me->size;		/* circular */
		me->arr[me->rear] = value;
		me->size ++;
	}
}

void cDequeue(cQueue_handle_t me, int* value){
	if (cQueue_isEMPTY(me) != EMPTY){
		*value = me->arr[me->front];
		me->front = (me->front + 1) % me->size;		/* circular */
		me->size--;
	}
}
void cQueue_traverse(cQueue_handle_t me){
	int item = me->front, i = 0;
	printf("-----------------------\n");
	printf("[ ");
	if (cQueue_isEMPTY(me) != EMPTY){
		for (	; i < me->size; i++){
			item = (item+1) % me->size;
			printf("%d ,", me->front);
		}
	}else{
		printf("\n>> UNDERFLOW!\n");
	}
	printf(" ]\n");
	printf("-----------------------\n");
}
	
unsigned int cQueue_size(cQueue_handle_t me){
	return cQueue_isEMPTY(me) != EMPTY ? me->size : printf("\n>> UNDERFLOW!\n");
}

void cQueue_clear(cQueue_handle_t me){
	me->front = 0;
	me->rear = -1;
	me->size = 0;
}