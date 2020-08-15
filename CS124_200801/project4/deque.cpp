
#include "deque.h"	//include deque header
#include "node.h"	//include node header

Deque::Deque(void){	//default constructor
    front=0; 
    back=0;
}

	
Deque::Deque(const Deque& a){	//copy constructor
    front=0;
    back=0;
    Node *temp=a.front;
    while(temp){	//continues copying items until null is reached
        pushback(temp->getData());
        temp=temp->getNext();
    }
}

	
Deque::~Deque(void){	//destructor
    Node *temp;
    while(front){	//deletes items in deque until null is reached
        temp=front;
        front = temp->getNext();
        delete temp;
    }
}


void Deque::pushfront(int e){		//pushes items in front of deque
    Node *newone = new Node(e,front,0);
    Node *temp = front;
    
    if (!front){	//creates front and back of deque if front not found
        front = newone;
        back = newone;
    }    
    else{
        temp->setPrev(newone);
        front = newone;
	}
}


void Deque::pushback(int e){		//pushes items in back of deque if back not found
    Node *newone = new Node(e,0,back);
    Node *temp=back;
    
    if (!back){	//creates front and back of deque
        front = newone;
        back = newone;
    }    
    else{
		temp->setNext(newone);
		back=newone;
	}
}


int Deque::popfront(){	//pops items out of the front of the deque
    Node *temp = front;
    int num;
    
    if(!front){	//if no item at the front of the deque, report to user
        cout << "Deque is empty"; 
        return 0;
    }    
    else 
    num = temp->getData();
    front = temp->getNext();
    delete temp;
    front->setPrev(0);
    return num;
}


int Deque::popback(){	//pops items out of the back of the deque
    Node *temp;
    int num;
    
    if (!back){	//if no item at the end of the deque, report to user
        cout << "Deque is empty"; 
        return 0;
    }
    
    else 
    temp = back;
    num = temp->getData();
    back = temp->getPrev();
    delete temp;
    back->setNext(0);
    return num;
}


bool Deque::isEmpty(void){	//checks to see if deque is empty, if so return false
	if (front){
		return false;
	}
	else{
		return true;
	}
}


int Deque::getSize(void){	//gets size of deque
    Node *temp = front;
    int count = 0;
    
    while(temp){	//continue counting items until end of deque is reached 
        temp = temp->getNext();
        count++;
    }        
    return count;
}


Deque& Deque::operator=(const Deque& a){	//definition for equal operator
    if (this==&a) 
    return *this;
    
    Node *temp;
    while(front){	//delete item at front of the deque
        temp = front;
        front = front->getNext();
        delete temp;
    }    
    back = 0;
    temp = a.front;
    while(temp){	//continue getting items until null is reached
        pushback(temp->getData());
        temp = temp->getNext();
    }    
    return *this;
}


ostream& operator<<(ostream& os, const Deque& a){	//definition for output operator
    os << "{ ";
    Node *temp = a.front;
    
    while(temp){	//continues outputting until null of deque is reached
		os << *temp << " ";
		temp = temp->getNext();
	}
	os << "}";
	return os;
}