#include <iostream>
using namespace std;

int main(){

	int	cell, size, xrow, xrow_temp, size_temp, row, row_temp, cell_temp, chart;

	cout << "number of cells";
	cin >> cell;
	cout << "Size of matrix ";
	cin >>  size;

	size_temp = size;
	row = chart = row_temp = cell_temp = cell;

	cout << endl;

	xrow_temp = xrow = cell * (size + 1);

	while(xrow>=0){
		cout << "X";
		xrow--;
	}
	cout << endl;
	while(chart > 0){
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
		xrow = xrow_temp;
		while(xrow>=0){
			cout << "X";
			xrow--;
		}
		cout << endl;
		chart--;
	}

	cout << "\n";
	system("pause");

	return 0;
}