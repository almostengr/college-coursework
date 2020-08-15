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
	List() : start(0) { }
	List(const List&);
	~List();
	void push_back(int e) {
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
	List& operator=(const List&);
	friend ostream& operator<<(ostream&, const List&);
};

List::~List(){
	if (start != 0){
		Node *t1, *t2;
		t1 = start;
		while(t1 !=0){
			t2=t1;
			t1 = t1 -> getNext();
			cout << "deleting 2 " << t2->getData() << endl;
			delete t2;
		}
	}
}
/*
List& List::operator=(const List& a){
	start = 0;
	Node *temp = a.start;
	while(temp != 0){
		push_back (temp -> getData());
		temp = temp ->getNext();
	}
	return *this;
}
*/

List ::List(const List& a){
	cout << "copy" << endl;
	start=0;
	Node *temp = a.start;
	while(temp){
		push_back( temp->getData() );
		temp=temp->getNext();
	}
}

List& List::operator=(const List& a){
	if(this ==&a) return *this;
	if(start != 0){//destructor
		Node *t1, *t2;
		t1=start;
		while (t1 != 0){
			t2 = t1;
			t1 = t1 -> getNext();
			delete t2;
			cout << "deleting " << endl;
		}
	}
	start = 0;
	Node *temp = a.start;
	while (temp !=0){
		push_back (temp -> getData());
		temp = temp ->getNext();
	}
	return *this;
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

int main( ) {
	List a, b;
	cout << "Adding 10, 20, 30, 40, and 50 to a" << endl;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	a.push_back(50);
	cout << "List a is " << a << endl;
	cout << "Assigning a to b" << endl;
	b = a;
	cout << "List b is " << b << endl;
	cout << "Adding 60 and 70 to b" << endl;
	b.push_back(60);
	b.push_back(70);
	cout << "List b is now " << b << endl;
	cout << "List a is now " << a << endl;
	cout << "Declaring a new list c that is the same as a" << endl;
	List c(a);
	cout << "Adding 80 and 90 to c" << endl;
	c.push_back(80);
	c.push_back(90);
	cout << "List c is now" << c << endl;
	cout << "List b is now" << b << endl;
	cout << "List a is now" << a << endl;
	//function1();
	//function2();
	//system("pause");
}

void function1 (){
	cout << "I am function1" << endl;
}

void function2(){
	cout << "I am function2" << endl;
}

/*	output

copy
Adding 80 and 90 to c
List c is now< 10 20 30 40 50 80 90 >
List b is now< 10 20 30 40 50 60 70 >
List a is now< 10 20 30 40 50 >
deleting 2 10
deleting 2 20
deleting 2 30
deleting 2 40
deleting 2 50
deleting 2 80
deleting 2 90
deleting 2 10
deleting 2 20
deleting 2 30
deleting 2 40
deleting 2 50
deleting 2 60
deleting 2 70
deleting 2 10
deleting 2 20
deleting 2 30
deleting 2 40
deleting 2 50
Press any key to continue . . .

*/