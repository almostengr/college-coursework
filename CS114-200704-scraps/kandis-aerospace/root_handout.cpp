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
    double xl, xu, prod, f_xl, f_xu, dx, a=0, b=5;
    dx=(b-a)/intervals;
    xl=a;
    xu=xl+dx;
    for(j=0; j<=num_roots; j++)
    {
             xlow[j]=0;
             xhigh[j]=0;
             f_xlow[j]=0;
             f_xhigh[j]=0;
}
j=0;
while(xu<=b)
{
               f_xl=G(xl);
               f_xu=G(xu);
              
               prod=f_xl*f_xu;
               if(prod<0)
               {
                         
                         xlow[j]=xl;
                         xhigh[j]=xu;
                         f_xlow[j]=f_xl;
                         f_xhigh[j]=f_xu;
                         j=j+1;
                         xl=xl+dx;
                         xu=xu+dx;
               }
               else if(prod==0)
               {
                    if(f_xl==0)
                    {
                    xl=xl-dx/2;
                    xu=xu-dx/2;
                    }
                    else
                    {
                    xu=xu+dx/2;
                    xl=xl+dx/2;
                    }
                    xlow[j]=xl;
                    xhigh[j]=xu;
                    f_xlow[j]=f_xl;
                    f_xhigh[j]=f_xu;
                    j=j+1;
                    xl=xl+dx;
                    xu=xu+dx;
               }
               else
               {
                   xl=xl+dx;
                   xu=xu+dx;
               }
               
}
jmax=j;


cout<<"Root#    f(xl)     f(xu)     xl       xu"<<endl;
cout<<"----------------------------------------"<<endl;
    for(j=0; j<=jmax-1; j++)
    {
            
cout<<setprecision(4)<<j+1<< "  "<<f_xlow[j]<< "  "<<f_xhigh[j]<< "  "<<xlow[j]<< "  "<<xhigh[j]<<endl;
            
                
     }
cin.get(); cin.get();

system("pause");
}                     
double G(double x)
{
       double gx;
       gx=sin(10*x)+cos(3*x);
       return gx;
}
       
           
           
    
    
   
    
