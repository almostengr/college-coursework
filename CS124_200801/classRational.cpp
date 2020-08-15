#include <iostream>
using namespace std;

class Rational {
private:
	int num, den;
	void reduce();
public:
	Rational ( ) : num(0), den(1) { }
	Rational (int n, int d) : num(n), den(d){if (d==0) den=1;}
	int getNum ( ) {return num;}
	int getDen ( ) {return den;}

	void setNum(int n){num=n;}
	void setDen(int d){
		if(d==0) den=1;
			else den=d;}

	Rational add(Rational r){
		Rational temp;
		temp.num=num*r.den+den*r.num;
		temp.den=den*r.den;
		temp.reduce();
		return temp;}

	Rational mult(Rational r){
		Rational temp;
		temp.num=num*r.num;
		temp.den=den*r.den;
		temp.reduce();
		return temp;}

	void print( ){reduce(); cout << num << "/" << den << endl;}

	void read( ) { char  ch;
	cin >> num >> ch >> den;
	reduce( );}
};

int gcd( int p, int q)
{if (p==0) return q;
return gcd(q%p,p);}

void Rational::reduce( )
{int factor =gcd(num, den);
num/=factor; den/=factor;
if (den < 0) {
	num=-num;
	den=-den;}
}

int main()
{
	Rational x,y,z(7,0);
	x.setNum(4); x.setDen(12); x.print();
	cout << "Enter a Fraction." << endl; y.read();
	z=x.add(y); cout << "The sum is: "; z.print();
	z=x.mult(y); cout << "The product is: "; z.print();
	return 0;}
