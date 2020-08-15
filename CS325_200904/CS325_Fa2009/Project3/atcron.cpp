#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


class Task{
	public:
		Task();
		virtual ~Task();
		virtual void fire();
		virtual bool isTime(int sec);
		virtual	bool repeats();
};
		

int main(int argc, char** argv){
	
	//GETS LOCAL TIME
	struct tm *ptr;
	time_t t;
	t = time(NULL);
	ptr = localtime(&t);
	
	cout << ptr -> tm_sec << " seconds on " << ptr -> tm_wday << endl << endl;
	//the current seconds and day 


	vector<string> taskList;	//LIST OF ALL THE TASKS
	vector<string> taskAttributes;	//LIST OF THE ATTRIBUTES OF THE TASK


	if(argc > 0){
		//cout << "works" << endl;
		//prints "works" if there is greater than 1 parameter
	}


	//DECLARE INPUT FILE AND OPEN IT
	ifstream configuration;
	configuration.open(argv[1]);


	if(configuration.fail()){
		//IF OPENING OF CONFIGURATION FILE FAILS
		cout << "No configuration file specified." << endl;
		return 0;
	}

//taskList[1][3];
	string config_event;
	int i = 0;

	while(getline(configuration,config_event)){
	//READ IN TASKS FROM FILE

		//cout << config_event << endl;
		taskList.push_back(config_event);

		//cout << v[1] << endl;
	
	
		//cout << argv[1];
	
		configuration.close();
		//CLOSE CONFIGURATION FILE




		istringstream iss(taskList[i]);
		//SEPERATE THE PARTS OF THE VECTOR 1


		string iss_chunk;
		//DECLARE THE ISS CHUNK
		
		while(iss >> iss_chunk){
			
			//PUT THE ATTRIBUTES OF THE TASK INTO VECTOR 2 
			taskAttributes.push_back(iss_chunk);
					
		}

		i++;
	
	}

	


	return 0;
}
