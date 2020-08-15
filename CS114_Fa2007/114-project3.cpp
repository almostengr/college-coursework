#include <iostream>											
using namespace std;										
															
															
															
//functions for conversions
int if_negative();
int negative_to_positive;
int number_to_text();
int ones_to_text();
int tens_to_text();
int teens_2_text();

//variables for conversions
int number_entered, 10_remainder, 10_divider;


int main( ){ 

	cout << "Enter an integer (or zero to exit): ";
	cin >> number_entered;

	while(number_entered != 0){	//contines loop while 0 is not enter
		if_negative();
		number_to_text();

		cout << endl << endl;

		cout << "Enter an integer (or zero to exit): ";
		cin >> number_entered;
	};

	system("pause");

	return 0;
};


int if_negative(){	//checks to see if number is negative

	if(number_entered < 0){
		cout << "negative ";
		negative_to_positive;
	}

	return 0;
};


int negative_to_positive{	//changes the number to positive it 

	number_entered = number_entered - number_entered - number_entered;

	return 0;
};


int next_step(){

	10_remainder = 10_remainder * 10_divider;
	number_entered = number_entered - 10_remainder;

	return 0;
};


int number_to_text(){	//converts the number to English text

	if (number_entered> 999999999){
		10_divider = 1000000000;
		10_remainder = number_entered / 10_divider;
		ones_to_text();
		cout << "billion ";
		next_step();
	}
	if(number_entered > 999999){
		if(number_entered > 99999999){
			10_divider = 100000000;
			10_remainder = number_entered / 10_divider;
			if(10_remainder>0){
				ones_to_text();
				cout << "hundred ";
				next_step();
			}
			if(number_entered > 9999999){
				10_divider = 10000000;
				10_remainder = number_entered / 10_divider;
				if(10_remainder>0){
					tens_to_text();
					next_step();
				}
			}
			if(number_entered > 999999){
				10_divider = 1000000;
				10_remainder = number_entered / 10_divider;
				if(10_remainder > 0){
					ones_to_text();
					next_step();
				}
			}
		}
		cout << "million ";
	}
	if(number_entered > 999){
		if(number_entered > 99999){
			10_divider = 100000;
			10_remainder = number_entered / 10_divider;
			if(10_remainder>0){
				ones_to_text();
				cout << "hundred ";
				next_step();
			}
		}
		if(number_entered > 9999){
			10_divider = 10000;
			10_remainder = number_entered / 10_divider;
			if(10_remainder>0){
				tens_to_text();
				next_step();
			}
		}
		if(number_entered > 999){
			10_divider = 1000;
			10_remainder = number_entered / 10_divider;
			if(10_remainder > 0){
				ones_to_text();
				next_step();
			}
		}
		cout << "thousand ";
	}
	if(number_entered > 0){
		if(number_entered > 99){
			10_divider = 100;
			10_remainder = number_entered / 10_divider;
			if(10_remainder>0){
				ones_to_text();
				cout << "hundred ";
				next_step();
			}
		}
		if(number_entered > 9){
			10_divider = 10;
			10_remainder = number_entered / 10_divider;
			if(10_remainder>0){
				tens_to_text();
				next_step();
			}
		}
		if(number_entered > 0){
			10_divider = 1;
			10_remainder = number_entered / 10_divider;
			if(10_remainder > 0){
				ones_to_text();
				next_step();
			}
		}
	}

	return 0;
};


int tens_to_text(){	//writes number out for tens place 

	if (10_remainder == 1){
		teens_2_text();
	}
	if (10_remainder == 2)
		cout << "twenty ";
	if (10_remainder == 3)
		cout << "thirty ";
	if (10_remainder == 4)
		cout << "fourty ";
	if (10_remainder == 5)
		cout << "fifty ";
	if (10_remainder == 6)
		cout << "sixty ";
	if (10_remainder == 7)
		cout << "seventy "; 
	if (10_remainder == 8)
		cout << "eighty ";
	if (10_remainder == 9)
		cout << "ninety ";

	return 0;
};


int teens_2_text(){	//writes numbers from 10 to 19
	10_remainder = number_entered - 10;

	if (10_remainder == 1)
		cout << "eleven ";
	if (10_remainder == 2)
		cout << "twelve ";
	if (10_remainder == 3)
		cout << "thirteen ";
	if (10_remainder == 4)
		cout << "fourteen ";
	if (10_remainder == 5)
		cout << "fifteen ";
	if (10_remainder == 6)
		cout << "sixteen ";
	if (10_remainder == 7)
		cout << "seventeen "; 
	if (10_remainder == 8)
		cout << "eightteen ";
	if (10_remainder == 9)
		cout << "nineteen ";

	10_remainder = 0;

	return 0;
};

int ones_to_text(){ //writes out ones and hundreds place 

	if (10_remainder == 1)
		cout << "one ";
	if (10_remainder == 2)
		cout << "two ";
	if (10_remainder == 3)
		cout << "three ";
	if (10_remainder == 4)
		cout << "four ";
	if (10_remainder == 5)
		cout << "five ";
	if (10_remainder == 6)
		cout << "six ";
	if (10_remainder == 7)
		cout << "seven "; 
	if (10_remainder == 8)
		cout << "eight ";
	if (10_remainder == 9)
		cout << "nine ";

	return 0;
};