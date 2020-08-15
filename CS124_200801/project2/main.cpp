#include <iostream>
#include <string>
#include "Movie.h"
#include "Collect.h"

using namespace std;


int main() {
	Collect c1;
	c1.setTitle("BestofBest");
	Movie m1, m2, m3("John Ford", "Stagecoach", "Western", 96, "G", "1939");
	m1.set("David Lean", "Doctor Zhivago", "Historical", 200, "G", "1965" );
	m2.setDirector("John Avildsen");
	m2.setTitle("Rocky");
	m2.setGenre("Sports");
	m2.setLength(120);
	m2.setRating("G");
	m2.setRelease("1976");
	Movie m4(m2);
	cout << m4.getDirector() << " " << m4.getTitle() << " " <<  m4.getGenre() << " " << m4.getRating()<< endl; 
	Movie m5;
	cin >> m5;
	cout << m1 << m2 << m3 << m4 << m5;
	c1 + m1; // adds a Movie to the Collection c1
	cout << c1;
	c1 + m2; c1 + m3; c1 + m4; c1 + m5;
	cout << c1;
	c1 - m4;
	cout << c1;
	cout << "Movies in Collection: " << c1.getMovieTotal() << endl;
	cout << "Collection Title: " << c1.getTitle() << endl;
	cout << "Collection total run time: " << c1.getTotalTime() << endl;

	system("pause");
	return 0;
}