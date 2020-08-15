#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class Track{
private:
	string title, artist;
	int plays;
public:
	Track(); //constructor for Track; need to only worry about initializing plays
	string getTitle(); //getter for the title of a track
	string getArtist(); //getter for the artist of a track
	int getPlayCount(); //getter for the play count of a track
	void setTrack(string t, string a, int p); //sets the track's title, artist, and play count
	void setTrack(Track tr); //sets one track equal to another (read: track s = track t)
	void print(); //print the attributes of a track:  title, artist, play count

};

int menu(); //prints a menu of options for the user.  There are 5 options: sort by title, sort by artist, sort by play count, party mix, and quit
void sortLibrary(Track t[], char c); //given an array of Tracks, sort by either title, artist, or play count.  The variable c dictates which one.
void partyMix(Track t[]); //print out a ten-Track party mix.  you may find the print() method in Track useful here.
void read(Track t[]); //read from library.txt and store in an array of Tracks
void printLibrary(Track t[]); //print entire contents of the library.  you may find the print() method in Track useful here.

void printLibrary(Track trak[]){
	for (count = 0; count<50; count	++){
		cout << title;
		cout << artist;
		cout << plays;

		cout << t[count];

		count++;
	}
}

void read(Track t[])

///opening file functions

string Track::getTitle(){
	return title;
}




void Track::setTrack(string t, string a, int p){

	title = t;
	artist = a;
	plays = p;

}


int main(){
	Track t[50];
	read(t);
	int menu_choice=menu();
	while(menu_choice!=5){
		switch(menu_choice){
			case 1: sortLibrary(t, 't');
				//sort the tracks by title
				break;
			case 2: sortLibrary(t, 'a');
				//sort the tracks by artist
				break;
			case 3: sortLibrary(t, 'c');
				//sort the tracks by play count
				break;
			case 4: partyMix(t);
				break;
		}
		if (menu_choice!=4) printLibrary(t);
		//print sorted library out, if a sort was called for...
		menu_choice = menu();
	}
	return 0;
}



