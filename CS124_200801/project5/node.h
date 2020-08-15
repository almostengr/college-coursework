#include "text.h"

#ifndef NODE
#define NODE

class Node {
	string data;
	Node *left;		//pointer to left node
	Node *right;	//pointer to right node
public:
	Node();		//default constructor
	Node(string);	//constructor
	friend class Tree;
	friend ostream& operator<<(ostream&, const Node&);
};

#endif