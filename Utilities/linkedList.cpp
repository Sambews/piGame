#include "linkedList.h"

template <typename T>
void LinkedList<T>::add(T value){
	Node<T>* n = new Node(value);
	if(tail){
		tail->next = n;
		n->next = head;
		tail = n;
	} else {
		head = n;
		tail = n;
		n->next = n;
	}
}


//Deletes the first instance of the target value. Returns 1 if success, 0 if no deletion.
template <typename T>
int LinkedList<T>::remove(T target){
	Node<T>* ptr = head;
	Node<T>* ptr2 = head;
	
	if(ptr->val == target){
		head = ptr->next;
		tail->next = head;
		delete ptr;
		return 1;
	}

	ptr = ptr->next;

	while(ptr != head){
		if(ptr->val == target){
			if(ptr == tail){
				ptr2->next = head;
				tail = ptr2;
				delete ptr;
			} else {
				ptr2->next = ptr->next;
				delete ptr;
			}
			return 1;
		} else {
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
	}

	return 0;
}


template <typename T>
void LinkedList<T>::print(){
	Node<T>* ptr = head;
	std::cout << ptr->val << ", ";
	ptr = ptr->next;
	
	while(ptr->next != head){
		std::cout << ptr->val << ", ";
		ptr = ptr->next;
	}
	
	std::cout << ptr->val << '\n';
}


template <typename T>
void LinkedList<T>::printEnds(){
	std::cout << "Head: " << head->val  << '\n';
	std::cout << "Tail: " << tail->val << '\n';
}
