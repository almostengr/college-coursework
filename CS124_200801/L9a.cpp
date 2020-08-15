#include <iostream>
#include <string>
using namespace std;

int main( ) {
	int *p1, *p2; //create two variables that can hold pointers of type int

	p1=new int;	//a nameless variable can be referred to as *p1 (variable point to by p1)

	*p1=42;	//p1 is set to 42

	p2=p1;	//p2 points to the same variable as p1
	cout << " *p1 = " << *p1 << endl;
	cout << " *p2 = " << *p2 << endl;

	*p2 = 53;	//p2 is set to 53, now p1 and p2 point to 53
	cout << " *p1 = " << *p1 << endl;
	cout << " *p2 = " << *p2 << endl;

	p1 = new int;	//a nameless viarable can be refrred to as *p1 (variable pointed to by p1)

	*p1=88;	//p1 is set to 88

	cout << " *p1 = " << *p1 << endl;
	cout << " *p2 = " << *p2 << endl;
	cout << "Hope you got the point of this example." << endl;

	system("pause");
	return 0;
}

/*	OUTPUT

 *p1 = 42
 *p2 = 42
 *p1 = 53
 *p2 = 53
 *p1 = 88
 *p2 = 53
Hope you got the point of this example.
Press any key to continue . . .

OUTPUT	*/