#if ! defined (LIST_H)
#define LIST_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class List {
    list<string> strung;
public:
	bool findbooktitle(string title);
	void print();
	void removebooktitle(string title);
	void add(string title, string publisher, string year, string pages);
	friend class TreeNode;
	friend class BinaryTree;
};

bool bigger(string a, string b);
#endif