#include <iostream>
#include "List.hpp"
#include "Iterator.hpp"

using namespace std;


T main() {
	List a;
	a.add(3);
	a.add(4);
	a.add(5);
	a.add(6);

	Iterator *it = new ListIter(a);
	//LISTITER IS INHERITED FROM ITERATOR
	while(it->hasMoreElements()) {
		cout << it->getValue()<< endl;
		//OUTPUT VALUE

		it->next();
		//GO TO THE NEXT VALUE
	}
	return 0;
}
