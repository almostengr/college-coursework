#include <iostream>
#include <string>
using namespace std;

#ifndef TEXT
#define TEXT

class Text{
	string title, author, publisher; //variable declarations
	int year, pages;
	bool status(int);
public:
	Text();	//default constructor
	Text(string, int, bool);
	//setter functions
	void setTitle(string);
	void setAuthor(string);
	void setPublisher(string);
	void setYear(int);
	void setPages(int);
	void setStatus(bool);

	//getter functions
	string getTitle();
	string getAuthor();
	string getPublisher();
	int getYear();
	int getPages();
	bool getStatus();

	
	friend class Tree;
	friend ostream& operator<<(ostream&, const Text&);
	
};

#endif 