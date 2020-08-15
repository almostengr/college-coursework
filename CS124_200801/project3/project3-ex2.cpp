/*exercise #2
declares a deque of ints
inserts the numbers 1 to 100 into the deque
	insert all the even numbers at the front of the deque
	insert all odd numbesr at the back of the deque
print the contents of the deque
prints the contents of the deque in reverse order
calculates the average of all values in the deque
*/

#include <iostream>
#include <deque>
using namespace std;

int main(){
	deque<int> numbers;	//name of the deque
	deque<int>::iterator numbers_i;	//iterator
	deque<int>::reverse_iterator rnumbers_i;	//reverse iterator

	//loads the even numbers into the front of the deque
	for(int a = 101; a >= 3; a--){
		a--;
		numbers.push_front(a);
	}
	//loads the odd numbers into the back of the deque
	for(int b=0; b<=98; b++){
		b++;
		numbers.push_back(b);
	}
	//prints out the deque
	cout << "The Deque Printed: " << endl;
	for(numbers_i = numbers.begin(); numbers_i!=numbers.end(); numbers_i++){
		cout << *numbers_i << " ";
	}
	cout << endl << endl;
	//prints out the deque in reverse order
	cout << "the deque print in reverse order: " << endl;
	for (rnumbers_i=numbers.rbegin(); rnumbers_i != numbers.rend(); rnumbers_i++){
		cout << *rnumbers_i << " ";
	}
	//calculates and prints the average of all values
	int temp =0, divide =1;
	for (numbers_i=numbers.begin(); numbers_i != numbers.end(); numbers_i++){
		temp = *numbers_i + temp;
		divide++;
	}
	temp = temp/divide;
	cout << "The average of all the values is: " << temp << endl << endl;
	system("pause");
	return 0;
}