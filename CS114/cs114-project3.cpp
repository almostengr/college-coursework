#include <iostream>
using namespace std;

void is_neg();
void convert_neg();
void num_to_eng();
void convert_ones();
void convert_tens();
void convert_teens();

int input, value, divisor_10, level;

void main( ){ 
	cout << "Enter an integer (or zero to exit): ";
	cin >> input;

	while(input != 0){
		is_neg();
		num_to_eng();

		cout << endl << endl;

		cout << "Enter an integer (or zero to exit): ";
		cin >> input;
	};

	system("pause");
};
void is_neg(){
	if(input < 0){
		cout << "Negative ";
		convert_neg();
	}
};
void convert_neg(){
	input = input - input - input;
};
void next_step(){
	value = value * divisor_10;
	level = level/10;
	input = input - value;
}
void num_to_eng(){
	divisor_10 = 1000000000, level = 999999999;
	if (input> 999999999){
		divisor_10 = 1000000000;
		value = input / divisor_10;
		convert_ones();
		cout << "Billion ";
		next_step();
	}
	if(input > 999999){
		if(input > 99999999){
			divisor_10 = 100000000;
			value = input / divisor_10;
			if(value>0){
				convert_ones();
				cout << "Hundred ";
				next_step();
			}
			if(input > 9999999){
				divisor_10 = 10000000;
				value = input / divisor_10;
				if(value>0){
					convert_tens();
					next_step();
				}
			}
			if(input > 999999){
				divisor_10 = 1000000;
				value = input / divisor_10;
				if(value > 0){
					convert_ones();
					next_step();
				}
			}
		}
		cout << "Million ";
	}
	if(input > 999){
		if(input > 99999){
			divisor_10 = 100000;
			value = input / divisor_10;
			if(value>0){
				convert_ones();
				cout << "Hundred ";
				next_step();
			}
		}
		if(input > 9999){
			divisor_10 = 10000;
			value = input / divisor_10;
			if(value>0){
				convert_tens();
				next_step();
			}
		}
		if(input > 999){
			divisor_10 = 1000;
			value = input / divisor_10;
			if(value > 0){
				convert_ones();
				next_step();
			}
		}
		cout << "Thousand ";
	}
	if(input > 0){
		if(input > 99){
			divisor_10 = 100;
			value = input / divisor_10;
			if(value>0){
				convert_ones();
				cout << "Hundred ";
				next_step();
			}
		}
		if(input > 9){
			divisor_10 = 10;
			value = input / divisor_10;
			if(value>0){
				convert_tens();
				next_step();
			}
		}
		if(input > 0){
			divisor_10 = 1;
			value = input / divisor_10;
			if(value > 0){
				convert_ones();
				next_step();
			}
		}
	}
};
void convert_tens(){
	if (value == 1){
		convert_teens();
	}
	if (value == 2)
		cout << "Twenty ";
	if (value == 3)
		cout << "Thirty ";
	if (value == 4)
		cout << "Fourty ";
	if (value == 5)
		cout << "Fifty ";
	if (value == 6)
		cout << "Sixty ";
	if (value == 7)
		cout << "Seventy "; 
	if (value == 8)
		cout << "Eighty ";
	if (value == 9)
		cout << "Ninety";
}
void convert_teens(){
	value = input - 10;
	if (value == 1)
		cout << "Eleven ";
	if (value == 2)
		cout << "Twelve ";
	if (value == 3)
		cout << "Thirteen ";
	if (value == 4)
		cout << "Fourteen ";
	if (value == 5)
		cout << "Fifteen ";
	if (value == 6)
		cout << "Sixteen ";
	if (value == 7)
		cout << "Seventeen "; 
	if (value == 8)
		cout << "Eightteen ";
	if (value == 9)
		cout << "Nineteen ";
	value = 0;
}
void convert_ones(){
	if (value == 1)
		cout << "One ";
	if (value == 2)
		cout << "Two ";
	if (value == 3)
		cout << "Three ";
	if (value == 4)
		cout << "Four ";
	if (value == 5)
		cout << "Five ";
	if (value == 6)
		cout << "Six ";
	if (value == 7)
		cout << "Seven "; 
	if (value == 8)
		cout << "Eight ";
	if (value == 9)
		cout << "Nine";
}