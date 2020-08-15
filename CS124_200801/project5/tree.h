#if ! defined (TREE_H)
#define TREE_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "treenode.h"
using namespace std;

class BinaryTree {
	TreeNode *root;
	bool doInsert(string name, string title, string publisher, string year, string pages, TreeNode *ptr);
	bool doinsertAuthor(string name, TreeNode *ptr);
	bool doRemove (string name, TreeNode*& ptr);
	bool doFind(string author, TreeNode* ptr);
	bool doFindAbooktitle(string author, string booktitle, TreeNode* ptr);
	bool doFindPrint(string author, TreeNode* ptr);
	bool doFindRemovebooktitle(string author, string booktitle, TreeNode* ptr);
	void doPrintLibrary(TreeNode* n);
	void doSearchLibrary(TreeNode* n, string booktitle);

public:
	BinaryTree( );
	void loadTree();
	bool insert(string name, string title, string publisher, string year, string pages);
	bool insertAuthor(string name);
	bool remove(string author);
	void printLibrary();
	void searchLibrary(string booktitle);
	void printAuthor(string author);
	void printAuthor2(ifstream);

	friend ostream& operator <<(ostream&, const BinaryTree&);

	bool find(string author);
	bool findAbooktitle(string author, string booktitle);
	bool findPrint(string author);
	bool findRemovebooktitle(string author, string booktitle);
};
#endif