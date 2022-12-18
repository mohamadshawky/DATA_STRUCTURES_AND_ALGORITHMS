#include <stdio.h>
#include <stdlib.h>

#include "cArray.h"

typedef struct cArray{
	
	int* array;
	int size;
	int capacity;
	
}cArray_t;

/* Check if capacity is small so extend, else none*/
static void CheckCapacity(cArrayHandle_t me){			//regarding append() & insert().
	//extend capacity of array
	if(me ->size == me->capacity){		// hash define @ configuration file, with creation of array by user.
		
		// int new_capacity = me->capacity + (me->capacity * 2)/100 + 1;
		// me->array= realloc(me->arr, new_capacity);
		
		me->capacity = me->capacity + (me->capacity * 2)/100 + 1;
		me->array= realloc(me->array, me->capacity * sizeof(int));
		
	}
}
cArrayHandle_t array_create(int capacity){
	cArrayHandle_t new_array = (cArrayHandle_t) malloc (sizeof(cArray_t));	
	if (new_array != NULL){
		new_array -> array= (int*) malloc (sizeof(int) * capacity);
		new_array -> size = 0;
		new_array -> capacity = capacity;
	}
	return new_array;		// not dangling as it reserved @ heap
}
void array_destroy(cArrayHandle_t me){	//this, self
	free (me->array);		//distroy pointer to array in struct
	free(me);				//distroy pointer to struct itself
}
void array_set(cArrayHandle_t me, int value, int index){
	if (index <= me->size){		// size is actual elements, capacity is garbage.
		me -> array[index] = value;
	}
}
void array_get(cArrayHandle_t me, int* value, int index){
	if (index <= me->size){		//random access within size
		*value = me->array[index];	
	}
}
void array_insert(cArrayHandle_t me, int value, int index){		//size must be incremeted when insertion till end of size
	
	if(index <= me->size)		//actual size. hence, insert with contigious elements
		CheckCapacity(me);
		for(int i = me->size-2; i >= index; i--){
			me->array[i+1] = me ->array[i];
		}
		me->array[index] = value;
		me->size++;		//increase size
}

void array_append(cArrayHandle_t me, int value){
	CheckCapacity(me);
	me->array[me->size] = value;	//arr[size] => out of size, within capacity								
	me->size++;						//increase size
}
void array_delete(cArrayHandle_t me, int index){
	if(index <= me->size)	//protection for memory access
	{
	//	CheckCapacity(me);	//not significant as sizr decreases 										//optional, review 
		// shift array to right
		for(int i=index; i <= me->size-2; i++)
		{
			me->array[i] = me->array[i+1];
		}
		me->size--;		//execlude last elements
	}
}
// void array_sort(cArrayHandle_t me){}
// void array_find(cArrayHandle_t me){}
void array_print(cArrayHandle_t me){
	printf("[");
	for(int i =0; i< me->size; i++){
		printf(" %d, ", me->array[i]);
	}
	printf("]\n");
}