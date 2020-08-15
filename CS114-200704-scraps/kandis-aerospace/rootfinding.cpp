/* An example on the use of functions :
                        recursive calls to a  function        file: 5ex4.cpp
   FALL 1998
   ___________________________________
   Jacob Y. Kazakia   jyk0
   October 8, 1998
   Example 4 of week 5
   Recitation Instructor: J.Y.Kazakia
   Recitation Section  01
   ___________________________________

Purpose: This program utilizes the function

double bisect (double xLeft, double xRight, double xtol, double ftol)

to locate the root of the function  f(x) = x^2 - 5 ,  between xLeft = 2
and xRight = 3.


Algorithm:  The bisection algorithm is described in the function bisect.

                */

 

  // Prototype the function


double bisect (double xLeft, double xRight, double xtol, double ftol);

double f( double x);

void main()
{
// declare the variables of the main function

double xLeft = 0;  // the initial left boundary
double xRight = 3.14; // the initial right boundary
double xtol = 1.0e-10; // the tolerance in x error ( this is the absolute value
                       // of the difference between two consecutive
                       // approximations of the root divided by the absolute
                       // value of the last approximation.
double ftol = 1.0e-8;  // The tolerance in f error ( this is the absolute value
                       // of the function for a given approximation of the root
double root_of_five;     // the needed root ( square root of 5  or  2.236068 )

//  invoking the function

root_of_five = bisect ( xLeft, xRight, xtol, ftol);

// output the root

cout << setiosflags(ios:: fixed) << setprecision(14);
cout << " \n\n   The root is = " << root_of_five << endl;


// hold the screen
/*
cout<<" \n\n enter e (exit) to terminate the program....";
char hold;
cin>>hold;
*/

system("pause");
}


/*       definition of function bisect

Purpose: To locate the root of a function  f(x)  between xLeft and xRight.

Algorithm:  The bisection method is used.  This consists of:
             1) Cheking to make sure that  f(xLeft) * f(xRight) is negative
             2) calculating  xMid = ( xLeft + xRight ) / 2.
             3) calculating  f( xMid)
             4) if   either  |f(xMid)| < ftol
                         or  |xRight - xLeft| / |xLeft| < xtol

                         the root is xMid.

             5) otherwise proceed as follows;

                  for f(xMid)* f(xLeft) > 0
                  use  xMid for xLeft and keep the same xRight

                  for f(xMid)* f(xLeft) < 0
                  use  xMid for xRight and keep the same xLeft

                  */

double bisect (double xLeft, double xRight, double xtol, double ftol)
{

double root = 0.0;
double xMid = 0.0;

if ( f(xLeft)*f(xRight) > 0 || xLeft > xRight )
 { cout<<" \n\n Wrong bracket" ;
   cout<<" \n Root will be set to 9999 \n";
   root = 9999;
 }
else if ( fabs(f(xLeft))  < ftol)    root = xLeft;
else if ( fabs(f(xRight)) < ftol)    root = xRight;
else
 {
  xMid = 0.5*(xLeft + xRight);
  if ( (xRight - xLeft)/fabs(xLeft) < xtol )       root = xMid;
  else if ( f(xLeft)*f(xMid) <0.0 )
    root = bisect( xLeft, xMid, xtol, ftol);
  else
    root = bisect( xMid, xRight, xtol, ftol);
 }

return ( root);
}

//    Definition of the function f(x)

double f ( double x)
{
double value;


value = x*x - 5;

return (value);

}


/*     THE OUTPUT IS:




   The root is = 2.23606797680259


 enter e (exit) to terminate the program....


 IF WE REDUCE THE TOLERANCES TO 1e-14 then we get:


 

   The root is = 2.23606797749979


 enter e (exit) to terminate the program....



 THE EXACT VALUE IS: 2.23606 79774 99789 .......( Handbook by M.R. Spiegel )

 */




