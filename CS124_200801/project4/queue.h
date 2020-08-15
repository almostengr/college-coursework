
#ifndef QUEUE
#define QUEUE

#include <iostream>
#include "node.h"	//include node header
using namespace std;

class Queue{
    private:
        Node *q;	//node pointer for queue        
    public:
        Queue(void);	//default constructor
        Queue(const Queue&);	//copy constructor
        ~Queue(void);	//destructor
        void enqueue(int);	
        int dequeue(void);
        bool isEmpty(void);	//checks to see if deque is empty
        int getSize(void);	//returns size of deque
        Queue& operator=(const Queue&);	//equal operator
        friend ostream& operator<<(ostream&, const Queue&);	//output operator
};
#endif


