//linkedlist_ADT.h
//doubly linked list
#ifndef _LINKEDLIST_ADT_H
#define _LINKEDLIST_ADT_H

typedef struct node{
	int data;
	struct node* next;
}node_t;

typedef struct ll_t linked_list_t;
typedef linked_list_t* Linked_List_handle_t;		//Linked_List_handle_t exposed to user so @ .h & in all imp. so include in .c

Linked_List_handle_t ll_create(int data);
void ll_destroy(Linked_List_handle_t me);
void ll_insert_front(Linked_List_handle_t me, int data);
void ll_insert_before(Linked_List_handle_t me, int data);
void ll_append(Linked_List_handle_t me, int data);
void ll_delete_next(Linked_List_handle_t me, node_t* n);
void ll_find(Linked_List_handle_t me, int key);
void ll_sort(Linked_List_handle_t me);			//bubble
void ll_print(Linked_List_handle_t me);
unsigned int ll_get_size(Linked_List_handle_t me);

#endif /* _LINKEDLIST_ADT_H */