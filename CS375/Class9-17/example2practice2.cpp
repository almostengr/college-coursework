#include <iostream>
using namespace std;

//class Animal
//class Dog inherits Animal
//Animal::speak() splat

//Animal *bob = new Dog();
//bob -> speak(); to bark

class Animal{
	protected:	//INHERITED CLASSES CAN ACCESS IT, IT APPEARS PRIVATE TO OTHERS
		int value;
	public: 
		Animal(){
			value = 3;
		}

		virtual void speak(){
			cout << "Bark" << endl;
		}
	//WHEN USING VIRTUAL, IT USES DYNAMIC BINDING
	//IF IT DOESN'T FIND ANOTHER VERSION OF FUNCTION, THEN WILL CALL ORIGINAL

};

class Pet: public Animal{
	public:
		Pet(){
		}

		virtual void sit(){	
			cout << "Sitting" << endl;
		}
};

class Dog: public Animal, public Pet{
	public:
		Dog(){ }

	void speak(){
		cout << "BARK" << endl;
	}
	
/*
	void (){	
		cout << "Goodbye from B. My value is " << value << endl;
	}
*/

};



int main(){
#if 0
	A a;
	a.sayHi();
	
	B b;
	b.sayHi();


	Dog *bob = new Dog();
	bob -> speak();
#endif

	Animal *bob = new Pet();	//TREATING IT LIKE CLASS A ALTHOUGH CREATING NEW CLASS B
	
	bob  -> sit();
	//ab -> sayBye();

	return 0;
}
