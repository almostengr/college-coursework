/*
	Kenneth Robinson
	CIS 251
	March 14, 2006
	Assignment 6
*/
#include <iostream>		//basic input/output stream
#include <fstream>		//reading and writing to a file or files
using namespace std;

class BankAccount{
	public:
		account();		//default constructor, initalizes variables to default values
		account(double balance, double interest_rate1, double interest_rate2);	//
		double payment();		//function for calculating payment
		double interest_due();	//functino for calculating interest
		double total_due();	//function for calculating total
	private:
		double balance;	//account balance that is input from the file
		const double interest_rate1 = 0.015;		//initalizes interest rate of 1.5%
		const double interest_rate2 = 0.01;		//initalizes interest rate of 1%
		double total_due;	//amount due after adding interest
};

void main(){		//main function
	ifstream in_file;			//calls for getting input file
	char again;				//for repeating loop
	char file_name[];
	char file_name_length[21];			//name of the file
	BankAccount account;		//defines the BankAccount class
	
	do{
		cout << "Enter the file name with the accoounts (max. 20 characters):" << endl;
		cin >> file_name;
		cin.get(name, file_name_length);	// Gets file_name characters
		cin.ignore(256, '\n');           // Remove Enter key from keyboard buffer
			if (in_file.fail()){
				cout << "Error opening file!" << endl;
			}
		in_file.open(name, ios::nocreate); // Open only if file exists
					
		account.account;			//initializes variables ot default values
		account.account(balance, interest_rate1, interest_rate2);
		account.payment;
		account.interest_due;
		account.total_due;
		
		cout.setf(ios::fixed);		//for 2 decimal places
		cout.setf(ios::showpoint);	//for 2 decimal places
		cout.precision(2);			//for 2 decimal places
	
	in_file.close();     		//close file
	cout << "Would you like to do another file (y/n)? \n";		//ask to process another file
	cin >> again;
	}while(again=="y" || again=="Y")
	system("pause");
}

BankAccount::account(){
	balance = 0;			//initalizes balance
	total_due = 0;			//initializes total amount due
}

BankAccount::account(double balance, double interest_rate1, double interest_rate2){

}

BankAccount::payment(){
	if (new_balance < 10){
	    minimum_payment = new_balance
	    }
	else{  // new_balance > 10
	    minimum_payment = new_balance * 10%  // Rule 3
			if{ (minimum_payment < 10)
			minimum_payment = 10        // Rule 2
			}
		}
}

BankAccount::interest_due(){
	if (balance > 1000){
	    interest = ((balance-1000) * interest_rate2) + (1000 * interest_rate1)
	    }
	else{
	    interest = balance * interest_rate1
	    }
}

BankAccount::total_due(){
	new_balance = balance + interest 
}
