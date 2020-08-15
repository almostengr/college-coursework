/*	
	Assignment 8
	CIS 251
	April 13, 2006
*/
#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()

//#include <string>         // For stricmp()

using namespace std;

const int MAX_ROWS = 7;   // Maximum number of rows in board
const int MAX_COLS = 4;   // Maximum number of columns in board
const int YES = 1;                
const int NO  = 0;
ofstream outputfile("output.txt");
void play(void);                                                    // Play game
void display(ostream& os, char b[][MAX_COLS], int r, int c);        // Display seating area
int  make_move(char b[][MAX_COLS], int r, int c, char p);           // Make player's move
int  valid_move(char b[][MAX_COLS],int r, int c, int p_r, int p_c); // Is move valid?
int  squares_left(char b[][MAX_COLS], int r, int c);                // Any squares left?

int main() 
// Parameters: None
// Returns:    Zero
// Calls:      play()    
{  char again;               // Does user want to go through loop again?
   cout << "\nThis program tracks the number of seats remaining on the airplane\n";
   do 
   {  play();
      cout << "\nDo you want to track the seats again (Y/N)? ";
      cin >> again;
      cin.ignore(1, '\n');  // Remove Enter key from keyboard buffer
   } while (again == 'y' || again == 'Y'); 

   cout << "\nEnd of Program!" << endl;   outputfile << "\nEnd of Program!\n\f";
   system("pause");
   return 0; 
}  // End of main()

void play(void)
{  char board[MAX_ROWS][MAX_COLS] =       // Array to hold board values and 
      { {'A', 'B', 'C', 'D'},		//row 1
	 {'A', 'B', 'C', 'D'},  // Initialize array to dummy values  row 2
      {'A', 'B', 'C', 'D'}, 		//row 3
	 {'A', 'B', 'C', 'D'}, 		//row 4
	 {'A', 'B', 'C', 'D'}, 		//row 5
	 {'A', 'B', 'C', 'D'}, 		//row 6
	 {'A', 'B', 'C', 'D'}, 		//row 7
      };
   char player  = 'X';                    // to denote if seat has been filled

   system("cls");
   do // Continue until there is a winner or the board is full 
   {  display(cout, board, MAX_ROWS, MAX_COLS);
      make_move(board, MAX_ROWS, MAX_COLS, player); // Make player's move
   } while (squares_left(board, MAX_ROWS, MAX_COLS) );

   display(cout, board, MAX_ROWS, MAX_COLS);
   display(outputfile, board, MAX_ROWS, MAX_COLS);
} // End of play()

void display(ostream& os, char b[][MAX_COLS], int r, int c)  // Display board
{  int i, j;    // Row and column index
   os << "\n\n";
   for (i = 0; i < r; i++)
   {  os << setw(3) << (i + 1) << "    ";  
      for (j = 0; j < c; j++)
      {  os << setw(4) << b[i][j]; 
      }
      os << endl;
   }
} // End of display()
int make_move(char b[][MAX_COLS], int r, int c, char p)   // Make player's move
{  int  row;                  // User's row number & column letter entered
   char col; 
   int  r_index, c_index;     // Array row & column index of player's move
   do                         // Continue until get valid move
   {   cout << "\n\nEnter your seat as row number column letter > ";
       cin >> row >> col;
       if (cin.fail()) { cin.clear(); row = -1; }  // Reset cin if invalid characters were entered
       while (cin.get()!= '\n') continue;          // Clear input buffer
       r_index = row - 1;                          // Subtract 1 to get array index
       if ( islower(col) ) col = toupper(col);     // Change to upper case for next statement
       c_index = col - 'A';                        // Subtract 'A' to get array index -- A is 0, B is 1...
   } while ( !valid_move(b, r, c, r_index, c_index) );
   b[r_index][c_index] = p;                        // Put player's symbol in board location
   return 1; //is_win(b, r, c, r_index, c_index);       // Was this a winning move?
} // End of make_move()

int valid_move(char b[][MAX_COLS], int r, int c, int p_r, int p_c) // Valid move?
{  if (p_r < 0 || p_r >= r)                        // Row index out of bounds?
   {  cout << "\n\aInvalid row.\n";                return NO;    }
   if (p_c < 0 || p_c >= c)                        // Column index out of bounds?
   {  cout << "\n\aInvalid column.\n";             return NO;    }
   if (b[p_r][p_c] == 'X' || b[p_r][p_c] == 'O')   // Spot taken?
   {  cout << "\n\aSeat already taken.\n";     return NO;    }
   return YES;                                     // Must be OK, could not find problem
} // End of valid_move()

int squares_left(char b[][MAX_COLS], int r, int c)  // Are any squares left
{  int i, j;    // Row and column index
   for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         if ( b[i][j] != 'X') return YES; // Found available square. No need to check rest.
   return NO;    // Checked all squares and none were available
}  // End of squares_left()