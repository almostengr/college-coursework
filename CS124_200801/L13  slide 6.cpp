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
	int size(void) const;
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
};

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

istream& operator>>(istream& is, List& l) {
	return is;
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
int List::size(void) const {
	Node *temp = start;
	int length = 0;
	while (temp != 0) {
		length++;
		temp = temp->getNext();
	}
	return length;
}

int main( ) {
	List a;
	int N, value;
	char ch;
	cout << "Enter a list  of integers : ";
	cin >> ch>> N;
	for(int x=0;x<N; x++)
	{
		cin>>value;
	a.push_back(value);
	}
	cin>>ch;
	cout << "You entered " << a << " which has " << a.size() << " elements." << endl;
	return 0;
}

/*	OUTPUT

Enter a list  of integers : 2 5 8 6 0 3 4 7
You entered < 8 6 0 3 4 > which has 5 elements.
Press any key to continue . . .

*/
