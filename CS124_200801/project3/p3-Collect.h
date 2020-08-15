/*


CS 124-002
Project 2
February 12, 2008
*/

#include "Movie.h"		//calls movie header file
#ifndef COLLECT		//check for class definition
#define COLLECT		

class Collect {
	Movie movie;
	string collection_name;		//name of collection

public:
	//Constructors
	Collect();		//default constructor

	//Mutator Functions
	void setTitle(string ct);	//sets title of collection of movies
	
	//Accessor Functions
	int getMovieTotal();		//gets the total number movies
	int getTotalTime();			//total time of all movies
	string getTitle();			//gets title for collection of movies

	friend ostream& operator<<(ostream& os, const Collect&);	//output stream
};

#endif	//end of checking for class definition