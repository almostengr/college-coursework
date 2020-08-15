#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string name;
	vector<string> data;

	cout << data.size() << endl;
	//	data.push_back();
	cout << data.size() << endl;
	int count = 10;
	cout << "Enter 10 names: ";
	//cin >> count;
	for (int a=0; a < count; ++a){
		cin >>name;
		data.push_back(name);
	}
	cout << data.size() << endl;
	cout << data.at(0) << endl;
	cout << data.back() << endl;
	cout << data.front() << endl;
	cout << "Current capacity of data is " << data.capacity() << endl;
	cout << "Data currently in the vector: " << endl;
	for (int i=0; i < data.size(); i++){
		cout << data[i] << endl;	
		//cout << data.front() << " " << data.back() << endl;
	}
	system("pause");
	return 0;
}

/*	OUTPUT

0
0
Enter 10 names: Kenny Ram Johnny Billy Bob Thornton James Earl Jones Barney
10
Kenny
Barney
Kenny
Current capacity of data is 13
Data currently in the vector:
Kenny
Ram
Johnny
Billy
Bob
Thornton
James
Earl
Jones
Barney
Press any key to continue . . .

OUTPUT */