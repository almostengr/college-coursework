

#ifndef STACK
#define STACK

#include <iostream>
#include "node.h"	//include node header
using namespace std;

class Stack{
    private:
        Node *theTop;	//node pointer to the top of stack         
    public:
        Stack();	//default constructor
        Stack(const Stack&);	//copy constructor
        ~Stack();	//destructor
        void push(int e);	//push items into stack
        int pop(void);	//pop items out of stack
        int top(void);	//goes to top of stack
        bool isEmpty(void);	//checks to see if stack is empty
        Stack& operator=(const Stack&);	//equal operator
        friend ostream& operator<<(ostream&, const Stack&);	//output operator
};
#endif

