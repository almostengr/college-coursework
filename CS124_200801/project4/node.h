

#ifndef NODE
#define NODE

#include <iostream>
using namespace std;

class Node{
    private:
        int data;	//data in node
        Node *next;	//pointer for next node
        Node *prev;	//pointer for previous node    
    public:
        Node();	//default constructor
        Node(int);	//copy constructor
        Node(int, Node*);	//adds data and pointer to next node
        Node(int, Node*, Node*);	//adds data and pointer to previous and next node
        Node* getNext(void) const;	//gets next node
        Node* getPrev(void) const;	//gets previous node
        int getData(void) const;	//gets data in node
        void setData(int);	//sets data in node
        void setNext(Node*);	//sets pointer for next node
        void setPrev(Node*);	//sets pointer for previous node
        friend ostream& operator<<(ostream&, Node&);	//output stream operator 
};
#endif

