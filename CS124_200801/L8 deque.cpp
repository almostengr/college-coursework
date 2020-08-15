#include <iostream>
#include <deque>
using namespace std;

void main(){
	deque<int> d;
	deque<int>::iterator di;
	int a;
	for (a=0; a<10; ++a)	//adds numbers 9 thru 0 into deque
		d.push_back(a);
	for (a=0; a<10; ++a)	//adds numbers 0 thru 9 into deque
		d.push_front(a);
	for (di=d.begin(); di!=d.end(); ++di) //outputs numbers 9-0 0-9
		cout << *di << " ";
	cout << endl;

	system("pause");
}

/*	OUTPUT

9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
Press any key to continue . . .

OUTPUT */