#include <iostream>
using namespace std;

string maximum(string A[], int size){
	string max=A[0];

	for(int i=1; i<size; i++){
		if(A[i] > max){
			max = A[i];
		}
	}
	return max;

};


int main(){

	int C[4] = {"abc","xyz","hello","mnop"};
	cout << maximum(C,4);

	return 0;
}
