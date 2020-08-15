#include <iostream>		//input and output stream library
#include <cmath>		//math library
using namespace std;


//variables
const int velocity[3] = {12000, 11000, 11000};		//velocity for each stage
const double structural[3] = {0.20, 0.15, 0.15};	//structural parameters for each stage

int stage = 0;	//stage number

double alpha;	//alpha
double burnout[3];	//array for burnout mass ratio
double payload[3];	//array for payload mass ratio


//functions
double find_alpha();	//calculates what alpha is by find the root
void burnout_ratio();	//calculates burnout ratio for each stage
void payload_ratio();	//calculates payload ratio
void inital_playload_ratio();	//calculates inital mass to payload mass ratio

double find_alpha(){	//finds alpha in burnout mass ratio
	
	return alpha;
}

void burnout_ratio(){	//burnout mass ratio function

	stage = 0;	//resets stage number

	do{
		burnout[stage] = ((alpha * velocity[stage])+1)/(alpha * structural[stage] * velocity[stage]);
		//divides for burnout ratio

		cout << "\nBurnout Ratio for Stage " << stage + 1 << " is: " << burnout[stage] << endl;
		//prints the burnout ratio for each stage to the screen

		stage++;	//increments the stage number + 1

	}while (stage <= 2);		//continues loop based on value of stage
}

void payload_ratio(){	//payload ratio function

	stage = 0;	//resets stage number for array

	do{
		payload[stage] = (1 - (payload[stage]*structural[stage])) / (structural[stage]-1);			
		//divides numerator by denominator for payload ratio

		cout << "\nPayload Ratio for Stage " << stage + 1 << " is: " << payload[stage] << endl;	
		//prints payload ratio for each stage to the screen

		stage++;	//increments the stage number + 1 

	}while (stage <= 2);		//contines loop while stage number is less than or equal to 2 
}

void initial_payload_ratio(){	//initial mass to payload ratio function
	
	double ip_ratio;	// initial to payload ratio that's printed to the screen

	ip_ratio = (((((1/payload[2])+1)/2) + ((1/payload[2])+1))/payload[0]) + (((1/payload[2])+1)/payload[1]) + ((1/payload[2])+1);
	// finds M0/ML a.k.a. initial mass to payload mass ratio

	cout << "\nInitial to Payload Ratio is: " << ip_ratio << endl;	
	//prints the initial to payload ratio to the screen
}


int main(){	//main function

	//START to be replaced by root finding function
	cout << "--Rocketry Program (Initial Mass Optimization)--" << endl;
	cout << "What is alpha? ";	//asks what alpha is
	cin >> alpha;	//user inputs alpha
	cout << "\nAlpha is: " << alpha << endl;	//states alpha inputted by user
	//END to be replaced by root finding function

	//alpha = find_alpha();	//calls function to find alpha

	burnout_ratio();	//calls Burnout Ratio function
	cout << "\n";	//prints blank line on screen
	payload_ratio();	//calls Payload Ratio function
	cout << "\n";	//prints blank line on screen
	initial_payload_ratio();	//calls Initial to Payload function
	cout << "\n";	//prints blank line on screen
	system("pause");	//system pause, requires user to continue


return 0;
}

