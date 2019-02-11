//Kenneth Robinson
#include <iostream>
using namespace std;


int x;

void main()
{
	//start program 

do {
cout << "\n1.   Option 1\n2.   Option 2\n3.   Option 3\n4.   Exit\n\nSelect Option ";
cin >> x;
//  add your code here

if (x = 1)
{
	cout << "\nOption 1" << endl;
}
else if (x = 2)
{
	cout << "\nOption 2" << endl;
}
else if (x = 3)
{
    cout << "\nOption 3" << endl;
}
else if (x = 4)
{
    cout << "\nEnd of program" << endl;
}
else
{
	cout << "\nInvalid option. Please choose again.\n" << endl;
}
}while(x != 4);

}//end program