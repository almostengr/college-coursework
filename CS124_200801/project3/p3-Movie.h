/*


CS 124-002
Project 2
February 12, 2008
*/

#include <iostream>
#include <string>
using namespace std;
#ifndef MOVIE	//check for class definiton
#define MOVIE

class Movie{
private:
	string director, title, genre, rating, release;	//declaring director, title, genre, rating, and release date
	int length;	//declaring length
	string movie_array[10];	//number of movies in the array

public:
	//Contructors
	Movie();	//default constructor
	Movie(Movie&);	//copy constructor
	Movie(string, string, string, int, string, string);	//constructor with initialization list

	//Accessor Functions
	string getDirector() const;	//gets the name of the director
	string getTitle() const;	//gets the title of the movie
	string getGenre() const;	//gets the genre of the movie
	int getLength() const;	//gets the length of the movie
	string getRating() const;	//gets the rating of the movie
	string getRelease() const;	//gets the release date of the movie
	
	//Mutator Functions
	void setDirector(string);	//sets the director of the movie
	void setTitle(string);	//sets the title of the movie
	void setGenre(string);	//sets the genre of the movie
	void setLength(int);	//sets the length of the movie
	void setRating(string);	//sets the rating of the movie
	void setRelease(string);	//sets the release date of the movie
	void set(string, string, string, int, string, string);	//constructor with initialization list

	friend ostream& operator<<(ostream& os, const Movie&);	//output stream
	friend istream& operator>>(istream& is, Movie&);	//input stream
	friend Movie operator+(Movie m);	//friend operator for adding movie
	friend Movie operator-(Movie n);	//friend operator for removing movie
};

#endif	//end of check for class definition