#include <iostream>
using namespace std;

template<typename T>
T maximum(T A[], int size){
	T max=A[0];

	for(int i=1; i<size; i++){
		if(A[i] > max){
			max = A[i];
		}
	}
	return max;

};


int main(){

	T C[4] = {"abc","xyz","hello","mnop"};
	cout << maximum(C,4);

	return 0;
}
