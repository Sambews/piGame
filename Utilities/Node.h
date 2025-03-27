#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
	public:
		T val;
		Node* next = nullptr;

		Node();
		Node(T val){this->val = val;}
		Node(T val, Node* next){this->val = val; this->next = next;}
};
#endif
