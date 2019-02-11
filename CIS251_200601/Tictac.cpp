// Author:     Teresa L. Hitt
// Assignment: Program Example from chapter 10, #10 page 647 altered to use A B C instead of numbers
// File:       TicTac.cpp
// Purpose:    Allows two players to play tic-tac-toe.
// Input:      Row number & column letter of each move.
#include <iostream>
#include <fstream> // I/O
#include <iomanip> // For setw()

//#include <string>         // For stricmp()

using namespace std;

const int MAX_ROWS = 3;   // Maximum number of rows in board
const int MAX_COLS = 3;   // Maximum number of columns in board
const int YES = 1;                
const int NO  = 0;
ofstream outputfile("output.txt");
void play(void);                                                    // Play game
void display(ostream& os, char b[][MAX_COLS], int r, int c);        // Display board
int  make_move(char b[][MAX_COLS], int r, int c, char p);           // Make player's move
int  valid_move(char b[][MAX_COLS],int r, int c, int p_r, int p_c); // Is move valid?
int  is_win(char b[][MAX_COLS], int r, int c, int p_r, int p_c);    // Winning move?
int  squares_left(char b[][MAX_COLS], int r, int c);                // Any squares left?

int main() 
// Parameters: None
// Returns:    Zero
// Calls:      play()    
{  char again;               // Does user want to go through loop again?
   cout << "\nThis program allows two players to play tic-tac-toe.\n";
   do 
   {  play();
      cout << "\nDo you want to play again (Y/N)? ";
      cin >> again;
      cin.ignore(1, '\n');  // Remove Enter key from keyboard buffer
   } while (again == 'y' || again == 'Y'); 

   cout << "\nEnd of Program!" << endl;   outputfile << "\nEnd of Program!\n\f";
   return 0; 
}  // End of main()

void play(void)
// Parameters: None
// Returns:    None
// Calls:      display(), make_move(), squares_left()
{  char board[MAX_ROWS][MAX_COLS] =       // Array to hold board values and 
      { {'A', 'B', 'C'},{'A', 'B', 'C'},  // Initialize array to dummy values
        {'A', 'B', 'C'} 
      };
   char player  = ' ';                    // Player whose turn it is
   int  win = NO;                         // Is there a winner?

   system("cls");
   do // Continue until there is a winner or the board is full 
   {  display(cout, board, MAX_ROWS, MAX_COLS);
      if   (player == 'X') player = 'O';                  // Change player for next turn
      else                 player = 'X';
      win = make_move(board, MAX_ROWS, MAX_COLS, player); // Make player's move
   } while ( !win && squares_left(board, MAX_ROWS, MAX_COLS) );

   display(cout, board, MAX_ROWS, MAX_COLS);
   display(outputfile, board, MAX_ROWS, MAX_COLS);
   if (win) {  cout << "\n" << player << " won!" << endl;
               outputfile << "\n" << player << " won!" << endl;
            }
   else     {  cout << "\nNo winner." << endl;
               outputfile << "\nNo winner." << endl;
            }
} // End of play()

void display(ostream& os, char b[][MAX_COLS], int r, int c)  // Display board
// Parameters: Output stream, Board array, # of rows & columns
// Returns:    None
// Calls:      None
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
// Parameters: Board array, # of rows & columns, Player's symbol
// Returns:    YES if winning move, NO if not
// Calls:      valid_move(), is_win()
{  int  row;                  // User's row number & column letter entered
   char col; 
   int  r_index, c_index;     // Array row & column index of player's move
   do                         // Continue until get valid move
   {   cout << "\n\nPlayer " << p << " enter your move as row number column letter > ";
       cin >> row >> col;
       if (cin.fail()) { cin.clear(); row = -1; }  // Reset cin if invalid characters were entered
       while (cin.get()!= '\n') continue;          // Clear input buffer
       r_index = row - 1;                          // Subtract 1 to get array index
       if ( islower(col) ) col = toupper(col);     // Change to upper case for next statement
       c_index = col - 'A';                        // Subtract 'A' to get array index -- A is 0, B is 1...
   } while ( !valid_move(b, r, c, r_index, c_index) );
   b[r_index][c_index] = p;                        // Put player's symbol in board location
   return is_win(b, r, c, r_index, c_index);       // Was this a winning move?
} // End of make_move()

int valid_move(char b[][MAX_COLS], int r, int c, int p_r, int p_c) // Valid move?
// Parameters: Board array, # of rows & columns, player's row & col choice
// Returns:    YES if it is a valid move, NO if invalid move
// Calls:      None
{  if (p_r < 0 || p_r >= r)                        // Row index out of bounds?
   {  cout << "\n\aInvalid row.\n";                return NO;    }
   if (p_c < 0 || p_c >= c)                        // Column index out of bounds?
   {  cout << "\n\aInvalid column.\n";             return NO;    }
   if (b[p_r][p_c] == 'X' || b[p_r][p_c] == 'O')   // Spot taken?
   {  cout << "\n\aLocation already taken.\n";     return NO;    }
   return YES;                                     // Must be OK, could not find problem
} // End of valid_move()

int is_win(char b[][MAX_COLS], int r, int c, int p_r, int p_c) // Winning move
// Parameters: Board array, # of rows & columns, player's move choice
// Returns:    YES if winning, NO if not
// Calls:      None
{  int  i, j;                         // Row and column index 
   char player = b[p_r][p_c];         // Character of player. Check for win for this symbol.
   int  win;                          // Does player win?
                                      // Check for row win
   for (win = YES, j = 0; j < c; j++) // Check each column of new value's row
   {   if ( b[p_r][j] != player )  
       {  win = NO;  break;  }        // At least one square does not match. No need to check rest of row
   }
   if (win == YES) return YES;        // All in row matched
                                      // Check for column win
   for (win = YES, i = 0; i < r; i++) // Check each row of new value's column
   {   if ( b[i][p_c] != player )
       {  win = NO;  break;  }        // At least one square does not match. No need to check rest.
   }
   if (win == YES) return YES;      // All in column matched
                                    // Check for diagonal wins if array is square and move was to diag. square
   if (r == c && p_r == p_c)              // Possible upper left to lower right diagonal win
   {   for (win = YES, i = 0; i < r; i++) // Check those where row & col are the same
       {   if ( b[i][i] != player )       
           {  win = NO;  break; }         // At least one square does not match. No need to check rest.
       }
       if (win == YES) return YES;        // All in diagonal matched
   }
   if (r == c && p_c == (r - 1) - p_r)    // Possible lower left to upper right diagonal win
   {   for (win = YES, i = 0; i < r; i++) // Check those where col is difference between max & row
       {   if ( b[i][(r-1) - i] != player)
           {  win = NO;  break; }         // At least one square does not match. No need to check rest.
       }
       if (win == YES) return YES;        // All in diagonal matched
   }
   return NO;  // Did not find win
} // End of is_win()

int squares_left(char b[][MAX_COLS], int r, int c)  // Are any squares left
// Parameters: Board array, # of rows & columns
// Returns:    YES if square available, NO if board full
// Calls:      None
{  int i, j;    // Row and column index
   for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         if ( b[i][j] != 'X' && b[i][j] != 'O' ) return YES; // Found available square. No need to check rest.
   return NO;    // Checked all squares and none were available
}  // End of squares_left()