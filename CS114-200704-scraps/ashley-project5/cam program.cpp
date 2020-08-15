#include <iostream>
#include <iomanip>
#include <fstream>
#include<stdio.h>
#include <cmath>
#include<math.h>
using namespace std;
double choice;


int main()
{
    
    cout<<"Type 1 for the Rocketry program"<<endl;
    cout<<"Type 2 for the Structural Dynamics Free Free Program"<<endl;
    cout<<"Type 3 for the Structural Dynamics Fixed Free Program"<<endl;
    cout<<"Type 4 for Aerodynamics"<<endl;
    cin>>choice;
    
    if (choice==1)
    {
         double n=3;
         double veq1=12000;
         double veq2=11000;
         double veq3=11000;
         double ep1=0.20;
         double ep2=0.15;
         double ep3=0.15;
         double vb=29000;
         double R1;
         double R2;
         double R3;
         double a;
         double l1;
         double l2;
         double l3;
         double m0ml; 
         double fa;
         double right = 1000000;
         double left = -1000000;
         double midpoint; 
         double epsilon;  
        
         R1=(a*veq1+1)/(a*ep1*veq1);
         R2=(a*veq2+1)/(a*ep2*veq2);
         R3=(a*veq3+1)/(a*ep3*veq3);
         vb=veq1*log(R1)+veq2*log(R2)+veq3*log(R3);
         l1=(1-R1*ep1)/(R1-1);
         l2=(1-R2*ep2)/(R2-1);
         l3=(1-R3*ep3)/(R3-1);
         m0ml= ((((((1/l3)+1)/l2)+((1/l3)+1))/l1)+(((1/l3)+1)/l2)+((1/l3)+1));
         do
         {
              
             midpoint = (right + left)/2;
         if(((veq1*log((left*veq1+1)/(left*ep1*veq1))+veq2*log((left*veq2+1)/(left*ep2*veq2))+veq3*log((left*veq3+1)/(left*ep3*veq3))) * (veq1*log((midpoint*veq1+1)/(midpoint*ep1*veq1))+veq2*log((midpoint*veq2+1)/(midpoint*ep2*veq2))+veq3*log((midpoint*veq3+1)/(midpoint*ep3*veq3)))) > 0)
                  left = midpoint;
         else 
                  right = midpoint;
      }  
          while (abs(right - left) > epsilon);
                a = midpoint;  
               fa=(-29000)+veq1*log((a*veq1+1)/(a*ep1*veq1))+veq2*log((a*veq2+1)/(a*ep2*veq2))+veq3*log((a*veq3+1)/(a*ep3*veq3));
          
                cout<<"alfa    "<<a<<endl;
                cout << fa << endl;
     }     
        
         
 
   
   
    else if (choice ==2)
    { 
         double omega;
         double EI;
         double m;
         double L;
         double lamda;
         double w;
         double h;
              //omega=lamda*lamda*sqrt(EI/m);
                                           
    }            
    else if (choice== 3)
    {
         
    }
    else if (choice== 4)
    {
         //ifstream infile("L:\\Aerodynamic.txt");
         double t; //theata
         double m; double g; double b;
         b=20; //betta
         m=.3;  //mach
         g=1.4; //gamma
         while (m>1)
         {
               //t=atan(2*(1/tan(b))((m*m*sin(b)*sin(b)-1)/(m*m*(g+cos(2*b)+2)));
               //m=m+.01;
         }
         //cout<<t; 
    }
    else
    {
        cout<<"Choice does not exist, please rerun the program and select a valid choice";
    }
    cin.get();
    cin.get();
}
