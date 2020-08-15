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
	void average(void) const;
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

double List::average(void) const{
	
	Node*temp = start;
	int sum = 0;
	while(temp!=0){
		sum+=temp->getData();
		temp=temp->getNext();
	}
	return (double)sum/size();

	
	/*double answer;
	int sum=0;
	Node *temp = start;
	while (temp != 0) {
		sum+=temp->getData();
		temp = temp->getNext();
	}
	answer=(double)sum/size();
	return answer;
	*/
}
int main(){
	List myList;
	n = srand(time(0));
	if(
	for(int n=1;n<=100;n++){
		myList.push_front(n);
		n++;
	}
	for(int n=2;n<=100;n++){
		myList.push_back(n);
		n++;
	}
	myList.print();
	myList.average();
	cout << endl;
	//cout << myList.size() << endl;
	
	system("pause");
}