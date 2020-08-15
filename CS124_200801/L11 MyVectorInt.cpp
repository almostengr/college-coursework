#include <iostream>
#include <string>
using namespace std;

class MyVectorInt {
	int currentSize;
	int capacity;
	int *data;
public:
	MyVectorInt( );		//default constructor
	MyVectorInt(int);	//constructor
	void push_back(int);	//push back for vector
	void pop_back(void);
	void pop_front(void);
	int size(void) const;	//size of vector
	int at(int a) const;	//location in vector
	int getCap(){
		return capacity;
	}
	int getCS( ){
		return currentSize;
	}
};

void MyVectorInt::pop_back(void){
	currentSize--;
	if(capacity - currentSize >15){	//
		//if the capacity is greater than 15, allocate a smaller
		//arrray (reduce by 10) and move things into the smaller vector
		cout << "Reducing space" << endl;
		cout << getCap() << " " << getCS() << endl;
		capacity = capacity - 10;
		int *p = data;
		data = new int[capacity];	//new capacity
		for (int a=0; a < currentSize; a++)
			data[a] = p[a];
		delete [] p;
	}
}

void MyVectorInt::pop_front(void){
	for(int i=0; i < currentSize-1; i++)
		data[i]=data[i+1];
	currentSize--;
	if(capacity - currentSize >15){
		cout << "Reducing space" << endl;
		cout << getCap() << " " << getCS() << endl;
		capacity = capacity - 10;
		int *p = data;
		data = new int[capacity];
		for (int a=0; a < currentSize; a++)
			data[a] = p[a];
		delete [] p;}
}

MyVectorInt::MyVectorInt() : currentSize(0), capacity(5) {
	data = new int[5]; 
}

MyVectorInt::MyVectorInt(int c) : currentSize(0), capacity(c) { 
	data = new int[c]; 
}

void MyVectorInt::push_back(int e) {
	if (currentSize < capacity) {
		data[currentSize] = e;
		currentSize++;
	}
	else {
		cout << "Adding more space" << endl;
		capacity = capacity + 5;
		int *p = data;
		data = new int[capacity];
		for (int a=0; a<currentSize; a++)
			data[a] = p[a];
		delete [] p;

		data[currentSize] = e;
		currentSize++;
	}
}

int MyVectorInt::size(void) const {
	return currentSize; 
}

int MyVectorInt::at(int a) const {
	if ( (a > -1) && (a < currentSize) )
		return data[a];
	else return 0;
}

int main ( ) {
	MyVectorInt v;
	int a;

	for (a=0; a<50; ++a)
		v.push_back(a);
	cout << endl << endl << "capacity is: " << v.getCap()<< endl;
	cout << "current size is: " << v.getCS()<< endl << endl;
	a = 0;
	while ( a < v.size() ) {
		cout << v.at(a) << " ";
		++a;
	}
	cout << endl;
	system("pause");

	for (a=0; a<20; ++a)
		v.pop_back();
	cout << endl << endl << "capacity is: " << v.getCap()<< endl;
	cout << "current size is: " << v.getCS()<< endl << endl;
	a = 0;
	while ( a < v.size() ) {
		cout << v.at(a) << " ";
		++a;
	}
	cout << endl;
	for (a=0; a<20; ++a)
		v.pop_front();
	cout << endl << endl << "capacity is: " << v.getCap() << endl;
	cout << "current size is: " << v.getCS()<< endl << endl;
	a = 0;
	while ( a < v.size() ) {
		cout << v.at(a) << " ";
		++a;
	}

	cout << endl;
	system("pause");
	return 0;
}

/* OUTPUT

Adding more space
Adding more space
Adding more space
Adding more space
Adding more space
Adding more space
Adding more space
Adding more space
Adding more space


capacity is: 50
current size is: 50

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
Press any key to continue . . .
Reducing space
50 34


capacity is: 40
current size is: 30

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

Reducing space
40 24
Reducing space
30 14


capacity is: 20
current size is: 10

20 21 22 23 24 25 26 27 28 29
Press any key to continue . . .

OUTPUT */