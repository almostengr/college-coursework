#include "node.h"

Node::Node(): data("Unknown Author"), left(0), right(0) {}	//default constructor
Node::Node(string e) : data(e), left(0), right(0) {}

ostream& operator<<(ostream& os, const Node& n) {
	if (n.left) 
		os << *(n.left);
	os << n.data << "(" << &n << ") ";
	if (n.right) 
		os << *(n.right);
	return os;
}