#if ! defined (TREENODE_H)
#define TREENODE_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "list.h"
using namespace std;

class TreeNode {
	string data;
	List booktitles;
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode( );
	TreeNode(string author);
	void addBook(string title, string publisher, string year, string pages);
	void printbooktitles();
	friend class List;
	friend class BinaryTree;
	friend ostream& operator<<(ostream&, const TreeNode&);
};
#endif