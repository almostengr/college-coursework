 #include <iostream>
using namespace std;

class Rational {
private:
	int num, den;
	
public:
	Rational ( ) : num(0), den(1) { }	//default constructor
	Rational ( int n) : num(n), den(1) { }	//one argument constructor
	Rational (int n, int d) : num(n), den(d){if (d==0) den=1;}	//two argument constructor
	Rational ( const Rational& r) : num(r.num), den(r.den) { }	//copy constructor
	int getNum ( ) const {return num;}	//accessor function
	int getDen ( ) const {return den;}	//accessor function

	void setNum(int n){num=n;}	//mutator function
	void setDen(int d){			//mutator function
		if(d==0) den=1;
			else den=d;}
	void set(int n, int d) {num=n; den=d;}	//mutator function
	void reduce();	//private method
	friend Rational operator +(const Rational& r, const Rational& t);	//Friend overloaded
			//friend appears in class, but definition is outside class

	Rational operator -(const Rational& r);	//overloaded minus operator

	Rational operator *(const Rational& r){	//overloaded multiplication operator
		Rational temp;
		temp.num=num*r.num;
		temp.den=den*r.den;
		temp.reduce();
		return temp;}

	Rational operator /(const Rational& r){	//overloaded division operator
		Rational temp;
		temp.num=num*r.den;
		temp.den=den*r.num;
		temp.reduce();
		return temp;}


//start added code
	friend ostream& operator << (ostream&, const Rational&);

	friend istream& operator >> (istream&, Rational&);

	
//end added code


	bool isPositive( )const { //public method
		if(num*den > 0) return true;
		return false;
	}

	bool isNegative( )const{  //public method
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

ostream& operator << (ostream& os, const Rational& r){
	os << r.num << "/" << r. den << endl;
	return os;
	}
	
istream& operator >> (istream& is, Rational& r){
	char ch;
	is >> r.num >> ch >> r.den;
	return is;
		}

int gcd( int p, int q)	//GCD function
{if (p==0) return q;
return gcd(q%p,p);}

void Rational::reduce( )	//private function
{int factor =gcd(num, den);
num/=factor; den/=factor;
if (den < 0) {
	num=-num;
	den=-den;}
}

int main()
{
	Rational v(4),x,y,z(7,0);v.print();
	x.set(4,12); x.print();
	cout << "Enter a Fraction." << endl; y.read();
	z=x+y; cout << "The sum is: "; z.print();
	z=x-y; cout << "The difference is: "; z.print();
	z=x*y; cout << "The product is: "; z.print();
	z=x/y; cout << "The quotient is: "; z.print();
	Rational w(z); w.print();		//copy value, then prints
	if (y.isPositive()) cout << "positive" << endl;
	if (y.isNegative()) cout << "negative" << endl;
	return 0;}

