#ifndef __LIST__
#define __LIST__
#include "Iterator.hpp"

template <class T>

//DECLARING A CLASS; THE CLASS DEFINITION IS LOCATED SOMEWHERE ELSE
class List;

template <class T>
class ListIter;

template <class T>
class Node {
	T data;	//CURRENT NUMBER STORED IN NODE
	Node<T> *next;	//POINTS TO NEXT NODE
public:
	Node() {next = 0;}
	friend class List<T>;	//ALLOWED TO ACCESS OTHER DATA
	friend class ListIter<T>;
};


template <class T>
class List {
	Node<T> *head;
	friend class ListIter<T>;
public:
	List() {
		head = 0;
	}

	void add(T i) {
		Node<T> *tmp = head;
		Node<T> *n = new Node();
		n->data = i;
		if(head == 0) {
		//IF NODE IS EMPTY, ADD NEW DATA
			head = n;
			return;
		}
		while(tmp->next) {
		//
			tmp = tmp->next;
		}
		tmp->next = n;
	}

};

class ListIter: public Container<T> {
	//"PUBLIC ITERATOR" MEANS THAT IT WILL INHERIT
	Node *current;
public:
	ListIter(List& list) {
		current = list.head;
		//START AT THE HEAD OF THE LIST
	}
	bool hasMoreElements() {
		return current!=0;
		//IS THE CURRENT ELEMENT 0
	}

	T getValue() {
		return current->data;
	}

	void next() {
		if(current) {
			current = current->next;
		}
	}
};

#endif
