#include <iostream>
#include <string>

using namespace std;

class Node {
	int data;
	Node *next;
public:
	Node() : data(0), next(0) { }
	Node(int e) : data(e), next(0) { }
	Node(int e, Node* n) : data(e), next(n) { }
	Node *getNext(void) const { return next; }
	int getData(void) const { return data; }
	void setData(int e) { data = e; }
	void setNext(Node* n) { next = n; }
};

class List {
	Node *start;
public:
	List();
	void push_front(int e);
	void push_back(int e);
	int size(void) const;
	void print(void) const;
};

List::List() : start(0) { }
void List::push_front(int e) {
	Node *newone = new Node(e,start);
	start = newone;
	return;
}
void List::push_back(int e) {
	Node *newone = new Node(e);
	if (start == 0)
		start = newone;
	else {
		Node *temp = start;
		while (temp->getNext() != 0)
			temp = temp->getNext();
		temp->setNext(newone);
	}
	return;
}
int List::size(void) const {
	Node *temp = start;
	int length = 0;
	while (temp != 0) {
		length++;
		temp = temp->getNext();
	}
	return length;
}
void List::print(void) const {
	Node *temp = start;
	cout << "[";
	while (temp != 0) {
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	cout << "]";
	return;
}

int main(){
	List myList;
	myList.push_back(1);
	myList.push_front(2);
	myList.push_back(3);
	myList.push_front(4);
	myList.push_back(5);
	myList.print();
	cout << endl;
	cout << myList.size() 
		<< endl;
}

/*	OUTPUT
[4 2 1 3 5 ]
5
Press any key to continue . . .
*/
