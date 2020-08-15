/*


CS 124-002
Project 2
February 12, 2008
*/

#include "Collect.h"	//calls collect header file

Collect::Collect(){
	//default constructor

};
void Collect::setTitle(string ct){
	//sets the title of the collection	
	collection_name = ct;
};
int Collect::getMovieTotal(){
	//gets the total number of movies in the array
	return 0;
};
int Collect::getTotalTime(){
	//gets the total length of the movies in the array
	return 0;
};
string Collect::getTitle(){	
	//gets the title of the collection
	return collection_name;
};
ostream& operator<<(ostream& os, const Collect& m) {
	
	os << m.collection_name << endl;
	os << m.movie.getTitle() << ", " << m.movie.getDirector() << ", " << m.movie.getGenre() << ", " <<
		m.movie.getLength() << ", " << m.movie.getRating() << ", " << m.movie.getRelease() << endl;
	return os;
};