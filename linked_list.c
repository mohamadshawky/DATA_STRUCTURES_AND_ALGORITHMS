/**
	@file 		linkedlist.c
	@breif 		Implementation of single linked list using ADT in c
	@Author		Mohamed Shawky
	@date 		
	@copyrights copyright (c) 2022
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node_t;

node_t* create_list (int);
node_t* list_prepend(node_t*, int);
void list_print(node_t*);
node_t* list_search(int, node_t*);
void list_insert_after(node_t*, int);
void list_append(node_t*, int);
void list_delete_node(node_t*);
void list_delete_by_value(node_t*, int);


void main (){
	
	int choice, number;
	
	node_t* list = create_list(0);
	
	if (list != NULL){
		do {
			printf(" (1) Prepend list. \n (2) Print list. \n (3) Append list. \n (4) Quit.");
			printf("\n>> Choice = ");
			scanf("%d", &choice);
					
			switch(choice){
				
				case 1:
					printf("\n>> Number = ");
					scanf("%d", &number);
					list = list_prepend(list, number);
					break;
					
				case 2:
					list_print(list);
					break;
				
				case 3:
					printf("\n>> Number = ");
					scanf("%d", &number);
					list_append(list, number);
					break;
				
				case 4:
					printf(" THANKS YOU \n");
					break;
					
				default: 
					printf("\n>> Invalid Input!\n");
					
			}
		}while(choice != 4);
	}
	else {
		printf("\n>> List is not created!\n");
	}
		
return;
}

/**
	@brief This function creates a linked list form scratch , contains only one node.
	@param num input integer for the first node. 
	@return node_t* pointer to the first (head) node, NULL if malloc failed.
	@note this function calls malloc in bg, so make sure to check for NULL return if the list can not be created.
*/

node_t* create_list (int num){
	node_t* head = (node_t*) malloc(sizeof(node_t));
	if (head != NULL){
		head->data = num;
		head->next = NULL;
	}
	else {
		printf("Error: in file %s: in function %s: malloc failed to allocate a new node", __FILE__ , __FUNCTION__);
	}
		return head;
}

node_t* list_prepend(node_t* head, int num){	//insert front
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	if (new_node != NULL){
		new_node -> data = num;
		new_node->next = head;
		head = new_node;
	}
	else {
		printf("Error: in file %s: in function %s: malloc failed to allocate a new node", __FILE__ , __FUNCTION__);
	}
	return head;
}

void list_print(node_t* list){
	printf("-----------------------\n");
	while (list != NULL){
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n-----------------------\n");
}

node_t* list_search(int key, node_t* list){	//O(n)
	node_t* ret = NULL;
	while (list != NULL){
		if (list->data == key){
			ret = list;
			break;
		}
		list = list ->next;
	}
return ret;
}

void list_insert_after (node_t* node, int num){	//O(1)
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	if (node != NULL && new_node != NULL){
		new_node ->data = num;
		new_node->next = node->next;
		node->next = new_node;
	}
	else {
		printf("Error: in file %s: in function %s: malloc failed to allocate a new node", __FILE__ , __FUNCTION__);
	}
}

void list_append(node_t* head, int num){	//O(n)
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	while (new_node != NULL && head->next != NULL){
		head = head->next;
	}
	new_node->data = num;
	new_node -> next = head -> next;
	head -> next = new_node;
}

void list_delete_node(node_t* node){		//O(1)
	node_t* temp = node->next->next;
	free (node->next);
	node -> next = temp;
}

void list_delete_by_value(node_t* node, int num){
	//trailling pointer technique
	node_t* current = node;
	node_t* previous = NULL;
	while(current != NULL && current -> data != num){
		previous = current;
		current = current->next;
	}
	if (previous == NULL){
		node = node->next;
	}
	else{
		previous->next = current -> next;
	}
	free (current);
		
}