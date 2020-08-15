#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main(){
	string input;
	vector <string> names;
	vector <string>::iterator inames;
	vector <string>::reverse_iterator rnames;
	int a=0;

	cout << "Enter 10 names: " << endl;
	while(a<10){
		cin >> input;

		names.push_back(input);
		a++;
	}

	names.at(1)="Big Al";
	for(inames=names.begin(); inames!=names.end(); ++inames){
		cout << *inames << " ";
	}
	cout << endl;

	for(rnames=names.rbegin(); rnames!=names.rend(); ++rnames){
		cout << *rnames << " ";
	}
	
	cout << endl;
	system("pause");
};

/*	output

Enter 10 names:
Kenny Ram R James Earl Jones Billy Bob Thornton Ray
Kenny Big Al R James Earl Jones Billy Bob Thornton Ray
Ray Thornton Bob Billy Jones Earl James R Big Al Kenny
Press any key to continue . . .

output */