
// 
//
//CS 114-002
// Project 7/8



#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//do not alter the function headings to "massage" the project in your favor

class Team{
   private:
      string name; //school name
      int Harris_pts; //Harris Points received
      int Coaches_pts; //Coaches' Points received
      int computerRankings[6]; //array contains each of the 6 computer rankings
      string conference; //conference that the school belongs to
   public:
       Team(); //constructor, initializes all points to zero
       void setTeam(string, int, int, int[], string); //sets Team info - name, points, conference
       void setName(string); //set the Team's name
       void setHarris(int); //set the Team's Harris Points
       void setCoaches(int); //set the Team's Coaches' Points
       void setComputer(int[]); //set the Team's Computer Points
       void setConference(string); //set the Team's Conference
       string getName(); //getter for the Team Name
       int getHarris(); //getter for Harris Points
       int getCoaches(); //getter for Coaches' Points
       void getComputer(int[]); //getter for computer points
       string getConference(); //getter for conference
       int computerHigh(); //returns highest computer points received
       int computerLow(); //returns lowest computer points received
       double bcs(int, int); //computes and returns a Team's BCS score; 2 arguments are total possible harris points and total possible coaches points
       void print(int, int); //prints out Team's information, namely the points earned in each poll and computer ranking model; 2 arguments are total possible harris points and total possible coaches points
};

//start functions for the class team
Team::Team(){
	Harris_pts = 0;
	Coaches_pts = 0;

	for(int i=0; i<6; i++){
		computerRankings[i] = 0;
	}
}

void Team::setTeam(string team_name, int harris, int coaches, int computer[], string conferencename){
	//sets all of the poll information about each team
	name = team_name;
	Harris_pts = harris;
	Coaches_pts = coaches;
	for(int i=0; i<6; i++){
	  computerRankings[i] = computer[i];
	}
	conference = conferencename;
}

void Team::setName(string team_name){	//sets the name of the team from the file
	name = team_name;
}
void Team::setHarris(int harris){	//sets the Harris Poll points from the file
	Harris_pts = harris;
}
void Team::setCoaches(int coaches){	//sets the Coaches Polls points from the file
	Coaches_pts = coaches;
}
void Team::setComputer(int computer[]){	//sets the Computer points from the file
	for(int i=0; i<6; i++){
		computerRankings[i] = computer[i];
	}
}
void Team::setConference(string conferencename){	//sets the Conference from the file
	conference = conferencename;
}

string Team::getName(){	//outputs Name of college
    return name;
}

int Team::getHarris(){	//outputs Harris rating
    return Harris_pts;
}
int Team::getCoaches(){	//outputs Coaches rating
    return Coaches_pts;
}
void Team::getComputer(int computer[]){	//outputs Computer ranking
	computer = computerRankings;
}
string Team::getConference(){	//outputs Conference
	return conference;
}

int Team::computerHigh(){	//computes high end computer average
	int highPoints = computerRankings[0];

	for(int i=1;i<6; i++){
		if(computerRankings[i] > highPoints)
				highPoints = computerRankings[i];
	}

	return highPoints;
}
int Team::computerLow(){	//computes low end computer average
    int lowPoints = computerRankings[0];

    for(int i=1;i<6; i++)
    {
        if(computerRankings[i] < lowPoints)
			lowPoints = computerRankings[i];
    }

    return lowPoints;
}

double Team::bcs(int maxHarris, int maxCoaches){	//calculates bcs average
	double bcs = 0.0;
	double Harris_percent = 0.0;
	double Coaches_percent = 0.0;
	double Computer_percent = 0.0;

	Harris_percent = Harris_pts/(double)maxHarris;
	Coaches_percent = Coaches_pts/(double)maxCoaches;

	for(int i=0; i<6; i++){
			if(computerRankings[i] != computerHigh() && computerRankings[i] != computerLow()){
					Computer_percent = Computer_percent + computerRankings[i];
			}
	}

	Computer_percent = Computer_percent/100.0;

	bcs = (Harris_percent + Coaches_percent + Computer_percent)/ 3.0;

	return bcs;
}

