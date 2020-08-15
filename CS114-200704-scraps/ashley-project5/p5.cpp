#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void tally(int votes[][5], string candidate_names[][5]);
void print(int votes[][5], string candidate_names[][5]);
void open_input(ifstream& input, char name[]);
void getnames(ifstream& input);
const int MAX_FILE_NAME=15;
char name[MAX_FILE_NAME+1];
string candidate_names;
int votes;


int main (){
        
	ifstream input;

	cout << "Ballot Counting Program \n\n";


/*
	open_input(input, name);	
	//input.open ("ballot.txt"); //open_input(input, name);

	if(input.is_open()){
			cout << "Opening ballot.txt...\n";
	}
	if(input.fail()){
		cout << "Unable to open \"ballot.txt\" file.\n";
		system("pause");
		return 0;
	}
	

	getnames(input);
	input.close();
	//tally(int votes, candidate_names);

	//print(votes, candidate_names);
	*/
	system("pause");
	return 0;
}


void open_input(ifstream& input, char name[])
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
      
	  input.clear();                   
      input.open(name, ios_base::in); 
   
   } while (input.fail() );            
} 

void getnames (ifstream& input){

	int can =0, pos = 0;

	cout << "Reading ballots and candidate names..." << endl;

	//input >> candidate_names[can][pos];
getline(
	while(!input.eof()){
		
		while(input != ","){
		input >> candidate_names;

	
			
		can = can + 1;
		if (input == ","){
			pos = pos + 1;
		}
		
		if (input == "\n"){
			pos = 0;
		}
		}

	}
	cout << "end of counting..." << endl;
}


void tally(int votes[][5], string candidate_names[][5]){


}

void print(int votes[][5], string candidate_names[][5]){

	int display=0;

	cout << "President" << setw(20) << "Votes" << setw(14) << "Percent" << setw(7) << endl;
		while (num_of_pres<=display){
			candidate_name[display][0]
			display = dislay+1;
		}
	display=0;
	cout << "Vice President" << setw(20) << "Votes" << setw(14) << "Percent" << setw(7) << endl;
			while (num_of_v_pres<=display){
			candidate_name[display][1]
			display = dislay+1;
		}
	display=0;
	cout << "Secretary" << setw(20) << "Votes" << setw(14) << "Percent" << setw(7) << endl;
			while (num_of_sec<=display){
			candidate_name[display][2]
			display = dislay+1;
		}
	display=0;
	cout << "Treasurer" << setw(20) << "Votes" << setw(14) << "Percent" << setw(7) << endl;
			while (num_of_tres<=display){
			candidate_name[display][3]
			display = dislay+1;
		}
	display=0;
	cout << "Judge" << setw(20) << "Votes" << setw(14) << "Percent" << setw(7) << endl;
			while (num_of_judge<=display){
			candidate_name[display][4]
			display = dislay+1;
		}
	display=0;
	cout << "Senator" << setw(20) << "Votes" << setw(14) << "Percent" << setw(7) << endl;
			while (num_of_sen<=display){
			cout << candidate_name[display][5] << setw(20) << votes[display][5] << 
				setw(14) << votes[display][5]/total_senator_votes << endl;

			display = dislay+1;
		}

//	cout << setprecisionn(2) << percentage[n] << "%" << endl;

}
