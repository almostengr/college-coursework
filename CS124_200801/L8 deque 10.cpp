#include <iostream>
#include <deque>
using namespace std;

void main(){
	
	deque <int> d;
	deque <int>::iterator di;
	int a;

	for (a=0; a<100; ++a){
		d.push_front(a);	//adds dbers 9 thru 0 into deque
	}

	for (a=1; a<100; ++a){
		d.push_back(a);	//adds dbers 0 thru 9 into deque
	}

	for(di=d.begin(); di!=d.end(); ++di){
		cout << *di << " ";	//outputs dbers 9-0 then 0-9
	}
	cout << endl;

	system("pause");
}