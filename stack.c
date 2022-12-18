#include <stdio.h>
#include "stack.h"

typedef struct stack {
	unsigned int top;		// index
	int* arr;				// not arr[SIZE] as this is static size to all stack structures.
	unsigned int size;
}stack_t;

buffer_status stack_isFull(stack_handle_t me){
	return (me->top == me->size)? FULL : NOT_FULL;
}

buffer_status stack_isEMPTY(stack_handle_t me){
	return (me->top == 0)? EMPTY : NOT_EMPTY;
}

void stack_create(stack_handle_t me, int* arr, unsigned int size){
	if (me != NULL){
		me->arr = arr;
		me->size = size;
		me->top= 0;
	}
}

void stack_push(stack_handle_t me, int data){
	if (stack_isFull(me) != FULL){
		me->arr[me->top] = data;
		me->top++;
		me->size++;
	}
}

void stack_pop(stack_handle_t me, int* top_value){
	if (stack_isEMPTY(me) != EMPTY){
		*top_value = me->arr[me->top-1];		//pop
		me->top--;								//decrease size
		me->size--;
	}		
}

void stack_peek(stack_handle_t me, int* top_value){
	if (stack_isEMPTY(me) != EMPTY){
		*top_value = me->arr[me->top-1];		
	}	
}

void stack_traverse(stack_handle_t me){
	int i = 0;
	if (stack_isEMPTY(me) != EMPTY){
		printf("-----------------------\n");
		printf("[ ");
		for (	; i < me->size; i++){
			printf("%d, ", me->arr[i]);
		}
	}else{
		printf("\n>> UNDERFLOW!\n");
	}
	printf(" ]\n");
	printf("-----------------------\n");
}

unsigned int stack_size(stack_handle_t me){
	return stack_isEMPTY(me) != EMPTY ? me->size : printf("\n>> UNDERFLOW!\n");
}
