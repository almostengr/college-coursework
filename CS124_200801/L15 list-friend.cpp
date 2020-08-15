#include <iostream>
#include <string>

using namespace std;

// class List; 

class Node {
	int data;
	Node *next;
public:
	Node() : data(0), next(0) { }
	Node(int e) : data(e), next(0) { }
	Node(int e, Node* n) : data(e), next(n) { }
	
	int getData( ) { return data; }
	Node* getNext( ) { return next; }
	void setData(int e) { data = e; }
	void setNext(Node* n) { next = n; }
	
	friend class List;
	friend ostream& operator << (ostream&, const List&);
};

class List {
	Node *start;
public:
	List() : start(0) { }
	List(const List&);
	~List();
	void push_back(int);
	List& operator=(const List&);
	friend ostream& operator<<(ostream&, const List&);
};

List::List(const List& a) {
	start = 0;
	Node *temp = a.start;
	while (temp) { push_back( temp->getData() ); temp = temp->getNext(); }
}

List::~List( ) {
	if (start != 0) {
			Node *t1, *t2;
			t1 = start;
			while (t1 != 0) { t2 = t1; t1 = t1->getNext(); delete t2; }
	}
}
void List::push_back(int e) {
		Node *newone = new Node(e);
		if (start == 0)
			start = newone;
		else {
			Node *temp = start;
			while (temp->getNext() != 0) temp = temp->getNext();
			temp->setNext(newone);
		}
		return;
	}
List& List::operator=(const List& a) {
	if (this == &a)
		return *this;
	else
		if (start != 0) {
			Node *t1, *t2;
			t1 = start;
			while (t1 != 0) { t2 = t1; t1 = t1->getNext(); delete t2; }
		}
	start = 0;
	Node *temp = a.start;
	while (temp) { push_back( temp->getData() ); temp = temp->getNext(); }
	return *this;
}

ostream& operator<<(ostream& os, const List& l) {
	os << "< ";
	Node *temp = l.start;
	while (temp) { os << temp->getData() << " "; temp = temp->getNext(); }
	os << ">";
	return os;
}

int main( ) {
	List a, b;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	b = a;
	cout << a << endl;
	cout << b << endl;
	b.push_back(40);
	cout << a << endl;
	cout << b << endl;
	List z(a);
	z.push_back(50);
	cout << a << endl;
	cout << b << endl;
	cout << z << endl;
	return 0;
}


/*	output

< 10 20 30 >
< 10 20 30 >
< 10 20 30 >
< 10 20 30 40 >
< 10 20 30 >
< 10 20 30 40 >
< 10 20 30 50 >
Press any key to continue . . .

*/