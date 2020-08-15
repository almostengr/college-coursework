#include <iostream>
#include <list>
#include <string>
using namespace std;

int sub_function();

#include <iostream>
#include <windows.h> // include this header
#include <vector>
using namespace std;
int main( )
{ LARGE_INTEGER LI1,LI2,LIF;
QueryPerformanceFrequency(&LIF);
double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
double dt, fq = 1.0/number;
int f = LIF.LowPart;
vector<int> v;
QueryPerformanceCounter(&LI1); // here is where we start timing
for (int a=1; a<=100000; a++)
v.insert(v.begin(),a);

sub_function();

QueryPerformanceCounter(&LI2); // here is where we finish timing
dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
cout << "\tfinished with time " << dt << endl;
system("pause");
return 0;
}



int sub_function(){
	//declarations
	list <string>s, copy;
	list <string>::iterator si;
	string name;
	//insert names using for loop
	cout << "Enter 10 names into the list" << endl;
	for (int i=0;i<10;i++){
		cin >> name;
		s.push_back(name);
	}
	cout << endl;
	//uses a copy, puts odds in front, evens in back
	for (si=s.begin();si!=s.end();++si){
		if((*si).length()%2==0){
			string temp=*si;
			copy.push_back(temp);
		}
		else{
			string temp=*si;
			copy.push_front(temp);
		}
	}
	//makes original container so its sorted odd/even
	s=copy;
	cout << s.front()<<endl<<endl;
	//wipes copy of container clean for later use
	copy.clear();
	//puts everything in original container into copy container that is not "Bigal"
	for(si=s.begin(); si != s.end(); si++){
		if(*si != "BigAl" || "bigal"){
			copy.push_back(*si);
		}
	}
	//again, makes a copy the original
	s=copy;

	//output list in reverse order
	s.reverse();
	for(si=s.begin(); si != s.end(); si++){
		cout << *si << " " << endl;
	}
	system("pause");
	return 0;
}