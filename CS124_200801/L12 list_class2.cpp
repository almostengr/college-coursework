#include <iostream>
#include <string>
#include <cmath>
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
	double average(void) const;
};
double List::average(void) const{
/*
	Node*temp = start;
	int sum = 0;
	while(temp!=0){
		sum+=temp->getData();
		temp=temp->getNext();
	}
	return (double)sum/size();
*/

	double answer;
	int sum=0;
	Node *temp = start;
	while (temp != 0) {
		sum+=temp->getData();
		temp = temp->getNext();
	}
	answer=(double)sum/size();
	return answer;
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

int main ( ){
	List l;
	int num;
	for(int i=0; i<100; i++){
		num = rand()%100+1;
		if (num%2==0)
			l.push_back(num);
		else 
			l.push_front(num);
	}
	l.print();

	cout << endl << "Average: " << l.average() << endl;

	return 0;
}

/*	OUTPUT

[83 19 39 27 45 9 77 67 41 57 55 85 49 7 51 71 91 47 49 65 43 41 7 89 43 91 17 7
9 63 45 69 65 23 95 13 39 27 19 17 83 93 3 5 37 43 65 63 59 79 25 1 35 42 68 70
6 46 82 28 62 92 96 28 92 54 22 96 48 72 70 68 100 36 4 12 34 74 42 12 54 48 58
38 60 24 42 30 36 6 30 2 94 30 24 32 40 24 38 30 42 ]
Average: 47.48
Press any key to continue . . .

*/