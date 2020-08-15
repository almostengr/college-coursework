/*	
	CIS 251
	Assignemnt 9
	April 25, 2006
*/

#include <iostream>
#include <fstream>        // For I/O   
#include <iomanip>        // For setw()
#include <cstdlib>         // For system()
#include <string>         // For stricmp()
#include "sort.h"           // Generic sort() function
using namespace std;

const int MAX_FILE_NAME     =  35;  // Maximum file name length
const int MAX_ID_LEN        =  10;  // Maximum length for employee's id
const int MAX_NAME_LEN      =  20;  // Maximum length for employee's name
const int RATE_CHANGE_POINT = 11;  // Quantity sold value at which commision rate changes
const double RATE1 = 0.10;          // Regular commission per subscription sold 
//const double RATE2 = 0.60;          // Premium commission per subscription sold

class SalesRecord                      // Record definition for employee's sales record
{  private:
      char   emp_id[MAX_ID_LEN + 1];   // Employee's id
      char   emp_name[MAX_NAME_LEN +1];// Employee's name
      int    quantity_sold;            // Number of magazine subscriptions sold
	  double price_paid;				//price for each item
	  double price;
	  double purchase_total;			//amount paid
	  double discount;					//discount amount, if any
   public:
      // Functions that operate on an individual record
	  SalesRecord();                   // Default constructor
      void read(ifstream& in);         // Read record from input stream
      void calc_commission();          // Calculate commission fields in record
      void write(ostream & os) const;  // Write record to output stream
      bool operator<(const SalesRecord& right) const;// Overloaded for use in sort
};
typedef SalesRecord * SalesRecord_Array; // Used to allocate 1-D sales record array

struct recordnode
  {  char emp_id[20];    // employee's id 20 letters
     char emp_name;          // employee's name
     int quantity_sold;     // quantity sold of item
	 double price;			//price of item
     recordnode* nxt;        // Pointer to next node
  };
typedef recordnode* SalesRecordPtr;
SalesRecordPtr record;

// Utility functions - functions are not specific to this problem
void open_input(ifstream& input, char name[]);           // Get file name & Open file
void open_output(ofstream& output, char name[]);         // Get file name & Open file

// Funcions that operate on array (set) of records
SalesRecord_Array read_records(ifstream& in, int &n);    // Allocate space for records & read them
void calc_records(SalesRecord_Array records, int n);     // Calculate commission rate and commission
void write_records(SalesRecord_Array records, int n);    // Save records to file

int  main()
// Parameters: None
// Returns:    Zero
// Calls:      open_input(), read_records(), calc_commissions(), sort(), write_records().
{  char again;                                  // Does user want to go through loop again?
   int  num_records;                            // # of records 
   char infilename[MAX_FILE_NAME + 1];          // Name of file for records to be processed
   ifstream  in;                                // Input file stream
   SalesRecord_Array records = NULL;            // Pointer to array of sales records


   do 
   {  open_input(in, infilename);               // Get file name & open file
      records = read_records(in, num_records);  // Read records & get number of records
      in.close();                               // Close file
      if (records != NULL && num_records > 0)
      {  calc_records(records, num_records);    // Calculate commission values for each record
         sort(records, num_records);            // Sort records by employee name
         write_records(records, num_records);   // Save records to new file
         delete [] records;                     // Free array of records  
      }
      else
      {  cout << "\n\n\aNo data in file: " << infilename << endl;
      }
      
      cout << "\nDo you want to process another file (Y/N)? ";
      cin >> again;
      cin.ignore(256, '\n');  // Remove Enter key from keyboard buffer
   } while ( again == 'y' || again == 'Y'); 

   cout <<  "\n\n***** END OF PROGRAM ******\n";// Print closing message.    
   system("pause");
   return 0;
}  // End of main()                

// Utility functions
void open_input(ifstream& input, char name[]) //Open file
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
      input.open(name, ios_base::in); // Open only if file exists
   } while (input.fail() );            // If can't open file, try again
} // End of open_input()

void open_output(ofstream& output, char name[]) //Open file
// Parameters: Variables for output file reference and output file name
// Returns:    None
// Calls:      None
{  int count = 0;             // Count number of tries
   do // Continue until we get a valid file name and can open file
   {  count++;
      if (count != 1)  // Issue error message if we are trying again.
      {  cout << "\n\aInvalid file name. Please try again." 
              << endl;
      }
      
	  cout << "\nEnter the output file name (maximum of " << MAX_FILE_NAME
           << " characters please)\n:> ";
      cin.get(name, MAX_FILE_NAME + 1);// Gets at most MAX_FILE_NAME characters
      cin.ignore(256, '\n');           // Remove Enter key from keyboard buffer
      output.clear();                  // Clear all error flags, if any, from prev try
      output.open(name);               // Open file for output
   } while (output.fail() );           // If can't open file, try again
} // End of open_output()