void Team::print(int maxHarris, int maxCoaches){	//prints detailed information about each team to the screen
	cout << "Rating: " << bcs(maxHarris,maxCoaches) << endl;
	cout << "Harris Poll Points: " << getHarris() << endl;
	cout << "Coaches Poll Points: " << getCoaches() << endl;
	cout << "Anderson & Hester Points: " << computerRankings[0] << endl;
	cout << "Billingsley Points: " << computerRankings[1] << endl;
	cout << "Colley Matrix Points: " << computerRankings[2] << endl;
	cout << "Massey Points: " << computerRankings[3] << endl;
	cout << "Sagarin Points: " << computerRankings[4] << endl;
	cout << "Wolfe Points: " << computerRankings[5] << endl << endl;
}
//end of class team functions


//See P7/8 description document for details on the following 8 functions:
void read(Team[], int&, int&);
void orderBCSRankings(Team[], int, int);
void printBCSFile(Team[], int, int);
void printBCSScreen(Team[], int, int);
char menu();
void findTeam(string, Team[], int, int);
void findConference(string, Team[], int, int);
void orderByPoll(Team[], string);
void bowlProjections(Team[]);

        //You are given this code -- DO NOT MODIFY MAIN
int main(){
	Team bcs_rankings[25];
	  int harris, coaches;
	char ans = 'y';
	  string locate_team, locate_conference;
	read(bcs_rankings, harris, coaches);
	orderBCSRankings(bcs_rankings, harris, coaches);
	  while (ans == 'y'){
	 ans = menu();
			 switch(ans){
					 case '1': printBCSFile(bcs_rankings, harris, coaches);
							 break;
					 case '2': printBCSScreen(bcs_rankings, harris, coaches);
							 break;
					 case '3': cout<<"Enter the name of the team (use underscore in lieu of space): ";
							 cin>>locate_team;
							 findTeam(locate_team, bcs_rankings, harris, coaches);
							 break;
					 case '4': orderByPoll(bcs_rankings, "Harris");
							 break;
					 case '5': orderByPoll(bcs_rankings, "Coaches");
							 break;
					 case '6': cout<<"Enter conference: ";
							 cin>>locate_conference;
							 findConference(locate_conference, bcs_rankings, harris, coaches);
							 break;
					 case '7': bowlProjections(bcs_rankings);
			 }
			 if (ans=='4'||ans=='5') orderBCSRankings(bcs_rankings, harris, coaches);
	 cout<<endl<<endl<<"Continue?(y/n) ";
			 cin>>ans;
	}
	return 0;
}

void bowlProjections(Team teams[]){
}

void orderBCSRankings(Team teams[], int maxHarris, int maxCoaches){	//sorts BCS Rankings in order

	for(int i=24;i>=0; i--){
		for(int j=1; j<=i; j++){
			if(teams[j-1].bcs(maxHarris,maxCoaches) < teams[j].bcs(maxHarris,maxCoaches)){
				Team temp = teams[j];
				teams[j] = teams[j-1]; 
				teams[j-1] = temp;              
			}
		}
	}
}

void read(Team rankings[], int& maxHarris, int& maxCoaches){	//reads file for input 

	string s;
	ifstream input_file;
	input_file.open("bcs.txt");

	input_file >> maxHarris;
	input_file >> maxCoaches;

		for(int line=0; line<25; line++){
		// Read in the Team name
		input_file >> s;        
		rankings[line].setName(s);
	    
		int points;

		// Read in the harris poll points
		input_file >> points;        
		rankings[line].setHarris(points);

		// Read in the coaches poll points
		input_file >> points;        
		rankings[line].setCoaches(points);


		// Read in the computer poll points
		int computerPolls[6];
				for(int i=0; i<6; i++){
					input_file >> computerPolls[i];
				}
		rankings[line].setComputer(computerPolls);

		// Read in the Conference
		input_file >> s;
		rankings[line].setConference(s);

		}

	input_file.close();
}

