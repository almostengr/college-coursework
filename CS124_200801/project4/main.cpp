

#include "queue.h"	//header file for queue
#include "stack.h"	//header file for stack
#include "deque.h"	//header file for deque
#include <iostream>

int main(){
	Deque d; 
    Queue q;
    Stack s;
    
    int a;
	do{
		cout << "How many numbers, min of 2, would you like to add to each of "
			 << "the three containers" << endl << "(deque, queue, stack)? ";
		cin >> a;
		if(a<2){	//alert if number less than 2 is entered 
			cout << "Error!! Please try again" << endl << endl;
		}
	}while(a < 2);
	cout << "\nEnter " << a << " number(s) seperated by spaces: " << endl;
    int b, c = 0;
    while (c < a){
        cin >> b;
        d.pushfront(b);	//pushes number into front of deque
        q.enqueue(b);	//pushes number into back of queue
        s.push(b);		//pushes number into stack
        c++;
    }
    
    cout << endl << "Enter a number to add to the back of deque: ";
    int e;
    cin >> e;
    d.pushback(e);		//pushes number into back of deque
    
	cout << endl << "Deque contains: " << d << endl;	//outputs contents of deque
	cout << "Queue contains: " << q << endl;		//outputs contents of queue
	cout << "Stack contains: " << s << endl;		//outputs contents of stack
	cout << endl; 
	system("pause");		//pause for user to see information
    
    Deque d1=d, d2; 
    Queue q1(q), q2;
    Stack s1=s, s2;
    
    cout << "Now going to remove some of the elements from the copies..." << endl;
    d1.popfront();	//removes number from of deque
    q1.dequeue();		//removes number from queue
    s1.pop();		//removes number from stack
    
    cout << endl << endl << "Copies are now:" << endl
         << "Copy of the deque: " << d1 << endl		//shows contents of copy of deque
         << "Copy of the queue: " << q1 << endl		//shows contents of copy of queue
         << "Copy of the stack: " << s1 << endl << endl;	//shows contents of copy of stack

    d2=d1;
    q2=q1;
    s2=s1;
    
    cout << "Checking the copies for items..." << endl;
	if(d2.isEmpty()){	//reports whether deque is empty
		cout << "\nDeque is empty";
	}
    else{
		cout << "\nDeque is not empty";
	}
    
    if(q2.isEmpty()){	//reports whether queue is empty
		cout << "\nQueue is empty";
	}
    else{
		cout << "\nQueue is not empty";
	}	
    if(s2.isEmpty()){	//reports whether stack is empty
		cout << "\nStack is empty";
	}
    else{
		cout << "\nStack is not empty";
	}
    
    cout << "\n\n\nSome numbers of the originals:";
    cout << "\nSize of the deque: " << d.getSize();	//reports size of each container
    cout << "\nSize of the queue: " << q.getSize();
    cout << "\nTop of the stack: " << s.top() << endl;
}