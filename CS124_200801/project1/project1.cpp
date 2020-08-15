/*


CS 124-002
Project 1
January 25, 2008
*/

#include <iostream>
#include <string>
using namespace std;

class Movie{
private:
	string director, title, genre, rating, release;	//declaring director, title, genre, rating, and release date
	int length;	//declaring length
	string cast_member[25];	//cast member array

public:
	//Contructors
	Movie();	//default constructor
	Movie(Movie&);	//copy constructor
	Movie(string, string, string, string, string, int);		//constructor with initialization list

	//Accessor Functions
	string getDirector (string director) const;	//gets the name of the director
	string getTitle (string title) const;	//gets the title of the movie
	string getGenre (string genre) const;	//gets the genre of the movie
	int getLength (int length) const;	//gets the length of the movie
	string getCast (string cast[]) const;		//gets the cast members of the movie
	string getRating (string rating) const;	//gets the rating of the movie
	string getRelease (string release) const;	//gets the release date of the movie
	
	//Mutator Functions
	void setDirector(string director);	//sets the director of the movie
	void setTitle(string title);		//sets the title of the movie
	void setGenre(string genre);		//sets the genre of the movie
	void setLength(int length);			//sets the length of the movie
	void setRating(string Rating);		//sets the rating of the movie
	void setRelease(string realeased);	//sets the release date of the movie

	//Operator Functions
	bool compareGenre(const Movie&);
	bool compareDirector(const Movie&);
	void show(const Movie&);
	void addCastMember(const Movie&);
	void trailer(const Movie&);
	void Critic(const Movie&);
};

//Constructors defined
Movie::Movie(){		//default constructor defined
};
Movie::Movie(Movie& r){		//copy constructor defined
}
Movie::Movie(string director, string title, string genre, string rating, string release, int length){	//custom constructor

	setDirector(director);
	setTitle(title);
	setGenre(genre);
	setRating(rating);
	setRelease(release);
	setLength(length);	
}

//Accessor Functions defined
string Movie::getDirector(string director) const{
	//gets name of the director of the movie
	return director;	
}
string Movie::getTitle(string title) const{
	//gets the title of the movie
	return title;
}
string Movie::getGenre(string genre) const{
	//gets the genre of the movie
	return genre;
}
int Movie::getLength(int length) const{
	//gets the length of the movie
	return length;
}
string Movie::getCast(string cast[]) const{
	//gets the cast members of the movie 
	return 0;
}
string Movie::getRating(string rating) const{
	//gets the rating of the movie
	return rating;
}
string Movie::getRelease(string release) const{
	//gets the release date of the movie
	return release;
}

//Mutator Functions defined
void Movie::setDirector(string mov_director){
	//sets the director of the movie
	director = mov_director;
}
void Movie::setTitle(string mov_title){
	//sets the title of the movie
	title = mov_title;
}
void Movie::setGenre(string mov_genre){
	//sets the genre of the movie
	genre = mov_genre;
}
void Movie::setLength(int mov_length){
	//sets the length of the movie
	length = mov_length;
}
void Movie::setRating(string mov_rating){
	//sets the rating of the movie
	rating = mov_rating;
}
void Movie::setRelease(string mov_release){
	//sets the relase date of the movie
	release = mov_release;
}


