//linkedlist_ADT.c
//doubly linked list
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist_ADT.h"

typedef struct ll_t{
	node_t* head;
	node_t* tail;
	int size;
}linked_list_t;

Linked_List_handle_t ll_create(int data){
	
	Linked_List_handle_t me = (Linked_List_handle_t) malloc (sizeof(linked_list_t));
	
	if (me != NULL){
		
		me->head = (node_t*) malloc (sizeof(node_t));
		
		if (me->head){
			
			me->head->data = data;
			
			me->head->next = NULL;		// node next 
			
			me->tail = me->head;		// tail
			
			me->size++;
		}
		
	}	
}

void ll_destroy(Linked_List_handle_t me){		/* Assignment */
	while (me->head->next != NULL){
		free (me->head->next);
	}
	free(me->head);
}

void ll_insert_front(Linked_List_handle_t me, int data){
	
	node_t* new_node = (node_t*) malloc (sizeof(node_t));
	
		if (new_node != NULL){
			
			new_node -> data = data;
			
			new_node ->next = me->head;	//node next
			
			me->head = new_node;		// head
			
			me->size ++;
		}
}

void ll_insert_before(Linked_List_handle_t me, int data){	/* Assignment */
		
}

void ll_append(Linked_List_handle_t me, int data){
	
	node_t* new_node = (node_t*) malloc (sizeof(node_t));
	
	if (new_node != NULL){
		
		new_node -> data = data;
	
		new_node->next = NULL;		//node next
		
		me->tail->next = new_node;	//next of tail
		
		me->tail = new_node;		// tail
		
		me->size++;
		
	}
	
}

void ll_delete_next(Linked_List_handle_t me, node_t* n){	/* Assignment */
	node_t* temp = node->next->next;
	free (node->next);
	node -> next = temp;
}

void ll_find(Linked_List_handle_t me, int key){	/* Assignment */
	node_t* ret = NULL;
	while (me != NULL){		//check on empty list
		if (list->data == key){
			ret = list;
			break;
		}
		list = list ->next;
	}
return ret;
}

void ll_sort(Linked_List_handle_t me){		/* Assignment */
	
}	

void ll_print(Linked_List_handle_t me){
	node_t* list = me->head;
	printf("-----------------------\n");
	while (list != NULL){
		printf("%d ", list->data);		// = arr[i]
		list = list->next;
	}
	printf("\n-----------------------\n");
}

unsigned int ll_get_size(Linked_List_handle_t me){
	return me->size;
}

