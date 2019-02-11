/*	AUTHOR: Kenneth Robinson
	ASSIGNMENT: 6 
	CIS 215
	DATE: March 27, 2006
	PURPOSE: Get account balances from a file and calculate total interest, minimum payment and total amount due.	
*/

#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()
using namespace std;

ofstream     outputfile("output.txt");     // Output file

const int    MAX_FILE_NAME = 35;            // Max space allocated for file name
const double TAX_RATE = 0.04;               // State tax rate
const double SHIPPING_MIN = 2.00;           // Minimum shipping charge
const double INTEREST_RATE1 = 0.01;         // Rate on first $1000
const double INTEREST_RATE2 = 0.015;        // Rate on amount over $1000
const double MIN_PAYMENT = 10.00;			// Maximum amount that has min shipping
const double SHIPPING_RATE1_AMOUNT = 50.00; // Maximum amount that has rate 1

class Account{
public:
	Account(double Balance, double InterestRate1, double InterestRate2);
	Account();
	double Payment();
	double InterestDue();
	double TotalAmountDue();
private:
	double balance;
	double interest_rate1;
	double interest_rate2;
	double total_amount_due;
};

// Utility Functions
void open_input(ifstream& input, char name[]); // Get file name & Open file
void process_file(ifstream& input);            // Read each value & process it
void set_values(double v);						//sets values
void output(ostream &out);            // Print values on output stream out

//variables
Account bal;						//calls Account class

int main(){
// Parameters: None
// Returns:    Zero
// Calls:      open_input(), process_file()    
   char again;             // Does user want to go through loop again?
   char file_name[MAX_FILE_NAME + 1]; // Name of file to be processed
   ifstream input_numbers;            // For working with input file

   cout << "This program can calculate the values needed for\n"
	   << "customer Accounts.\n" << endl;
   system("pause"); // Hold message on screen until key is pressed

   do 
   {  
	 system("cls");                           // Clear screen
	 open_input(input_numbers, file_name);    // Get file name & open file
	 process_file(input_numbers);             // Process values in file
	 input_numbers.close();                   // Close file

	 cout << "\nDo you want to process another file (Y/N)? ";
	 cin >> again;
	 cin.ignore(256, '\n');  // Remove Enter key from keyboard buffer
   
   } while ( again == 'y' || again == 'Y'); 

   cout << "\nEnd of Program!" << endl;
   outputfile << "\n\nThanks for using Account!\f"; 
   outputfile.close();
   
   system("pause");
   return 0; 
}  // End of main()

void open_input(ifstream& input, char name[]){ //Open file, exit on error
// Parameters: Variables for input file reference nad input file name
// Returns:    None
// Calls:      None
   int count = 0;             // Count number of tries
   do // Continue until we get a valid file name and can open file
   {  count++;
     if (count != 1)  // Issue error message if we are trying again.
      {  cout << "\n\aInvalid file name or file does not exist. Please try again." 
              << endl;
      }
      cout << "\nEnter the input file name (maximum of " << MAX_FILE_NAME
           << " characters please)\n:> ";
      cin.get(name, MAX_FILE_NAME + 1);// Gets at most MAX_FILE_NAME characters
      cin.ignore(256, '\n');           // Remove Enter key from keyboard buffer
      input.clear();                   // Clear all error flags, if any, from prev try
      input.open(name,ios_base::in); // Open only if file exists
   } while (input.fail() );            // If can't open file, try again
} // End of open_input()

void process_file(ifstream& input){ 
// Parameters: Variable for file reference
// Returns:    None
// Calls:      Account::set_merchandise_value(), Account::output()
	double value;              // Merchandise value from file

   while (input >> value){     // Continue as long as we can read a number from file.
	
	   cout << "Original Balance: $" << value << endl;
	   
	 bal =Account(value, INTEREST_RATE1, INTEREST_RATE2);
      output(cout);      // Send output to screen
      output(outputfile);   // Send output to outputfile
   }
} // End of process_file()


// Account Class Functions
Account::Account(){				//default constructor
// Parameters: None
// Calls:      None
	balance = total_amount_due = 0.0; // Initialize all values to zero
	interest_rate1 = INTEREST_RATE1;
	interest_rate2 = INTEREST_RATE2;
} // End Account::Account()

Account::Account(double value, double InterestRate1, double InterestRate2){
// Parameters: Merchandise value
// Calls:      Account::Payment(), Account::Interest(), Account::TotalAmountDue()

  interest_rate1 = INTEREST_RATE1;
  interest_rate2 = INTEREST_RATE2;
  balance = value;
  InterestDue();
  Payment();
  TotalAmountDue();  
} // End Account::Account(double Balance, double InterestRate1, double InterestRate2))

double Account::InterestDue(){
	double interest;

	if (balance > 1000){
	    return interest = ((balance - 1000) * interest_rate1) + (1000 * interest_rate2);
	}
	else{
		return interest = balance * interest_rate2;
	}
}

double Account::Payment(){
// Parameters: None
// Returns:    minimum payment
// Calls:      None
	double minimum_payment;

		if (balance < 10){
		    return minimum_payment = balance;  // Rule 1
		}
		else{  // new balance > 10
		return minimum_payment = balance * .10;  // Rule 3
			if (minimum_payment < 10){
				return minimum_payment = MIN_PAYMENT;       // Rule 2
			}
		}
} // End Account::Payment()

double Account::TotalAmountDue(){
	return balance = balance + InterestDue();
}

void output(ostream &out){
// Parameters: Referrence to output stream where output is to be sent
// Returns:    
// Calls:      None

  out.setf(ios::fixed);      out.setf(ios::showpoint);     out.precision(2);
//   out << "Account Balance : $" << setw(8) << value << endl;
   out << "Interest: $" << setw(2) << bal.InterestDue() << endl;
   out << "Minimum Payment: $" << setw(2) << bal.Payment() << endl;
   out << "Total due: $" << setw(2) << bal.TotalAmountDue() << endl;
   out << "\n";
} // End Account::output()
