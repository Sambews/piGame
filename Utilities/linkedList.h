#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>

template <typename T> class LinkedList{
	private:
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;

	public:
		LinkedList(){}
		~LinkedList(){}

		Node<T>* getHead(){return head;}
		void setHead(Node<T>* p){head = p;}

		Node<T>* getTail(){return tail;}
		void setTail(Node<T>* p){tail = p;}

		void add(T);
		int remove(T);
		void print();
		void printEnds();
};
#endif
