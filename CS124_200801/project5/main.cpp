#include "tree.h"
#include <string>
using namespace std;

void main () {  //main testing all functions used throughout classes
	BinaryTree database;
	database.loadTree();

	int option=0;
	string search, search2;

	do{
		if(option == 1){
			cout << "Enter the name of the author: ";
			cin >> search;
			database.printAuthor(search);
			cout << endl << endl;
		}
		else if(option == 2){
			cout << "Enter the name of the author:";
			cin >> search;
			cout << "Enter the name of title of the book: ";
			cin >> search2;
			if((database.findAbooktitle(search, search2)) == true)
				database.printAuthor(search);
			else
				cout << "Search item not found." << endl << endl;
		}
		else if(option == 3){
			cin >> search;
			database.insertAuthor(search);
			cout << "Author added." << endl << endl;
		}
		else if(option == 4){
			cout << "Enter query to search for: " << endl;
			cin >> search;
			cout << "Searching library for " << search << endl;
			database.searchLibrary(search);
		}
		else if(option == 5){
			database.printLibrary();
		}
		else if(option == 0){	//exit option
		}
		else{
			cout << "Invalid option entered!  Please try again." << endl;
		}

		cout << "--Main Menu--" << endl << endl;
		cout << "1. Search Books by Author" << endl << "2. Search by Author and Title" << endl << "3. Add Author" << 
			endl << "4. Search Entire Library" << endl << "5. Print Library" << endl << "Enter 0 to exit." <<
			endl << endl << "Enter option:";

		cin >> option;

	}while(option != 0);
}