void findTeam(string team_name, Team teams[], int maxHarris, int maxCoaches){	//finds a team and displays rating, etc info
	orderBCSRankings(teams, maxHarris, maxCoaches);

	for(int i=0;i<25;i++){
		 if(team_name == teams[i].getName()){
			cout << team_name << endl;
			cout << "Rank: " << (i+1) << endl;
				 teams[i].print(maxHarris, maxCoaches);
			return;
		 }
	}

	cout << "Team not found" << endl;   
}

void findConference(string conference, Team teams[], int maxHarris, int maxCoaches){	//finds a confernce and display
    
	int found = 0;

	orderBCSRankings(teams, maxHarris, maxCoaches);

    for(int i=0;i<25;i++){
		if(conference == teams[i].getConference()){
			cout << (i+1) << " " << teams[i].getName() << " " << teams[i].bcs(maxHarris,maxCoaches) << endl;
			found = 1;
        }
    }

    if(found == 0)
        cout << "No teams from " << conference << " found." << endl;   
}

void printBCSScreen(Team teams[], int maxHarris, int maxCoaches){	//prints rankings to screen within a range
	int lower_rank; 
	int upper_rank;

	cout << "Enter range of the BCS rankings you want to see." << endl;
	cout << "Upper rank: ";
	cin >> upper_rank;
	cout << "Lower rank: ";
	cin >> lower_rank;

	for(int e=(upper_rank-1); e<lower_rank; e++){
		cout << (e+1) << " " << teams[e].getName() << " " << teams[e].bcs(maxHarris,maxCoaches) << endl;
	}
}

void printBCSFile(Team teams[], int maxHarris, int maxCoaches){	//prints rankings to a file
	ofstream output_file;
	output_file.open("bcs_rankings.txt");

	orderBCSRankings(teams, maxHarris, maxCoaches);

	for(int e=0; e<25; e++){
			output_file << (e+1) << " " << teams[e].getName() << " " << teams[e].bcs(maxHarris,maxCoaches) << endl;
	}
	output_file.close();

	cout << "Results written to bcs_rankings.txt" << endl;
}

void orderByPoll(Team teams[], string poll){	//orders schools based upon polls
	ofstream output_file;

	if(poll == "Harris"){    
		for(int e=24;e>=0; e--){
			for(int z=1; z<=e; z++){
				if(teams[z-1].getHarris() < teams[z].getHarris()){
					Team team = teams[z];
					teams[z] = teams[z-1]; 
					teams[z-1] = team;              
				}
			}
		}

	output_file.open("harris_poll.txt");
		for(int e=0;e<25;e++){
				cout << (e+1) << " " << teams[e].getName() << "    " << teams[e].getHarris() << endl;
				output_file << (e+1) << " " << teams[e].getName() << "    " << teams[e].getHarris() << endl;
		}
	output_file.close();
	}

	if(poll == "Coaches"){    
		for(int e=24;e>=0; e--){
			for(int z=1; z<=e; z++){
				if(teams[z-1].getCoaches() < teams[z].getCoaches()){
					Team team = teams[z];
					teams[z] = teams[z-1]; 
					teams[z-1] = team;              
				}
			}
		}

	output_file.open("coaches_poll.txt");
		for(int e=0;e<25;e++){
			cout << (e+1) << " " << teams[e].getName() << "    " << teams[e].getCoaches() << endl;
			output_file << (e+1) << " " << teams[e].getName() << "    " << teams[e].getCoaches() << endl;
		}
	output_file.close();
	} 
}

char menu(void){	//menu for selecting a program operation
	char d='d';

	cout << "2007 Bowl Championship Series Standings" << endl << endl;
	cout << "Select an Option" << endl;
	cout << "1) Print BCS Rankings to a File" << endl;
	cout << "2) Print BCS Rankings to the Screen" << endl;
	cout << "3) Find a Team" << endl;
	cout << "4) Sort by Harris Poll and Print to a File" << endl;
	cout << "5) Sort by Coaches' Poll and Print to a File" << endl;
	cout << "6) View Teams in a Conference" << endl;
	cout << "7) Print out BCS Bowl Projections" << endl;
	cout << "Your choice: ";
	cin >> d;

	return d;
}