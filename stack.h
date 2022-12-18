#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack stack_t;
typedef stack_t* stack_handle_t;

#ifndef BUFFER_STATUS
#define BUFFER_STATUS
typedef enum{
	NOT_FULL = 1,
	FULL,
	NOT_EMPTY,
	EMPTY	
}buffer_status;
#endif /* BUFFER_STATUS */

buffer_status stack_isFull(stack_handle_t me);
buffer_status stack_isEMPTY(stack_handle_t me);
void stack_create(stack_handle_t me, int* arr, unsigned int size);
void stack_push(stack_handle_t me, int data);
void stack_pop(stack_handle_t me, int* top_value);
void stack_peek(stack_handle_t me, int* top_value);
void stack_traverse(stack_handle_t me);
unsigned int stack_size(stack_handle_t me);

#endif /* _STACK_H_ */