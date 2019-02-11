// Author:     Teresa L. Hitt
// Assignment: Program Example from chapters 6 & 7
// File:       Invoice.cpp
// Purpose:    This program reads merchandise values from a file. For each 
//             merchandise value it computes the tax, shipping and total due 
//             for the customer's invoice.
//             Tax is 4% of merchandise value.
//             Shipping is calculated as follows based on merchandise value:
//                Minimum shipping charge is $2.00
//                The shipping is 10% on the first $50.00 and 5% on any amount
//                over $50.00.
// Input:      Name of file to be processed.  Accounts.txt
#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()
using namespace std;

ofstream     outputfile("output.txt");     // Output file

const int    MAX_FILE_NAME = 35;            // Max space allocated for file name
const double TAX_RATE = 0.04;               // State tax rate
const double SHIPPING_MIN = 2.00;           // Minimum shipping charge
const double SHIPPING_RATE1 = 0.10;         // Rate on first $50
const double SHIPPING_RATE2 = 0.05;         // Rate on amount over $50
const double SHIPPING_MIN_AMOUNT = 20.00;   // Maximum amount that has min shipping
const double SHIPPING_RATE1_AMOUNT = 50.00; // Maximum amount that has rate 1

class Invoice
{  public:
	   Invoice();                            // Default constructor, initialize to zero              
      Invoice(double v);                    // Initialize with merchandise value
      void set_values(double v);            // v - merchandise, set invoice values
      void output(ostream &out);            // Print values on output stream out

   private:
	   void   calc_total();                  // Calculate tax, shipping, total value
      double merchandise;                   // Merchandise on invoice
      double tax;                           // Tax on merchandise
      double shipping;                      // Shipping charge on merchandise
      double total_due;                     // Total due on invoice
};

// Utility Functions
void open_input(ifstream& input, char name[]); // Get file name & Open file
void process_file(ifstream& input);            // Read each value & process it

int main() 
// Parameters: None
// Returns:    Zero
// Calls:      open_input(), process_file()    
{  char again;             // Does user want to go through loop again?
   char file_name[MAX_FILE_NAME + 1]; // Name of file to be processed
   ifstream input_numbers;            // For working with input file

   cout << "This program can calculate the values needed for\n"
        << "customer invoices.\n" << endl;
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
   outputfile << "\n\nThanks for using Invoice!\f"; 
   outputfile.close();
   
   return 0; 
}  // End of main()



void open_input(ifstream& input, char name[]) //Open file, exit on error
// Parameters: Variables for input file reference nad input file name
// Returns:    None
// Calls:      None
{  int count = 0;             // Count number of tries
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

void process_file(ifstream& input) 
// Parameters: Variable for file reference
// Returns:    None
// Calls:      Invoice::set_merchandise_value(), Invoice::output()
{  double value;              // Merchandise value from file
   Invoice sale;              // Invoice for a sale
   while (input >> value)     // Continue as long as we can read a number from file.
   {  sale.set_values(value); // Set Invoice Values
      sale.output(cout);      // Send output to screen
      sale.output(outputfile);   // Send output to outputfile
   }
} // End of process_file()

// Invoice Class Functions
Invoice::Invoice()
// Parameters: None
// Calls:      None
{  merchandise = tax = shipping = total_due = 0.0; // Initialize all values to zero
} // End Invoice::Invoice()

Invoice::Invoice(double v)
// Parameters: Merchandise value
// Calls:      Invoice::calc_total()
{  merchandise = v;
   calc_total();
} // End Invoice::Invoice(double)

void Invoice::set_values(double v)
// Parameters: Merchandise value
// Returns:    None
// Calls:      Invoice::calc_total()
{  merchandise = v;
   calc_total();
} // End Invoice::set_merchandise_total()

void Invoice::calc_total()
// Parameters: None
// Returns:    None
// Calls:      None
{  tax = TAX_RATE * merchandise;             // Calculate tax
   if ( merchandise <= SHIPPING_MIN_AMOUNT)  // Calculate shipping
      shipping = SHIPPING_MIN;
   else if ( merchandise <= SHIPPING_RATE1_AMOUNT)
      shipping = merchandise * SHIPPING_RATE1;
   else
      shipping = SHIPPING_RATE1_AMOUNT * SHIPPING_RATE1 + 
                 (merchandise - SHIPPING_RATE1_AMOUNT) * SHIPPING_RATE2;
   total_due = merchandise + tax + shipping; // Calculate invoice total
} // End Invoice::calc_total()

void Invoice::output(ostream &out)
// Parameters: Referrence to output stream where output is to be sent
// Returns:    None
// Calls:      None
{  out.setf(ios::fixed);      out.setf(ios::showpoint);     out.precision(2);
   out << "\n\nMerchadise : $" << setw(8) << merchandise << endl;
   out <<     "Tax        : $" << setw(8) << tax << endl;
   out <<     "Shipping   : $" << setw(8) << shipping << endl;
   out <<     "Total due  : $" << setw(8) << total_due << endl;
} // End Invoice::output()