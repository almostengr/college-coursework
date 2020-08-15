

#include "queue.h"	//include stack header
#include "node.h"	//include node header

Queue::Queue(void){	//default constructor
    q = 0;
}


Queue::Queue(const Queue & a){	//copy constructor
    q=0;
    Node *temp = a.q;
        
	while (temp){	//continues copying items from previous queue until null is reached
        enqueue(temp->getData());
        temp = temp->getNext();
    }
}


Queue::~Queue(void){	//destructor
    Node *temp;
    while (q){	//delete all items in queue until null is reached
		temp=q;
        q = temp->getNext();
        delete temp;
    }
}


void Queue::enqueue(int e){	//creates new queue if one does not already exist
    Node *newone = new Node(e);
    
	if (q == 0){	//if queue does not exist, create a new one
		q = newone;
	}
    else{
        Node *temp = q;
		while (temp->getNext()){	//continue getting items in queue until null is reached
			temp = temp->getNext();
			temp->setNext(newone);
		}
    }
}


int Queue::dequeue(void){	
    if(!q){	//if queue is empty report back to user
        cout<<"Nothing in queue"; 
        return 0;
    }
    
    Node *temp = q;	//deletes item out of queue
    int num = temp->getData();
    q = temp->getNext();
    delete temp;
    return num;
}


bool Queue::isEmpty(void){	//if queue is empty return false
	if(q){
		return false;
	}
	else{
		return true;
	}
}


int Queue::getSize(void){	//gets size of queue
    Node *temp = q;
    int count = 0;
    
    while(temp){	//continue incrementing until null is reached
        count++;
        temp = temp->getNext();
    }    
    return count;
}


Queue& Queue::operator=(const Queue& a){	///equal operator
	if (this==&a){
		return *this;
	}
    
    Node *temp;
    while(q){	//continue getting items untill null is reached
        temp = q;
        q = q->getNext();
        delete temp;
    }    
    q = 0;
    temp = a.q;
    while(temp){	//continue adding items until null is reached
        enqueue(temp->getData());
        temp = temp->getNext();
    }    
    return *this;
}


ostream& operator<<(ostream& os, const Queue& q){	//output operator for items in queue
    os << "{ ";
    Node *temp = q.q;
    while(temp){	//continue outputting until null is reached
        os << *temp << " ";
        temp = temp->getNext();
    }    
    os << "}";
    return os;
}