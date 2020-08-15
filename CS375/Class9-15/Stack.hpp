#ifndef __STACK__
#define __STACK__

#include "Container.hpp"

template <class T>
class Stack:private Container<T> {
public:
	Stack():Container<T>() {
	}
	
	bool push(T v) {
		Node<T> *n =Container<T>::insertFront(v);
		return (n!=0);
	}
	
	T pop() {
		Node<T> *f = Container<T>::removeFront();
		T v = f->getValue();
		delete f;	
		return v;
	}

	int getSize() {
		Container<T>::getSize();
	}
};
#endif
