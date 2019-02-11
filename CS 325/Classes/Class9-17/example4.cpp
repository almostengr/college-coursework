#include <iostream>
using namespace std;

template <class T>
class Sit: public T{
	public: 
		void doSit(){
			cout << "Sit" << endl;
		}
};

template <class T>
class Stay: public T{
	public:
		void doStay(){
			cout << "Stay" << endl;
		}
};

template <class T>
class Fetch: public T{
	public: 
		void doFetch(){
			cout << "fetch" << endl;
		}
};


class Dog{
	public: 	
		Dog(){ 	}
};


int main(){
/*	Dog *fido = new Dog();	
*/

	Sit<Dog> fido;
	fido.doSit();
	
Dog *badDog = new Dog();

	return 0;
}
