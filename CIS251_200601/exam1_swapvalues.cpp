//Kenneth Robinson
#include <iostream>
using namespace std;


int main()
{
	int x;
	int y;
	void swap_values(int& x, int& y);

	cout << "Input two numbers:" << endl;
	cin >> x >> y;

	swap_values(x,y);




	system("pause");
	return 0;
}

void swap_values(int& x, int& y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
	cout << "Values swapped " << x << " " << y << endl;

}
