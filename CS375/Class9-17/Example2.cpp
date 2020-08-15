#include <iostream>
using namespace std;

class A{
	protected:	//INHERITED CLASSES CAN ACCESS IT, IT APPEARS PRIVATE TO OTHERS
		int value;
	public: 
		A(){
			value = 3;
		}

		virtual void sayHi(){
			cout << "Hello from A. My value is" << value << endl;
		}
	//WHEN USING VIRTUAL, IT USES DYNAMIC BINDING
	//IF IT DOESN'T FIND ANOTHER VERSION OF FUNCTION, THEN WILL CALL ORIGINAL

};


class B: public A{
	public:
		
		B(){ }
/*	
	void sayHi(){
		cout << "Hello from B. My value is" << value << endl;
	}
*/
	
	void sayBye(){	
		cout << "Goodbye from B. My value is " << value << endl;
	}

};

int main(){
#if 0
	A a;
	a.sayHi();
	
	B b;
	b.sayHi();
#endif

	B *b = new B();
	b -> sayHi();	

	A *ab = new B();	//TREATING IT LIKE CLASS A ALTHOUGH CREATING NEW CLASS B
	ab -> sayHi();
	//ab -> sayBye();

	return 0;
}
