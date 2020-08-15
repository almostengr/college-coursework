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
	int pop_front();
	int pop_back();
	friend ostream& operator<<(ostream&, const List&);
};

int List::pop_front(){
int answer;
if(start!=0){
answer = start->getData();
Node *save = start;
start=start->getNext();
delete save;}
else answer = -999; // or any other sentinel value
return answer;
}



int List::pop_back(){
int answer;
if(start!=0){
Node *t1 = start,*t2;
while(t1->getNext()!=0){
t2=t1;
t1=t1->getNext();}
answer=t1->getData();
t2->setNext(0);
delete t1;}
else answer = -999; // or any other sentinel value
return answer;
}




Node *List::find(int e) {
	Node *temp = start;
	while (temp) {
		if (temp->getData() == e) return temp;
		temp = temp->getNext();
	}
	return 0;
}

void List::insert(Node *ptr, int e) {
Node *newone = new Node(e, ptr->getNext());
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
	int f = a.pop_front();
	cout << a << endl;
	cout << "The popped value was " << f << endl;
	int b = a.pop_back();
	cout << a << endl;
	cout << "The popped value was " << b << endl;
	return 0;
}


/*	output

< 10 20 30 40 50 >
< 10 15 20 30 35 40 50 1 >
< 15 20 30 35 40 50 1 >
The popped value was 10
< 15 20 30 35 40 50 >
The popped value was 1
Press any key to continue . . .

*/