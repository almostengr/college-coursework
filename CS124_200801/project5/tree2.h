//#if ! defined (TREE_H)
//#define TREE_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "node.h"
using namespace std;

#ifndef TREE
#define TREE

class Tree {
	Tree *root;
	bool doInsert(string , string , Tree *);
	bool doInsertArtist(string , Tree *);
	bool doRemove (string , Tree*& );
	bool doFind(string , Tree* );
	bool doFindASong(string , string , Tree* );
	bool doFindPrint(string , Tree* );
	bool doFindRemoveSong(string , string , Tree* );
	void doPrintLibrary(Tree* );
	void doSearchLibrary(Tree* , string );
		int doHeight(Node*);

public:
	Tree( );
	void loadTree();
	bool insert(string , string );
	bool insertArtist(string );
	bool remove(Text);
	void printLibrary();
	void searchLibrary(string );
	void printArtist(string );

	friend ostream& operator <<(ostream&, const Tree&);

	bool find(Text );
	bool findASong(string , string );
	bool findPrint(string );
	bool findRemoveSong(string , string );
	int height(void);	//gets height of tree
};
#endif