 #include <iostream>
using namespace std;

class Rational {
private:
	int num, den;
	
public:
	Rational ( ) : num(0), den(1) { }
	Rational ( int n) : num(n), den(1) { }
	Rational (int n, int d) : num(n), den(d){if (d==0) den=1;}
	Rational ( const Rational& r) : num(r.num), den(r.den) { }
	int getNum ( ) const {return num;}
	int getDen ( ) const {return den;}

	

	void setNum(int n){num=n;}
	void setDen(int d){
		if(d==0) den=1;
			else den=d;}
	void set(int n, int d) {num=n; den=d;}
	void reduce();
	friend Rational operator +(const Rational& r, const Rational& t);

	Rational operator -(const Rational& r);

	Rational operator *(const Rational& r){
		Rational temp;
		temp.num=num*r.num;
		temp.den=den*r.den;
		temp.reduce();
		return temp;}

	Rational operator /(const Rational& r){
		Rational temp;
		temp.num=num*r.den;
		temp.den=den*r.num;
		temp.reduce();
		return temp;}

	bool isPositive( )const { 
		if(num*den > 0) return true;
		return false;
	}

	bool isNegative( )const{ 
		if(num*den < 0) return true;
		return false;
	}

	void print( ){reduce(); cout << num << "/" << den << endl;}

	void read( ) { char  ch;
	cin >> num >> ch >> den;
	reduce( );}
};

Rational operator +(const Rational& r, const Rational& t){
		Rational temp;
		temp.num=r.num*t.den+r.den*t.num;
		temp.den=r.den*t.den;
		temp.reduce();
		return temp;}

Rational Rational::operator -(const Rational& r){
		Rational temp;
		temp.num=num*r.den-den*r.num;
		temp.den=den*r.den;
		temp.reduce();
		return temp;}

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
	Rational v(4),x,y,z(7,0);
	v.print();
	x.set(4,12); x.print();
	cout << "Enter a Fraction." << endl; y.read();
	z=x+y; cout << "The sum is: "; z.print();
	z=x-y; cout << "The difference is: "; z.print();
	z=x*y; cout << "The product is: "; z.print();
	z=x/y; cout << "The quotient is: "; z.print();
	Rational w(z); w.print();
	if (y.isPositive()) cout << "positive" << endl;
	if (y.isNegative()) cout << "negative" << endl;
	return 0;}

