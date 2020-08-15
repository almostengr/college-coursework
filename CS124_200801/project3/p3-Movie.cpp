/*


CS 124-002
Project 2
February 12, 2008
*/

#include "Movie.h"	//calls movie header file

//Constructors defined
Movie::Movie(){		
	//default constructor defined.  sets strings to unknown and int to 0
	director = "unknown";
	title = "unknown";
	genre = "unknown";
	length = 0;
	rating = "unknown";
	release = "unknown";

};
Movie::Movie(Movie& r){	
	//copy constructor defined

	//gets movie information and puts it into a value 
	director = r.getDirector();	
	title = r.getTitle();
	genre = r.getGenre();
	length = r.getLength();
	rating = r.getRating();
	release = r.getRelease();

};
Movie::Movie(string d, string t, string g, int l, string ra, string re){
	//custom constructor
	
	//values inputed from constructor are put into a value
	director = d;
	title = t;
	genre = g;
	length = l;
	rating = ra;
	release = re;
}

//Accessor Functions defined
void Movie::set(string d, string t, string g, int l, string ra, string re){	//custom constructor

	//values inputed from constructor are put into a value
	director = d; 
	title = t;
	genre = g;
	length = l;
	rating = ra;
	release = re;
}
string Movie::getDirector() const{
	//gets name of the director of the movie
	return director;	
}
string Movie::getTitle() const{
	//gets the title of the movie
	return title;
}
string Movie::getGenre() const{
	//gets the genre of the movie
	return genre;
}
int Movie::getLength() const{
	//gets the length of the movie
	return length;
}
string Movie::getRating() const{
	//gets the rating of the movie
	return rating;
}
string Movie::getRelease() const{
	//gets the release date of the movie
	return release;
}

//Mutator Functions defined
void Movie::setDirector(string d){
	//sets the director of the movie
	director = d;
}
void Movie::setTitle(string t){
	//sets the title of the movie
	title = t;
}
void Movie::setGenre(string g){
	//sets the genre of the movie
	genre = g;
}
void Movie::setLength(int l){
	//sets the length of the movie
	length = l;
}
void Movie::setRating(string ra){
	//sets the rating of the movie
	rating = ra;
}
void Movie::setRelease(string re){
	//sets the relase date of the movie
	release = re;
}

//Friend operators
ostream& operator << (ostream& os, const Movie& m) {
	//outputs the information of the movies
	os << m.title << ", " << m.director << ", " << m.genre << ", " <<
		m.length << ", " << m.rating << ", " << m.release << endl;

	return os;
};
istream& operator >> (istream& is, Movie& m) {
	//input stream

	// input is in the format: director, title, genre, length, rating, release
	char ch;
	is >> ch; // read the " "
	is >> m.director;	//input the driector
	is >> ch; // read the " "
	is >> m.title;		//input the title of movie
	is >> ch; // read the " "
	is >> m.genre;	//input the genre
	is >> ch;
	is >> m.length;	//input the length of the movie
	is >> ch;
	is >> m.rating;	//input rating 
	is >> ch;
	is >> m.release;	//input of the release year

	return is;
};  
Movie operator + (Movie m){
	//definition of the + operator
	Movie temp;	//temporary variable
	int movie_number;	//sets array number to 0

	if(movie_number < -1){	//if number is not defined, then set to 0
		movie_number = 0;
	}

	temp.movie_array[movie_number];		//array of number into temp variable
movie_number++;
	return temp;	//return value
};
Movie operator - (Movie n){
	//definition of the - operator
	Movie temp;

	return temp;	//return value
};