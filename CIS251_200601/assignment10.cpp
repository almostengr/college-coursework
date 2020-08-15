/*		
		CIS 251
		April 25, 2006
		Assignment 10
*/

#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()

#include <string>         // For stricmp()
#include "sort.h"           // Generic sort() function
using namespace std;

const int MAX_FILE_NAME     =  35;  // Maximum file name length
const int MAX_ID_LEN        =  10;  // Maximum length for employee's id
const int MAX_NAME_LEN      =  20;  // Maximum length for employee's name
const int RATE_CHANGE_POINT = 500;  // Quantity sold value at which commision rate changes
const double RATE1 = 0.50;          // Regular commission per subscription sold 
const double RATE2 = 0.60;          // Premium commission per subscription sold

class SalesRecord;                  // Forward declaration needed to allow typedef
typedef SalesRecord * SalesRecord_List;// Used for pointer to head of list

class SalesRecord                      // Record definition for employee's sales record
{  private:
      char   emp_id[MAX_ID_LEN + 1];   // Employee's id
      char   emp_name[MAX_NAME_LEN +1];// Employee's name
      int    quantity_sold;            // Number of magazine subscriptions sold
      double commission_rate;          // Commission on each subscription
      double commission;               // Salesperson's commission
      SalesRecord * next;              // Pointer to next record in list.   
   public:
      // Functions that operate on an individual record
      SalesRecord();                   // Default constructor
      void read(ifstream& in);         // Read record from input stream
      void calc_commission();          // Calculate commission fields in record
      void write(ostream & os) const;  // Write record to output stream
      void report(ostream& os) const;  // Write record report line to output stream
      bool operator<(const SalesRecord& right) const;// Overloaded for use in sort
      // Funcions that operate on list (set) of records need access to data in records
      friend void read_records(ifstream& in, SalesRecord_List& records);      
      friend void append(SalesRecord_List& records, SalesRecord& rec);        
      friend void calc_records(SalesRecord_List records);                 
      friend void report(SalesRecord_List records);                            
      friend void find_max_min_sales(SalesRecord_List records, int &max, int &min);
      friend void delete_records(SalesRecord_List& records);                   
};

// Utility functions - functions are not specific to this problem
void open_input(ifstream& input, char name[]);           // Get file name & Open file
void open_output(ofstream& output, char name[]);         // Get file name & Open file

int  main()
// Parameters: None
// Returns:    Zero
// Calls:      open_input(), read_records(), calc_commissions(), sort(), write_records().
{  char again;                                  // Does user want to go through loop again?
   char infilename[MAX_FILE_NAME + 1];          // Name of file for records to be processed
   ifstream  in;                                // Input file stream
   SalesRecord_List records = NULL;             // Pointer to head of list of sales records

   do 
   {  open_input(in, infilename);               // Get file name & open file
   cout << infilename; 
   read_records(in, records);                // Read records & get number of records
      in.close();                               // Close file
      if (records != NULL)
      {  calc_records(records);                 // Calculate commission values for each record
         report(records);                       // Produce sales report
         delete_records(records);               // Free array of records  
      }
      else
      {  cout << "\n\n\aNo data in file: " << infilename << endl;
      }
      cout << "\nDo you want to process another file (Y/N)? ";
      cin >> again;
      cin.ignore(256, '\n');  // Remove Enter key from keyboard buffer
   } while ( again == 'y' || again == 'Y'); 
   cout <<  "\n\n***** END OF PROGRAM ******\n";// Print closing message.    
   return 0;
}  // End of main()                



// Funcions that operate on list (set) of records
void read_records(ifstream& in, SalesRecord_List& records) // Allocate space for records & read them
// Parameters: Input stream, List of records.      
// Returns   : Pointer to list of records allocated.                                                        
// Calls     : read(), append().                                                        
{  SalesRecord      temp;           // Temporary record in which to read data
   records = NULL;                  // Initialize to NULL incase no records
                                    // Peek ahead to see if there is anything in file
   while (in.good() && !in.eof() && in.peek() != -1)    
   {  temp.read(in);               // Read next record
      append(records, temp);        // Add record to end of list
   }
} // End of read_records()

void append(SalesRecord_List& records, SalesRecord& rec) // Add record to end of list
// Parameters: List of records, record holding values of record to be added
// Returns   : None.                                                        
// Calls     : None.
{  SalesRecord *    new_record = NULL; // Pointer to new record to be added
   SalesRecord *    last       = NULL; // Pointer to last record in list

   new_record = new SalesRecord;       // Allocate space for new record
   if (new_record == NULL)
   {   cout << "\aCan not allocate memory!";
       exit(1);
   }
   
   *new_record = rec;                  // Set values in allocated record
   new_record->next = NULL;            // Set next field to NULL
   
   if (records == NULL)                // If list is empty, add as 1st record
   {   records = new_record;
   }
   else                                // Otherwise find end of list and add record there
   {   last = records;                 // Find last record in list
       while ( last->next != NULL)     // Last record's next field would be NULL
       {   last = last->next;          // Move to next record,until reach last one
       }
                                       // Set next field of last record to  
       last->next = new_record;        // point to new_record.
   }
} // End of append()

void calc_records(SalesRecord_List records) // Calculate commission rate and commission
// Parameters: List of records      
// Returns   : None.                                                        
// Calls     : SalesRecord::calc_commission().                                                        
{  SalesRecord *    current = NULL;    // Pointer to current record in list
   
   current = records;                  // Start at beginning of list
   while (current != NULL)             // While there is a record to process
   {   current->calc_commission();     // Calculate commission info for this record
       current = current->next;        // Move to next record
   }

} // End of calc_records()

