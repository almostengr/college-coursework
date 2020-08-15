#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;

const int velocity1 = 12000;	// Velocity of stage 1
const int velocity2 = 11000;	// Velocity of stage 2
const int velocity3 = 11000;	// velocity of stage 3

const int velocity[3] = {12000, 11000, 11000};
const double structural[3] = {0.20, 0.15, 0.15};

const double structural_p1 = 0.20;	//structural parameter stage 1
const double structural_p2 = 0.15;	//structural parameter stage 2
const double structural_p3 = 0.15;	//structural parameter stage 3

int stage; // number of stage
int initial_mass;	//inital mass of the rocket
int stage_n = 1;	//stage number

double alpha[3];	//array for alpha
double burnout[3];	//array for burnout mass ratio
double payload[3];	//array for payload mass ratio

double inital_to_payload;	//initial mass to payload mass ratio

void find_alpha();	//calculates alpha for each stage 
/*int burnout_ratio();	//calculates burnout ratio for each stage
int payload_ratio();	//calculates payload ratio
int inital_playload_ratio();	//calculates inital mass to payload mass ratio
*/
void find_alpha(){

	double num;	//numerator of fraction
	double den;	//denomenator of fraction
	int alpha_deg = -180;
	double alpha = 0;

	stage_n=1;


	do{
		num = alpha_deg * 12000;
		den = alpha_deg * 12000 * 0.20;
		alpha = num / den;

		//cout << "Alpha for Stage " << stage_n << " is: " << alpha[stage_n] << "\n";
		cout << "Alpha in degrees is: " << alpha_deg << "\n";
		cout << "Alpha is: " << alpha << "\n";

		//system("pause");

		alpha_deg++;

		//stage_n++;
	}while (alpha_deg <=10);
	//return (alpha[1], alpha[2], alpha[3]);
}

/*
int burnout_ratio(){

	double mass_start;	//stage 1 start vehicle mass
	double mass_end;	//stage 1 end vehicle mass

	stage_n=1;

	do{
	mass_start = alpha[stage_n] * velocity[stage_n] + 1;	//stage 1 starting mass
	mass_end = alpha[stage_n] * structural[stage_n] * velocity[stage_n];	//stage 1 ending mass
	burnout[stage_n] = mass_start/mass_end;	//stage 1 ratio

	cout << "Stage " << stage_n << " Burnout Ratio: " << burnout[stage_n] << endl;

	stage_n++;
	}while (stage_n<=3);
}
*/


int payload_ratio(){
	
	double num[3];	//numerator array
	double den[3];	//denomerator array

	stage_n = 1;	//resets stage number

	for (i=1; i=3; i++){
		num[stage_n] = 1 - burnout[stage_n] * structural[stage_n];
		den[stage_n] = burnout[stage_n] - 1;

		payload[stage_n] = num[stage_n] / den[stage_n];	//
	}
}

int inital_payload_ratio(){

}

void main(){

/*
	int x = 200;
double y;
   y = log( x );
   printf( "log( %.2f ) = %f\n", x, y );

*/
/*
	cout << "What is the initial mass of the rocket? ";
	cin >> initial_mass;
	cout << "\n";
*/
	find_alpha();
	//burnout_ratio();
	//payload_ratio();
	//inital_payload_ratio();
	cout << "End of program... \n";
	system("pause");	

} // End of program