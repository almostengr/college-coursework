

#ifndef DEQUE
#define DEQUE

#include <iostream>
#include "node.h"	//include node header
using namespace std;

class Deque{	//class deque definition
    private:	
        Node *front;	//pointer to front of node
        Node *back;		//pointer to back of node        
    public:
        Deque(void);	//default constructor
        Deque(const Deque&);	//copy constructor
        ~Deque(void);	//destructor
        void pushfront(int);	//push items in front
        void pushback(int);		//push items in back
        int popfront();		//pop items out of front of deque
        int popback();		//pop items out of back of deque
        bool isEmpty(void);	//checks to see if deque is empty
        int getSize(void);	//gets size of deque
        Deque& operator=(const Deque&);	//equal operator
        friend ostream& operator<<(ostream&, const Deque&);	//friend output operator
};
#endif