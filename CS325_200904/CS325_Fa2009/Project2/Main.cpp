#include <iostream>
#include <cstdlib>
#include "BST.hpp"
#include "BSTIterator.hpp"


using namespace std;

int main() {
    BST<int> tree;
/*
        5
    3       8
   2 4     7 9
  1       6
*/
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(8);
    tree.insert(7);
    tree.insert(6);
    tree.insert(9);
//  feel free to use other trees, however, I've given sample output for
//  this one in the README file. 

    //Test your iterators here.

	Iterator<int> *pre_OrderIt = new BST_PreOrder_Iterator<int> (&tree);

	while(pre_OrderIt -> hasMoreElements()){
	//continue if more elements are available

		cout << pre_OrderIt -> getValue() << ", "; //gets value
		pre_OrderIt ->  next();	//go to next item
	}

	cout << endl << endl;	//blank space



	Iterator<int> *level_OrderIt = new BST_LevelOrder_Iterator<int> (&tree);

	while(level_OrderIt -> hasMoreElements()){
	//continue if more elements are available

		cout << level_OrderIt -> getValue() << ", "; //gets value
		level_OrderIt -> next(); //go to next item
	}

	cout << endl << endl;	//blank space


    return 0;
}