//Methods defined
bool Movie::compareGenre(const Movie& r){	//compares genre of two different movies; if equal returns true

	string m_genre = r.getGenre(genre);

	if (m_genre==m_genre){
		return true;
	}
	else{
		return false;
	}

/*
	Movie s;

	string genre1 = r.getGenre(genre);
	string genre2 = s.getGenre(genre);

	cout << "\nComparing Genres for " << r.getTitle(title) << " and " << s.getTitle(title) << ": ";
	if(genre1==genre2)
		return true;
	else
		return false;
		*/

}
bool Movie::compareDirector(const Movie& r){	//compares directors of two different movies; if equal returns true
	string	m_director = r.getDirector(director);
	string title_m=r.getTitle(title);

	if (m_director==m_director){
		return true;
	}
	return false;

	/*
	string director1=director;
	string director2 = r.getDirector(director);

	cout << "\nComparing Directors for " << r.getTitle(title) << " and " << ": ";
	if(director1==director2){
		cout << "returning true";
		return true;
	}
	else{
		cout << "returning false";
		return false;
	}
	*/
}
void Movie::Critic(const Movie& r){	//outputs the critic's response based upon the movie

	rating == r.getRating(rating);
	genre == r.getGenre(genre);

	cout << "Critic's Opinion: ";

	if(rating=="PG-13" && genre=="Comedy"){
		cout << "Not the best movie for younger audiences." << "\n" << endl;
	}
	else if(rating=="PG" && genre=="Comedy"){
		cout << "Kid friendly movie." << "\n" << endl;
	}
	else if(rating=="PG-13" && genre=="Drama"){
		cout << "It's worth seeing" << "\n" << endl;
	}
	else{
		cout << "Movie has not been criticized." << "\n" << endl;
	}
}
void Movie::show(const Movie& r){	//outputs movie title and length to screen
	int hours=0, minutes, total_length;

	minutes = r.getLength(length);	//gets movie and inputs it to minutes
	while(minutes>60){				//changes movie length in minutes to hours and minutes
		minutes = minutes-60;
		hours++;
	}

	cout << "\nMovie Title: " << r.getTitle(title) << endl;			//gets title
	cout << "Movie Length: " << hours << " Hr(s), " << minutes << " minutes" << endl;	//gets length
}
void Movie::trailer(const Movie& r){	//outputs information about the movie and trailer to screen
	double t_length;		//declares total length of trailer
	int mins=0, secs;			//length in minutes and seconds
	
	t_length = r.getLength(length);	//gets total length of movie and inputs to length of trailer

	t_length = t_length * 0.02;		//multiplies the total movie length by 2% to create trailer length

	secs = t_length*60;		//changes trailer length to seconds
	while(secs>60){			//changes trailer length from seconds to minutes and seconds
		secs = secs-60;
		mins++;
	}

	cout << "Trailer Length: " << mins << " Min(s), " << secs << " Sec(s)" << endl;
}
void Movie::addCastMember(const Movie & r){
	char input='n';		//sets input default value
	string cast_name;	//defines string for names to go into array
	int count=0, max_cast_num;	//initializes count to 0
	
	do{
		cout << "Need to add any cast members?(y/n) ";	//prompts for adding cast members
		cin >> input;	//user input for adding cast members

		if(input == 'y' || input == 'Y'){
			do{
				cout << "Enter the Cast Member name (first name only): ";	//prompts user for cast member first name
				cin >> cast_name;	//gets cast member first name
				
				cast_member[count] = cast_name;	//puts cast member name into array
				cout << "Added Cast Member: " << cast_name << endl;	//reports that cast member name has been added
				count++;	//increment number in array
		
				do{
					cout << "Add another cast member?(y/n) ";		//prompts for adding another cast member
					cin >> input;	//wait on user input 

					if(input == 'y' || input == 'Y' || input =='n' || input == 'N'){
					}
					else{
						cout << "Invalid selection! Please try again." << endl;
						input = 'i';
					};
				}while(input == 'i');

			}while(input == 'y' || input == 'y');
		}
		else if(input == 'n' || input == 'N'){
			//do nothing if user responds no
		}
		else{
			cout << "Invalid selection! Please try again." << endl;
			input = 'i';	//alert user of invalid choice
		}
	}while(input == 'i');

	if(count > 0){
		cout << "Cast Members are:" << endl;
		max_cast_num = count;
		do{
			cout << cast_member[count] << endl;
			count--;
		}while(count >= 0);
		cout << "Total Members: " << max_cast_num << endl;
	}
}



void main(){

	Movie a("David Talbert", "First Sunday", "Comedy", "PG-13", "2008", 98), 
		b("Francis Lawrence", "I Am Legend", "Drama", "PG-13", "2007", 101),
		c("Tim Hill", "Alvin and the Chimpmunks", "Comedy", "PG", "2007", 92),
		d("Jason Reitman", "Juno", "Comedy", "PG-13", "2007", 96);
	//calls constructor for objects of class
	
	cout << "Movie Information  -  Source: IMDB\n\n" << endl;
	a.show(a);	//display movie information about movie a
	a.trailer(a);	//display movie a trailer info
	a.Critic(a);	//critic's opinion of movie a
	a.addCastMember(a);

	b.show(b);	//display movie information about movie b
	b.trailer(b);	//display movie b trailer info
	b.Critic(b);	//critic's opinion of movie b
	b.addCastMember(b);

	c.show(c);	//display movie information about movie c
	c.trailer(c);	//display movie c trailer info
	c.Critic(c);	//critic's opinion of movie c
	c.addCastMember(c);

	d.show(d);	//display movie information about movie d
	d.trailer(d);	//display movie d trailer info
	d.Critic(d);	//critic's opinion of movie d
	d.addCastMember(d);



	cout << "\n\nMovie Director Comparison..." << endl;
	if (a.compareDirector(b))		//compares directors of movie a and b
		cout << "Same Director\n";
	else
		cout << "Different Directors\n";
	if(b.compareDirector(d))		//compares directors of movie a and c
		cout << "Same Director\n";
	else
		cout << "Different Directors\n";
	if(c.compareDirector(a))		//compares directors of movie b and c
		cout << "Same Director\n";
	else
		cout << "Different Directors\n";
	if(d.compareDirector(b))
		cout << "Same Director\n";
	else
		cout << "Different Directors\n";

	cout << "\n\nMovie Genre Comparison..." << endl;
	if (a.compareGenre(b))	//compares genre of movie a and b
		cout << "Same Genre\n";
	else
		cout << "Different Genres\n";
	if (b.compareGenre(d))	//compares genre of movie a and c
		cout << "Same Genre\n";
	else
		cout << "Different Genres\n";
	if (c.compareGenre(c))	//compares genre of movie b and c
		cout << "Same Genre\n";
	else
		cout << "Different Genres\n";
	if(d.compareDirector(b))
		cout << "Same Genre\n";
	else
		cout << "Different Genre\n";


	system("pause");	//requires user to press any key to continue
};