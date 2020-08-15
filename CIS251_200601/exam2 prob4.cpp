//
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_number);

void head_insert(NodePtr& head, int the_number);
{
	 NodePtr temp_ptr;
	 temp_ptr = new Node;

	 temp_ptr->data = the_number;

	 temp_ptr->link = head;
	 head = temp_ptr;
}