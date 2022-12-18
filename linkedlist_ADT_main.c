
#include <stdio.h>

#include "linkedlist_ADT.h"

void main (){
	
		Linked_List_handle_t mylist = ll_create(0);
		
		for (int i =0; i < 3; i++){
			ll_insert_front(mylist, i+2);
		}
		
		for (int i =1; i < 4; i++){
			ll_append(mylist, i*5);
		}
		
		ll_print(mylist);
}