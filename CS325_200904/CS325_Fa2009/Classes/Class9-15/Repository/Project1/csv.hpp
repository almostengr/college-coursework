#ifndef __CSV__
#define __CSV__

#include <string>
#include <iostream>
using namespace std;

class CSV{
	
	private:
		string stockSymbol, time, symbolsFile;
		double value1, value2, value3, value4;
		int volume;

	public:
		void printStockSymbols();
		//prints one stock symbol per file
	
		void printDailyTotals();
		//prints the maximum and minimum value per stock per day
	
		void prettyPrint(string symbolFile);
		//opens the file symbol file and correlates the symbols in
		//your data. So, for some symbol, say APPL, you should 
		//print the long form of the name (Apple Inc.) and the
		//maximum price, the minimum price, and the volume.	void printVolume();
		//print all stock symbols, then a space, then the volume




};
#endif