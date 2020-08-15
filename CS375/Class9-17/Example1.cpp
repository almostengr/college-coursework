#include <iostream>
using namespace std;

template <class T>

class Aclass{
	T value;
	
	public:
	Aclass() { }

};



int main(){
	Aclass <int> a;
	Aclass <double> b;
	Aclass <string> c;

	return 0;
}
