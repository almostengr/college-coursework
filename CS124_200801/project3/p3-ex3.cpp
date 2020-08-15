#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){

	list<string>s, copy;
	list<string>::iterator si;
	string name;

	cout << "Enter 10 names into the list. " << endl;
	for (int i=0; i<10; i++){
		cin >> name;
		s.push_back(name);
	}
	cout << endl;

	for (si=s.begin(); si != s.end(); ++si){
		if((*si).length()%2==0){
			string temp=*si;
			copy.push_back(temp);
		}
		else{
			string temp=*si;
			copy.push_front(temp);
		}
	}

	s=copy;
	cout << s.front() << endl << endl;

	copy.clear();

	for(si=s.begin(); si != s.end(); si++){
		if(*si != "BigAl" || "bigal"){
			copy.push_back(*si);
		}
	}

	s=copy;

	s.reverse();
	for(si=s.begin(); si != s.end(); si++){
		cout << *si << " " << endl;
	}
	system("pause");
	return 0;
}


/*	START OF OUTPUT

Enter 10 names into the list.
Barney
Big Bird
Teletubbies Matlock Seinfield Cookie Monster
Frankstein
Jaws

Monster

Jaws
Frankstein
Cookie
Bird
Barney
Big
Teletubbies
Matlock
Seinfield
Monster
Press any key to continue . . .

END OF OUTPUT */