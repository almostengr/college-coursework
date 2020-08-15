#include <iostream>
#include <fstream> // I/O
using namespace std;

int value[127];
int read_input(ifstream& read_input, char character);
int find_max();
int max1, max2, max3, max4, max5, num, total=0;
char cmax1,cmax2,cmax3,cmax4,cmax5, character;
double percent1, percent2, percent3, percent4, percent5;

int read_input(ifstream& input, char character){

	while(input.get(character)){
		num=int(character);
		value[num] = value[num]++;
		total++;

		if(num==32)
			total--;
		if(num==10)
			total--;
	}
		return 0;
}

int find_max(){
	num=33;
	max1=max2=max3=max4=max5=0;
	cmax1,cmax2,cmax3,cmax4,cmax5=0;
	while(num<128){
		if(value[num]>max1){
			max5=max4;	cmax5=cmax4;
			max4=max3;	cmax4=cmax3;
			max3=max2;	cmax3=cmax2;
			max2=max1;	cmax2=cmax1;
			max1=value[num];
			cmax1 = int(num);
		}
		else if(value[num]>max2){
			max5=max4;	cmax5=cmax4;
			max4=max3;	cmax4=cmax3;
			max3=max2;	cmax3=cmax2;
			max2=value[num];
			cmax2 = int(num);
		}
		else if(value[num]>max3){
			max5=max4;	cmax5=cmax4;
			max4=max3;	cmax4=cmax3;
			max3=value[num];
			cmax3 = int(num);
		}
		else if(value[num]>max4){
			max5=max4;	cmax5=cmax4;
			max4=value[num];
			cmax4 = int(num);
		}
		else if(value[num]>max5){
			max5=value[num];
			cmax5 = int(num);
		}
		else{
		}
		num++;

		//cout << cmax1 << cmax2 << cmax3 << cmax4 << cmax5 << endl;
	}
	return 0;
}

void find_percent(){
	percent1 = ((double)max1/total) * 100;
	percent2 = ((double)max2/total) * 100;
	percent3 = ((double)max3/total) * 100;
	percent4 = ((double)max4/total) * 100;
	percent5 = ((double)max5/total) * 100;

	//return percent1, percent2, percent3, percent4, percent5;
}
int main(){ 
	ifstream input;      // For working with input file

	input.open("data.txt");
	read_input(input, character);
	input.close();                   // Close file
	find_max();
	find_percent();

	//START OF OUTPUT 
	cout << "The five most common characters were: " << endl;

	//cout.width(3);
	cout.setf(ios::left);
	cout << cmax1;
	cout.width(8);
	cout.setf(ios::right);
	cout << max1 << " times";
	cout.width(8);
	cout.setf(ios::right);
	cout.precision(4);
	cout << percent1 << "%" << endl;

	//cout.width(3);
	cout.setf(ios::left);
	cout << cmax2;
	cout.width(8);
	cout.setf(ios::right);
	cout << max2 << " times";
	cout.width(8);
	cout.setf(ios::right);
	cout.precision(4);
	cout << percent2 << "%" << endl;

	//cout.width(3);
	cout.setf(ios::left);
	cout << cmax3;
	cout.width(8);
	cout.setf(ios::right);
	cout << max3 << " times";
	cout.width(8);
	cout.setf(ios::right);
	cout.precision(4);
	cout << percent3 << "%" << endl;

	//cout.width(3);
	cout.setf(ios::left);
	cout << cmax4;
	cout.width(8);
	cout.setf(ios::right);
	cout << max4 << " times";
	cout.width(8);
	cout.setf(ios::right);
	cout.precision(4);
	cout << percent4 << "%" << endl;

	//cout.width(3);
	cout.setf(ios::left);
	cout << cmax5;
	cout.width(8);
	cout.setf(ios::right);
	cout << max5 << " times";
	cout.width(8);
	cout.setf(ios::right);
	cout.precision(4);
	cout << percent5 << "%" << endl;

	cout << endl << "Characters not found: ";
	for(num=33; num<127; num++){
		if(value[num]==0)
			cout << char(num) << " ";
	}
	cout << endl << endl;


	//END OF OUTPUT 
	system("pause");
	return 0;
}