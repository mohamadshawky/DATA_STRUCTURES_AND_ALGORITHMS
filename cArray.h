#ifndef _CARRAY_H
#define _CARRAY_H

typedef struct cArray cArray_t;
typedef cArray_t* cArrayHandle_t;

cArrayHandle_t array_create(int capacity);
void array_destroy(cArrayHandle_t me);
void array_set(cArrayHandle_t me, int value, int index);
void array_get(cArrayHandle_t me, int* value, int index);
void array_insert(cArrayHandle_t me, int value, int index);
void array_append(cArrayHandle_t me, int value);
void array_delete(cArrayHandle_t me, int index);
// void array_sort(cArrayHandle_t me);
// void array_find(cArrayHandle_t me);
void array_print(cArrayHandle_t me);



#endif	// _CARRAY_H