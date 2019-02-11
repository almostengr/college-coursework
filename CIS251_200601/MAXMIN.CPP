// Author:     Teresa L. Hitt
// Assignment: Program Example from chapter 5, #1 page 284
// File:       MaxMin.cpp
// Purpose:    Searches a file of numbers of type int and writes the largest and
//             smallest numbers to the screen. Allows the user to repeat action
//             with other files.
// Input:      Name of file to be processed. maxmin1.txt maxmin2.txt

#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()
using namespace std;

ofstream outputfile("output.txt");
const int MAX_FILE_NAME = 35; // Maximum space allocated for file name

void open_input(ifstream& input, char name[]);          // Get file name & Open file
void find_max_min(ifstream& input, int& max, int& min); // Find max & min values
void output(const char name[], int max, int min, ostream& os = cout); // Print results

int main() 
// Parameters: None
// Returns:    Zero
// Calls:      open_input(), find_max_min(), output()     
{  char again;                        // Does user want to go through loop again?
   char file_name[MAX_FILE_NAME + 1]; // Name of file to be processed
   ifstream input_numbers;            // For working with input file

   int max, min;                      // Maximum and minimum numbers from file

   cout << "This program can find the largest and smallest numbers in a file\n"
        << "of integers.\n" << endl;
   system("pause"); // Hold message on screen until key is pressed

   do 
   {  
      system("cls");                           // Clear screen
      open_input(input_numbers, file_name);    // Get file name & open file
      find_max_min(input_numbers, max, min);   // Find max & min values in file
      input_numbers.close();                   // Close file
      output(file_name, max, min);             // Print results on screen
      output(file_name, max, min, outputfile);    // Print results on outputfile

      cout << "\nDo you want to process another file (Y/N)? ";
      cin >> again;
      cin.ignore(256, '\n');  // Remove Enter key from keyboard buffer
   
   } while ( again == 'y' || again == 'Y'); 

   cout << "\nEnd of Program!" << endl;
   outputfile << "\n\nThanks for using MaxMin!\f"; 
   outputfile.close();
   
   return 0; 
}  // End of main()

void open_input(ifstream& input, char name[]) //Open file, exit on error
// Parameters: Variables for input file reference and input file name
// Returns:    None
// Calls:      None
{  int count = 0;             // Count number of tries
   
   do // Continue until we get a valid file name and can open file
   {  
      count++;
      
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

void find_max_min(ifstream& input, int& max, int& min) // Find max & min values
// Parameters: Variables for file reference and max and min values
// Returns:    None
// Calls:      None
{  
   int value;              // Value from file

   input >> value;         // Read first number
   max = min = value;      // Initialize max & min to first number
   while (input >> value)  // Continue as long as we can read a number from file.
   {  
      if (value > max) max = value;
      if (value < min) min = value;
   }
} // End of find_max_min()

void output(const char name[], int max, int min, ostream& os) // Print results
// Parameters: File name, max & min values from file, output stream
// Returns:    None
// Calls:      None
{  os << "\n\nInput File Name        : " << name << endl;
   os << "Largest Number in File : " << setw(8) << max << endl;
   os << "Smallest Number in File: " << setw(8) << min << endl;
} // End of output()
