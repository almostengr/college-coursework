#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void tally(int ,  string);
void print(int , string);
void open_input(ifstream, char);
void getnames(ifstream);
const int MAX_FILE_NAME=15;
char name[MAX_FILE_NAME+1];
string candidate_names;
int votes;


void main (){
        ifstream instream;}
void open_input(ifstream& instream, char name[])
{  int count = 0;             
   do 
   {  
      count++;
      
      if (count != 1)  
      {  cout << "\n\aInvalid file name or file does not exist. Please try again." 
              << endl;
      }
   
      cout << "\nEnter the input file name (maximum of " << MAX_FILE_NAME
           << " characters please)\n:> ";
      cin.get(name, MAX_FILE_NAME + 1);
      cin.ignore(256, '\n');           
      
      instream.clear();                   
      instream.open(name, ios_base::in); 
   
   } while (instream.fail() );            
} 

void getnames (ifstream instream){
int n=0;
while(getline(ifstream, candidate_names, ','))
{

candidate_names[][5];




}
}
void tally(int votes[][5], string candidate_names[][5]){
int total, count=0;
ifstream ballot;
ballot.open("ballot.txt");
ballot>>name;
ballot.close();
while (name!=ballot.eof())
if 



}

void print(int votes[][5], string candidate_names[][5]){
vote








}


