/*	Kenneth Robinson
	Assignment 5
	CIS 251
	March 2, 2006
*/

#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()
using namespace std;

ofstream outputfile("output.txt");
const int MAX_FILE_NAME = 35; // Maximum space allocated for file name
double average;

void open_input(ifstream& input, char name[]);          // Get file name & Open file
void find_average(ifstream& input, double& average); // Find max & min values
void output(const char name[], double average, ostream& os = cout); // Print results

int main()
{  char again;                        // Does user want to go through loop again?
   char file_name[MAX_FILE_NAME + 1]; // Name of file to be processed
   ifstream input_numbers;            // For working with input file

   int max, min;                      // Maximum and minimum numbers from file

   cout << "This program can find the average of the numbers in a file\n"
        << "of integers.\n" << endl;
   system("pause"); // Hold message on screen until key is pressed

   do 
   {  
      system("cls");                           // Clear screen
      open_input(input_numbers, file_name);    // Get file name & open file
      find_average(input_numbers, average);   // Find max & min values in file
      input_numbers.close();                   // Close file
      output(file_name, average);             // Print results on screen
      output(file_name, average, outputfile);    // Print results on outputfile

      cout << "\nDo you want to process another file (Y/N)? ";
      cin >> again;
      cin.ignore(256, '\n');  // Remove Enter key from keyboard buffer
   
   } while ( again == 'y' || again == 'Y'); 

   cout << "\nEnd of Program!" << endl;
   outputfile << "\n\nThanks for using MaxMin!\f"; 
   outputfile.close();
   
   system("pause");
   return 0; 
}  // End of main()

void open_input(ifstream& input, char name[])
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

void find_average(ifstream& input, double& average) // Find average of values
{  
	double value;				// number being input
	double total = 0;				// total of all numbers
	int divisor = 1;			// number to divide by
	
	input >> value;				// reads numbers from file
	while (input >> value)		// loops and gets all numbers
	{
	total = total + value;		// add all values to total
	divisor++;					// changes the number to divide by
	}
	average = total / divisor;	// gets average of numbers
}

void output(const char name[], double average, ostream& os) // Print results
{  os << "\n\nInput File Name: " << name << endl;
   os << "The average of the grades in the file is: " << setw(8) << average << endl;
}