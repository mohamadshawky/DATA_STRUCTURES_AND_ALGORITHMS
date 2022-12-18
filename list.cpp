#include <iostream>
#include <list>
#include <forward_list>

int main(){
	/* Doubly linked list */
	std::list <int> mylist = {1,2,3,4,5};
	
	/* Single linked list */
	std::forward_list <int> myfwdlist = {2,4,6,8};
	
	mylist.push_back(25);		// append
	mylist.push_front(2);		//insert front
	
	for (auto /*std::list<int>::iterator */ it = mylist.begin(); it != mylist.end(); it++){
		std::cout << *it << ' ';
	}	
}