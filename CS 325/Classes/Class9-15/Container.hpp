#ifndef __CONTAINER__
#define __CONTAINER__
#include "Node.hpp"

template <class T>
class Node;


template <class T>
class Container {
    Node<T> *head, *tail;
    int size;

public:
    Container() {
        head = tail = 0;
        size = 0;
    }	

    ~Container() {
        Node<T> *n = head;
        while(n) {
            n = n->next;
            delete head;
            head = n; 
        }
    }

    Node<T> *getFront() {
        return head;
    }
    Node<T> *getBack() {
        return tail;
    }
    Node<T> *insertFront(T v) {
        Node<T> *node = new Node<T>(v, 0, head );
        if(head)
            head->prev = node;
        head = node;
		if(!tail) tail=head;
        size++;
		return node;
    }

    Node<T> *insertBack(T v) {
        Node<T> *node = new Node<T>(v, tail, 0);
        if(tail)
            tail->next = node;
        tail = node;
		if(!head) head=tail;
        size++;
		return node;
    }

    Node<T> *insertAfter(Node<T> *n, T v) {
        if(n) {
            Node<T> *node = new Node<T>(v, n, n->next);
            if(n->next) 
                n->next->prev = node;     
            n->next = node;
			size++;
            return node;
        }
		return 0;
    }

    Node<T>* removeFront() {
        Node<T> *node = head;
        if(head && head->next) {
            head->next->prev = 0;
            head = head->next;
        } else {
            head = 0;
        }
        size--;
        return node;
    }
        
    Node<T> *removeBack() {
        Node<T> *node = tail;   
        if(tail && tail->prev) {
            tail->prev->next = 0;
            tail = tail->prev;
        } else { 
            tail = 0;
        }
        size--;
        return node;
    }

    Node<T> *removeNode(Node<T> *n) {
        if(n->prev) {
            n->prev->next = n->next;
        }
        if(n->next) {
            n->next->prev = n->prev;
        }
        size--;
        return n;
    }

    int getSize() {
        return size;
    }
};

#endif
