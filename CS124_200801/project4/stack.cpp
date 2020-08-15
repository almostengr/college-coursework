
#include "stack.h"	//include stack header
#include "node.h"	//include node header

Stack::Stack(){		//default constructor
    theTop = 0;
}


void Stack::push(int e){	//pushin new number into stack
    Node *newone = new Node(e, theTop);
    theTop = newone;
}


Stack::Stack(const Stack& a){	//copy constructor
    Stack tempstack;
    tempstack.theTop=0;
    Node *temp = a.theTop;
    while(temp){	//continues adding items to stack
        tempstack.push(temp->getData());
        temp = temp->getNext();
    } 
    theTop=0;
    temp = tempstack.theTop;
    while(temp){	//continues adding times to stack
        push(temp->getData());
        temp = temp->getNext();
    }
}


Stack::~Stack(){		//destructor
    Node *temp;
    while(theTop){	//delete items in stack until null is reached
        temp = theTop;
        theTop = temp->getNext();
        delete temp;
    }
}


int Stack::pop(void){	//pop items out of the stack
	Node *temp;    
    if(!theTop){	//if the top of the stack is not found, report to user 
        cout << "Stack is empty"; 
        return 0;
    }
	else
		temp = theTop;		//pops out items in stack
    theTop = temp->getNext();
    int num = temp->getData();
    delete temp;
    return num;
}


int Stack::top(void){ //find the top of the stack
    if(!theTop){
        cout << "Stack is empty"; 
        return 0;
    }
	else{
		return theTop->getData();
	}
}


bool Stack::isEmpty(void){	//checks to see if the stack is empty
	if(theTop){
		return false;
	}
	else{
		return true;
	}
}


Stack& Stack::operator=(const Stack& a){	//definition for the = operator
    if (this==&a) 
		return *this;
    
    Node *temp;
    if (!theTop){
        while (theTop){
            temp = theTop;
            theTop = theTop->getNext();
            delete temp;
        }
    }
    temp = a.theTop;
    while(temp){
        push(temp->getData());
        temp = temp->getNext();
    }
    return *this;
}


ostream& operator<<(ostream& os, const Stack& s){	//outputs the items in the stack
    os << "{ ";
    Node *temp = s.theTop;
    while(temp){
        os << *temp << " ";
        temp = temp->getNext();
    }
    os << "}";
    return os;
}