// Functions that operate on individual records
SalesRecord::SalesRecord()     // Initialize data
// Parameters: None
// Returns:    none
// Calls:      None
{  emp_id[0] = emp_name[0] ='\0';         // Set strings to null
   
   quantity_sold = 0;                     // Set numeric data to zero
	discount = 0.0; 
} // End of SalesRecord::SalesRecord()

void SalesRecord::read(ifstream& in)      // Read record from input stream, does not read commission values
// Parameters: Input stream
// Returns:    none
// Calls:      None
{ /* in.get(emp_id, MAX_ID_LEN +1);         // Read id
   while (in.get() != '\n');              // Clear Enter after id

   in.get(emp_name, MAX_NAME_LEN +1);     // Read name: Last, First
   while (in.get() != '\n');              // Clear Enter after name

   in >> quantity_sold;                   // Read quantity sold value
   in >> price;							//Read price of item
   while (in.get() != '\n');              // Clear Enter at end of record
   */
record = new recordnode;

record->emp_id;
record->emp_name;
record->quantity_sold;
record->price;
record->nxt;



} // End of SalesRecord::read()

void SalesRecord::calc_commission()       // Calculate commission fields in record
// Parameters: None
// Returns:    None
// Calls:      None
{  if (quantity_sold < RATE_CHANGE_POINT){
		discount = RATE1 * price;
		price = price - discount;
		purchase_total = quantity_sold * price;
	}
   else
	purchase_total = quantity_sold * price;
   
} // End of SalesRecord::calc_commission()

void SalesRecord::write(ostream & os) const// Write record to output stream
// Parameters: Output stream, record to be written      
// Returns   : None.                                                        
// Calls     : None.                                                        
{  os.setf(ios::fixed);   os.setf(ios::showpoint);   os.precision(2);
   
   os << emp_id << "\n" << emp_name << "\n"
       << quantity_sold << " "// << commission_rate << " "
       << purchase_total << endl;
} // End of SalesRecord::write()              

bool SalesRecord::operator<(const SalesRecord& right) const// Overloaded for use in sort
// Parameters: Record to be compared - on right side of < operator
// Returns:    true if emp_name in first record < emp_name in second record, false otherwise
// Calls:      None
{  if (stricmp(emp_name, right.emp_name) < 0)
        return true;
   else 
        return false;
} // End of SalesRecord::operator<

// Funcions that operate on array (set) of records
SalesRecord_Array read_records(ifstream& in, int &n)      // Allocate space for records & read them
// Parameters: Input stream, variable for number of records.      
// Returns   : Pointer to array of records allocated.                                                        
// Calls     : SalesRecord::read().                                                        
{
   in >> n;                       // Read number of records
   if (n < 1 || in.fail()) 
      return NULL;               // No records to read return
   
   while (in.get() != '\n');     // Clear enter after number of records in file
   SalesRecord_Array records;    // Pointer for array of records

   records = new SalesRecord[n]; // allocate space for records 
   if (records == NULL)
   {   cout << "\aCan not allocate memory!";
       exit(1);
   }
   
   int i;
   for(i = 0; in.good() && !in.eof() && i < n; i++) 
   {  records[i].read(in);             // Read each record
   }

   return records;  // Return pointer to array 
} // End of read_records()

void calc_records(SalesRecord_Array records, int n) // Calculate commission rate and commission
// Parameters: Array of records, number of records.      
// Returns   : None.                                                        
// Calls     : SalesRecord::calc_commission().                                                        
{  int i;
   for(i = 0; i < n; i++) 
   {  records[i].calc_commission();    // Process each record
   }
} // End of calc_records()

void write_records(SalesRecord_Array records, int n)   // Save records to file
// Parameters: Array of records, number of records.      
// Returns   : None.                                                        
// Calls     : SalesRecord::write().                                                        
{  char      outfilename[MAX_FILE_NAME + 1];   // Name of file for output records
   ofstream  out;                              // Output file stream

   cout << "\n\nI need the output file name." << endl;
   open_output(out, outfilename);              // Get file name & open file

   if (out.good())
   {  out << n << endl;          // Write number of records to file
      int i;
      for(i = 0; i < n; i++) 
      {  records[i].write(out);  // Write each record to file
      }
      out.close();
   }
   else
   {  cout << "\a\nUnable to save data!" << endl;
   }
} // End of write_records()