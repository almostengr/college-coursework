#include <iostream>
#include <string>
using namespace std;

class Node {
	string data;
	Node *next;
public:
	Node( ) : data(0), next(0) { 
	}
	Node(string e) : data(e), next(0) { 
	}
	Node(string e, Node *n) : data(e), next(n) { 
	}
	string GetData(void) { 
		return data; }
	Node *GetNext(void) { 
		return next; }
	void SetData(string e) { 
		data = e; }
	void SetNext(Node *n) { 
		next = n; }
	friend ostream& operator<<(ostream &, const Node &);
};

ostream& operator<<(ostream &os, const Node &n) {
	/*
	os << "<Node at location " << &n
		<< ": data=" << n.data
		<< ", next node is at location="
		<< n.next << ">";
		*/
	return os;
}

int main( ) {
	Node *a, *b, *c, *d, *e;
	a = new Node("Maggie");
	b = new Node("Lisa",a);
	c = new Node("Bart",b);
	d = new Node("Marge",c);
	e = new Node("Homer",d);

	Node* temp;
	temp = e;

	while(temp != 0){
		cout << temp->GetData() << endl;
		temp=temp->GetNext();
	}

	system("pause");
	return 0;
}