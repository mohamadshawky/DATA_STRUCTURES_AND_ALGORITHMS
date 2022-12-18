#ifndef _CQUEUE_H_
#define _CQUEUE_H_

typedef struct cQueue cQueue_t;
typedef cQueue_t* cQueue_handle_t;

#ifndef BUFFER_STATUS
#define BUFFER_STATUS
typedef enum{
	NOT_FULL = 1,
	FULL,
	NOT_EMPTY,
	EMPTY	
}buffer_status;
#endif /* BUFFER_STATUS */

void cQueue_create(cQueue_handle_t me, int arr[], int size);
buffer_status cQueue_isEMPTY(cQueue_handle_t me);
buffer_status cQueue_isFULL(cQueue_handle_t me);
void cEnqueue(cQueue_handle_t me, int value);
void cDequeue(cQueue_handle_t me, int* value);
void cQueue_traverse(cQueue_handle_t me);
unsigned int cQueue_size(cQueue_handle_t me);
void cQueue_clear(cQueue_handle_t me);

#endif /* _CQUEUE_H_ */