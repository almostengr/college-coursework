
#include "node.h"	//include node header 

Node::Node(){	//default constructor
    data = 0; 
    next = 0; 
    prev = 0;
}


Node::Node(int d){	//copy constructor
    data = d; 
    next = 0; 
    prev = 0;
}


Node::Node(int d, Node* n){	//adds number and pointer 
    data = d; 
    next = n; 
    prev = 0;
}


Node::Node(int d, Node* n, Node* p){	//inserts a number between two existing numbers
    data = d; 
    next = n; 
    prev = p;
}


Node* Node::getNext(void) const{ //gets next node
    return next; 
}


Node* Node::getPrev(void) const{ //gets previous node
    return prev; 
}


int Node::getData(void) const{	//gets data in node
    return data;
}


void Node::setData(int e){	//sets the value of a node
    data = e; 
}


void Node::setNext(Node* n){	//sets the pointer to next node
    next = n; 
}


void Node::setPrev(Node* p){	//sets pointer to preceding node
    prev = p; 
}


ostream& operator<<(ostream& os, Node& n){	//output operator
    os << "[" << n.data << "]";
    return os;
}