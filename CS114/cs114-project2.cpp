#include <iostream>				//
using namespace std;            //
								//CS 114-003
								//Project 2
int main(){                

	int	cell, size, x_row, x_row_temp, size_temp,
		row, row_temp, cell_temp, matrix;

	cout << "Input numbers: ";
	cin >> cell >> size;

	size_temp = size;
	row = matrix = row_temp = cell_temp = cell;
	cout << endl;

	x_row_temp = x_row = cell * (size + 1);

	while(x_row>=0){
		cout << "X";
		x_row--;
	}

	cout << endl;
	while(matrix > 0){
		row=row_temp;
		while(row > 0){
			cell=cell_temp;
			while(cell > 0){
				cout << "X";
				size = size_temp;
				while(size>0){
					cout << " ";
					size--;
				}
				cell--;
			}
			cout << "X";
			row--;
			cout << endl;
		}
		x_row = x_row_temp;
		while(x_row>=0){
			cout << "X";
			x_row--;
		}
		cout << endl;
		matrix--;
	}

	cout << "\n";
	system("pause");

	return 0;
};