#ifndef __NODE__
#define __NODE__
#include "Container.hpp"

template <class T>
class Node {
	T value;	
	Node<T> *next;
	Node<T> *prev;
	static int counter;
public:
	Node(T v);	
	~Node() {
		Node<T>::counter--;
	}
	Node(T v,Node<T>*, Node<T>*);	
	Node<T>* getNext();
	Node<T>* getPrev();
	T getValue();

	static int getCounter(){ return counter;}
    template <class S> friend class Container;

//	static int getCounter() {return counter;}
};

template <class T>
int Node<T>::counter = 0;


template <class T>
Node<T>::Node(T v) {
	this->value = v;
	this->next = 0;	
	this->prev = 0;	
	Node<T>::counter ++;
}

template <class T>
Node<T>::Node(T v, Node<T> *p, Node<T> *n) {
	Node<T>::counter ++;
	this->value = v;
	this->next = n;	
	this->prev = p;	
}

template <class T>
Node<T> *Node<T>::getNext() {
	return next;
}

template <class T>
Node<T> *Node<T>::getPrev() {
	return prev;
}

template <class T>
T Node<T>::getValue() {
	return value;
}
#endif
