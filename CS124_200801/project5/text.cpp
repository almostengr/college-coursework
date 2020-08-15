#include "text.h"
/*
Text::Text() : title(""), author(""), publisher(""), year(0), pages(0), status(0) {}
Text::Text(string s, int i, bool b) : title(s), author(s), publisher(s), year(i), pages(i), status(b) {}
*/

Text::Text(){	//default contructor
	title="undefined";
	author="undefined";
	publisher="undefined";
	year=0;
	pages=0;
	status(0);
}
Text::Text(string s, int i, bool b){	//constructor
	title=s;
	author=s;
	publisher=s;
	year=i;
	pages=i;
	status(b);
}

//Setter Functions
void Text::setTitle(string s){
	title=s;
}
void Text::setAuthor(string s){
	author=s;
}
void Text::setPublisher(string s){
	publisher=s;
}
void Text::setYear(int i){
	year=i;
}
void Text::setPages(int i){
	pages=i;
}
void Text::setStatus(bool b){
	status(b);
}

//Accessor Functions
string Text::getTitle(){
	return title;
}
string Text::getAuthor(){
	return author;
}
string Text::getPublisher(){
	return publisher;
}
int Text::getYear(){
	return year;
}
int Text::getPages(){
	return pages;
}
bool Text::getStatus(){
	return 0;
}

//ostream& operator<<(ostream& os, const Text& t) {
//	os << t.title << ", " << t.author << ", " << t.publisher 
//		<< ", " << t.year << ", " << t.pages << ", " << t.status << endl;
//	return os;
//}