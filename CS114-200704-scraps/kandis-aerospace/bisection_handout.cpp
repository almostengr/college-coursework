/* Root Search Handout*/
#include<iostream>
#include<cmath>
#include<iomanip>
double G(double);
using namespace std;
int main()
{
    int const intervals=200;
    int const num_roots=20;
    double xlow[num_roots], xhigh[num_roots], f_xlow[num_roots],f_xhigh[num_roots];
    int j,jmax;
    double xl, xu, xr, prod, f_xl, f_xu, f_xr, dx, a=0, b=5;
    dx=(b-a)/intervals;
    xl=a;
    xu=xl+dx;
    xr=xl+xu/2;
    for(j=0; j<=num_roots; j++)
    {
             xlow[j]=0;
             xhigh[j]=0;
             f_xlow[j]=0;
             f_xhigh[j]=0;
             f_xr[j]=0
}
j=0;
while(!(x_low[j])==0)
{
               f_xl=G(xl);
               f_xu=G(xu);
               xr=xu+xl/2;
               f_xr              
               prod=f_xl*f_xr;
               if(prod<0)
               {
                         
                         xlow[j]=xl;
                         xhigh[j]=xr;
                         f_xlow[j]=f_xl;
                         f_xhigh[j]=f_xr;
                         j=j+1;
                         xl=xl+dx;
                         xr=xr+dx;
               }
               else
               {
                    
                    {
                    xl=xl-dx/2;
                    xu=xu-dx/2;
                    }
                    }
                    else
                    {
                    xu=xu+dx/2;
                    xl=xl+dx/2;
                    }
                    xlow[j]=xl;
                    xhigh[j]=xu;
                    j=j+1;
                    //xl=xl+dx;
//                    xu=xu+dx;
               }
               else
               {
                   xl=xl+dx;
                   xu=xu+dx;
               }
               
}
jmax=j;


cout<<"Root#          Xr               Error "<<endl;
cout<<"--------------------------------------"<<endl;
    for(j=0; j<=jmax-1; j++)
    {
            
cout<<setprecision(5)<<j+1<< "  "<<f_xlow[j]<< "  "<<f_xhigh[j]<< "  "<<xlow[j]<< "  "<<xhigh[j]<<endl;
            
                
     }
cin.get(); cin.get();
}                     
double G(double x)
{
       double gx;
       gx=sin(10*x)+cos(3*x);
       return gx;
}
       
           
           
    
    
   
    
