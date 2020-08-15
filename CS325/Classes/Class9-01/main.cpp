#include <iostream>
using namespace std;

int maximum(int A[], int size){
	int max=A[0];

	for(int i=1; i<size; i++){
		if(A[i] > max){
			max = A[i];
		}
	}
	return max;

};


int main(){

	int B[5] = {10, 40, 20, 50, 30};
	cout << maximum(B,5);

	return 0;
}
