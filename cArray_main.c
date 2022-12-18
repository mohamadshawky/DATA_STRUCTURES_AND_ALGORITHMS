#include <stdio.h>

#include "cArray.h"

void main(){
	
	cArrayHandle_t myarr = array_create(5);
	
	for(int i = 0; i <= 5; i++){
		array_insert(myarr, i*i, i)	;
	}
	array_print(myarr);	
	
	array_set(myarr, 100, 3);
	array_print(myarr);	
	
	array_append(myarr, 200);
	array_print(myarr);	
	
	array_delete(myarr, 2);
	array_print(myarr);	
	
}