#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<char> s;
	set<char>::iterator i;
	
	s.insert('S');
	s.insert('T');
	s.insert('U');
	s.insert('V');
	s.insert('S');
	s.insert('V');
	s.insert('T');
	s.insert('W');

	cout << "This set holds:\n";
	for (i = s.begin(); i != s.end(); i++)
		cout << *i << " ";
	cout << endl;



	return 0;

}