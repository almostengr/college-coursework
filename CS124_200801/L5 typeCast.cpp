#include <iostream>
#include <string>
using namespace std;
class Rational {
	int num, den;
public:
	Rational( );
	Rational(int, int);
	Rational(double);
	Rational(char);
	operator double()const;
	friend Rational operator+ ( const Rational& a, const Rational& b );
	friend ostream& operator<<(ostream&, const Rational&);
	
}; 
Rational::Rational():num(0), den(1){cout << "default" << endl;}
Rational::Rational(int n, int d):num(n), den(d){cout << "ints" << endl;}
Rational::Rational(double n):num(n), den(1){cout << "double" << endl;}
Rational::Rational(char ch):num(ch-'0'), den(1){cout << "char" << endl;}
Rational operator + (const Rational& a, const Rational& b)
{
	Rational temp;
	temp.num=a.num*b.den+b.num*a.den;
	temp.den=a.den*b.den;
	return temp;}

ostream& operator<<(ostream& os, const Rational& r){
cout << r.num << "/" << r.den << endl;
return os;
}
Rational::operator double( ) const{
	double ans;
    ans=(double) num / den;
return ans;}
     
int main( ) {
	Rational d(3,4);
	double x;
	x = d;
	cout << x << endl;
	return 0;
}