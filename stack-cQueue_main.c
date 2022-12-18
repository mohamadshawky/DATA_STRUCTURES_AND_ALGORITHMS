
#include <stdio.h>
#include "stack.h"
#include "cQueue.h"

#define STACK_SIZE		5
#define CQUEUE_SIZE		8

int main(){
	
int b[CQUEUE_SIZE] = {0};
	cQueue_handle_t myqueue;
	cQueue_create(myqueue, b, CQUEUE_SIZE);
	
	cEnqueue(myqueue, 5);
	cEnqueue(myqueue, 10);
	cEnqueue(myqueue, 15);
	
	cQueue_traverse(myqueue);
	/*
		int a[STACK_SIZE];
		stack_handle_t mystack;
		stack_create(mystack, a, 10);
	
		stack_push(mystack, 5);
		stack_push(mystack, 7);
		stack_traverse(mystack);
	*/


}