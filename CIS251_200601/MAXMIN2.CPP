// Author:     Teresa L. Hitt
// Assignment: Program Example from chapter 9, #1 page 284 Altered to use an array
//             and type double
// File:       MaxMin2.cpp
// Purpose:    Searches a file of numbers of type double and writes the numbers along with
//             the largest and smallest numbers to the screen and outputfile. Allows the user 
//             to repeat action with other files.
// Input:      Name of file(s) to be processed. maxmin1.txt maxmin2.txt

#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()
using namespace std;

ofstream outputfile("output.txt");
const int MAX_FILE_NAME     = 35;  // Maximum file name length
const int MAX_NUMBER_SCORES = 40;  // Maximum number of values in array
void open_input(ifstream& input, char name[]);                       // Get file name, Open file
void read_values(ifstream& input, double v[], int size, int& used);  // Read values from file
void find_max_min(const double v[], int n, double& max, double& min);// Find max/min in array
void output(const char name[], const double v[], int n, 
			double max, double min, ostream &out = cout);            // Print Results

int main() 
// Parameters: None
// Returns:    Zero
// Calls:      open_input(), read_values(), find_max_min(), output()     
{  char     again;                        // Does user want to go through loop again?
   char     file_name[MAX_FILE_NAME + 1]; // Name of file to be processed
   ifstream input_numbers;                // Input file of doubles
   double   scores[MAX_NUMBER_SCORES];    // Array to hold scores processed
   double   max, min;                     // Maximum and minimum numbers from file
   int      num_scores;                   // Number of scores in file

   cout << "This program can find the largest and smallest numbers in a file\n"
        << "of at most " << MAX_NUMBER_SCORES << " floating-point values.\n" << endl;
   system("pause"); // Hold message on screen until key is pressed

   do 
   {  open_input(input_numbers, file_name);    // Get file name & open file
      read_values(input_numbers, scores, 
         MAX_NUMBER_SCORES, num_scores);       // Read values
      input_numbers.close();                   // Close file
      if (num_scores > 0)
      {  find_max_min(scores, num_scores, max, min); // Find max & min values in array
         output(file_name, scores, num_scores, max, min); // Print results on screen
         output(file_name, scores, num_scores, max, min, outputfile); // and outputfile
      }
      else
      {  cout << "\n\n\aNo data in file: " << file_name << endl;
      }

      cout << "\nDo you want to process another file (Y/N)? ";
      cin >> again;
      cin.ignore(256, '\n');  // Remove Enter key from keyboard buffer
   } while ( again == 'y' || again == 'Y'); 

   cout << "\nEnd of Program!" << endl;
   outputfile << "\n\nThanks for using MaxMin!\f"; 
   outputfile.close();
   return 0; 
}  // End of main()

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
      input.open(name, ios_base::in); // Open to read only if file exists
   } while (input.fail() );            // If can't open file, try again
} // End of open_input()

void read_values(ifstream& input, double v[], int size, int& used) // Read values
// Parameters: Variables for file reference, variable for array reference,
//             value for array size and variable for number of values in array
// Returns:    None
// Calls:      None
{  
   double value;        // Value from file
   int count = 0;       // Count number of values in file

   while (count < size && input >> value) // Continue as long as there is 
                                          // room in the array and we can read
   {  v[count] = value;                   // a number from file.
      count ++; 
   }

   used = count;
} // End of read_values()

void find_max_min(const double v[], int n, double& max, double& min) // Find max & min values
// Parameters: Variables for array reference, value for number of values 
//             and variables for max and min values
// Returns:    None
// Calls:      None
{  
   int i;   // Array index and loop counter
   
   max = min = v[0];
   
   for (i = 1; i < n; i++) // Start with 1 since max & min initialized to v[0]
   {  
      if (v[i] > max) max = v[i];
      if (v[i] < min) min = v[i];
   }
} // End of find_max_min()

void output(const char name[], const double v[], int n, 
			double max, double min, ostream& out) 
// Parameters: File name, array reference, number of values and max & min values
// Returns:    None
// Calls:      None
{  int i;  // Array index and loop counter
   out.setf(ios::fixed);
   out.setf(ios::showpoint);
   out.precision(1);
   out << "\n\nInput File Name:         " << name << endl;
   out << "\nFile Contents:" << endl;
   for (i = 0; i < n; )
   {  out << setw(8) << v[i];
      if ( ++i % 5 == 0) out << "\n"; // Print only 5 values per line
   }
   if ( i % 5 != 0) out << "\n";      // Newline if last line is short
   out << "\nLargest  Number in File:        " << setw(8) << max << endl;
   out <<   "Smallest Number in File:        " << setw(8) << min << endl;
} // End of output()