void find_max_min_sales(SalesRecord_List records, int& max, int& min) // Find max & min values
// Parameters: List of records and variables for max and min values
// Returns:    None
// Calls:      None
{  if (records == NULL)
   {  max = min = 0;                   // No records to check, set max & min to zero
   }
   else
   {  SalesRecord *  current  = NULL;  // Pointer to current record in list
   
      current = records;               // Start at beginning of list
      max = min = current->quantity_sold; // Initialize to value in 1st record
      current = current->next;         // Move to next record
      while (current != NULL)          // While there is a record left to process
      {  if (current->quantity_sold > max) max = current->quantity_sold;
         if (current->quantity_sold < min) min = current->quantity_sold;
         current = current->next;      // Move to next record
      }
   }
} // End of find_max_min_sales()

void report(SalesRecord_List records)  // Produce report
// Parameters: List of records      
// Returns   : None.                                                        
// Calls     : report(SalesRecord&), find_max_min_sales().
{  if (records == NULL)  // Nothing to report
   {  return;   }
   
   char      outfilename[MAX_FILE_NAME + 1];   // Name of file for report
   ofstream  out;                              // Output file stream

   cout << "\n\nI need the report file name." << endl;
   open_output(out, outfilename);
   
   if (out.good())
   {  out << "\n" << setw(50) << "Magazine Sales Report\n" << endl;
      out << setw(3) << " ";
      out.setf(ios::left); // Left justification for string fields
      out << setw(21) << "Employee";
      out << setw(11) << "ID";
      out << setw(5)  << " " << "# Sold";
      out << setw(5)  << " " << "Rate"; 
      out << setw(5)  << " " << "Commission\n" << endl;
      
      SalesRecord *    current = NULL;   // Pointer to current record in list
      current = records;                 // Start at beginning of list
      while (current != NULL)            // While there is a record to process
      {   current->report(out);          // Write line for record
          current = current->next;       // Move to next record
      }
   
      int max, min;
      find_max_min_sales(records, max, min);
      out << "\n\n   Minimum quantity sold = " << setw(6) << min << endl;
      out << "   Maximum quantity sold = " << setw(6) << max << endl;
      out << "\n\n   End of Report" << endl;
      out.close();
   }  
   else
   {  cout << "\a\nUnable to write report!" << endl;
   }
} // End of report()

void delete_records(SalesRecord_List& records) // Free all records in list
// Parameters: List of records      
// Returns   : None.                                                        
// Calls     : None.                                                        
{  SalesRecord *  current  = NULL;  // Pointer to current record in list
   SalesRecord *  deadmeat = NULL;  // Pointer to record to be deleted
   
   current = records;               // Start at beginning of list
   while (current != NULL)          // While there is a record left
   {   deadmeat = current;          // Set to record to be deleted
       current = current->next;     // Move to next record
       delete deadmeat;             // Delete previous record
   }

   records = NULL;                  // records is now an empty list
} // End of delete_records()

// Functions that operate on individual records
SalesRecord::SalesRecord()               
{  emp_id[0] = emp_name[0] ='\0';         // Set strings to null
   quantity_sold = 0;                     // Set numeric data to zero
   commission_rate = commission = 0.0; 
   next = NULL;                           // Set pointer to NULL
} // End of SalesRecord::SalesRecord()

void SalesRecord::report(ostream& os) const // Write record report line to output stream
// Parameters: Output stream, record to be printed      
// Returns   : None.                                                        
// Calls     : None.                                                        
{  os << setw(3) << " ";  // Skip 3 spaces
   os.setf(ios::left);    // Left justification for string fields
   os << setw(21) << emp_name << setw(11) << emp_id;
   
   os.setf(ios::right, ios::adjustfield); // Right justification for numeric values
   os.setf(ios::fixed);   os.setf(ios::showpoint);   os.precision(2);
   
   os << setw(10) << quantity_sold << setw(10) << commission_rate 
      << setw(13) << commission << endl;
} // End of SalesRecord::report()              

void SalesRecord::read(ifstream& in)     // Read record from input stream, does not read commission values
// Parameters: Input stream
// Returns:    none
// Calls:      None
{  in.get(emp_id, MAX_ID_LEN +1);         // Read id
   while (in.get() != '\n');              // Clear Enter after id
   in.get(emp_name, MAX_NAME_LEN +1);     // Read name: Last, First
   while (in.get() != '\n');              // Clear Enter after name
   in >> quantity_sold;                   // Read quantity sold value
   while (in.get() != '\n');              // Clear Enter at end of record
} // End of SalesRecord::read()

void SalesRecord::calc_commission()       // Calculate commission fields in record
// Parameters: None
// Returns:    None
// Calls:      None
{  if (quantity_sold < RATE_CHANGE_POINT) commission_rate = RATE1;
   else                                   commission_rate = RATE2;
   commission = commission_rate * quantity_sold;
} // End of SalesRecord::calc_commission()

void SalesRecord::write(ostream & os) const// Write record to output stream
// Parameters: Output stream, record to be written      
// Returns   : None.                                                        
// Calls     : None.                                                        
{  os.setf(ios::fixed);   os.setf(ios::showpoint);   os.precision(2);
   
   os << emp_id << "\n" << emp_name << "\n"
       << quantity_sold << " " << commission_rate << " "
       << commission << endl;
} // End of SalesRecord::write()              

bool SalesRecord::operator<(const SalesRecord& right) const// Overloaded for use in sort
// Parameters: Record to be compared
// Returns:    true if emp_name in first record < emp_name in second record, false otherwise
// Calls:      None
{  if (stricmp(emp_name, right.emp_name) < 0)  return true;
   else                                        return false;
} // End of SalesRecord::operator<

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



