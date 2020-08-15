/*	MAIN.CPP 	*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
//#include "csv.hpp"
//#include "csv.cpp"
using namespace std;

int main(){

	vector<int> v;

	ifstream in_stream;
	in_stream.open("input1.csv");
	
	if(in_stream.fail()){
		//IF OPENING INPUT FILE FAILS
		cout << "Input file opening failed.\n" << endl;
		exit(1);
	}
	else{
		//IF OPENING INPUT FILE SUCCEEDS
		
		string stockSymbol, time, value1, value2, value3, value4, volume;

		while(getline(in_stream, stockSymbol,',')){
			while(getline(in_stream, time, ',')){
				while(getline(in_stream, value1, ',')){
					while(getline(in_stream, value2, ',')){
						while(getline(in_stream, value3, ',')){
							while(getline(in_stream, value4, ',')){
								while(getline(in_stream, volume)){

									cout << stockSymbol << " | ";
									cout << time << " | ";
									cout << value1 << " | ";
									cout << value2 << " | ";
									cout << value3 << " | ";
									cout << value4 << " | ";
									cout << volume << " | ";

									cout << "\n\n";

									system("pause");

								};
							};
						};
					};
				};
			};
		};

		
	}

	return 0;
	
	in_stream.close();
};