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
	void push_front(int);
	void push_back(int);
	Node *find(int);
	void insert(Node *, int);
	friend ostream& operator<<(ostream&, const List&);
};

Node *List::find(int e) {
	Node *temp = start;
	while (temp) {
		if (temp->getData() == e) return temp;
		temp = temp->getNext();
	}
	return 0;
}

void List::insert(Node *ptr, int e) {
Node*newone=new Node(e, ptr->getNext());
ptr->setNext(newone);
	return;
}

ostream& operator<<(ostream& os, const List& l) {
	os << "< ";
	Node *temp = l.start;
	while (temp) {
		os << temp->getData() << " ";
		temp = temp->getNext();
	}
	os << ">";
	return os;
}

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

int main( ) {
	List a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	a.push_back(50);
	cout << a << endl;
	Node *temp;
	temp = a.find(10);
	a.insert(temp, 15);
	temp = a.find(30);
	a.insert(temp, 35);
	temp = a.find(50);
	a.insert(temp, 1);
	cout << a << endl;
}


/**	output

< 10 20 30 40 50 >
< 10 15 20 30 35 40 50 1 >
Press any key to continue . . .

*/