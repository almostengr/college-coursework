// Author:     Alan Cook
// Assignment: CIS 251
// File:       linklist.cpp
#include <iostream>
#include <iomanip>        // For setw()
#include <cstdlib>         // For system()
using namespace std;

struct Node
{
int data;
Node *next;
};

typedef Node* NodePtr ;// Used for pointer to head of list

// Linked-List Utility Functions

void display_list(NodePtr start);
Node *search(NodePtr start, int target);
void append(NodePtr& start, int value);
void insert_at_head(NodePtr& start, int value);
int delete_node(NodePtr& start, int target);
void insert(NodePtr& start, int value);

int  main()
// Parameters: None
// Returns:    Zero
{ 


NodePtr head = NULL;

cout <<  "Build Ordered List from this: " << endl;
for (int i = 10 ; i> 0 ; i--)
{
cout << i << endl;
insert(head,i);
}

cout <<  "Print List which is now in order" << endl;

display_list(head);
system("pause");

insert(head,15);

cout <<  "Insert 15" << endl;

display_list(head);
system("pause");

delete_node(head, 7);
cout <<  "Delete  7" << endl;

display_list(head);
system("pause");

insert(head,11);//
cout <<  "Insert 11" << endl;

display_list(head);
system("pause");

delete_node(head, 1);
cout <<  "Delete  1 at Head of List" << endl;

display_list(head);
system("pause");


insert(head,0);

cout <<  "Insert 0 at head of List" << endl;

display_list(head);
system("pause");


cout <<  "\n\n***** END OF PROGRAM ******\n";// Print closing message.    
return 0;
}  // End of main()                


void display_list(NodePtr start)
// Parameters: Pointer to start of List
// Returns   : None.                                                        
// Calls     : None.

{
while (start != NULL)
{
cout << start->data << endl;
start = start->next;
}
}

 
Node *search(NodePtr start, int target)
// Parameters: Pointer to start of List,value of record to be found
// Returns   : Pointer to target record if found                                                       
// Calls     : None.

{
NodePtr npointer;

npointer = start;
while (npointer->data != target && npointer != NULL)
npointer = npointer->next;

if (npointer->data = target)
return npointer;
else
return NULL;

}

void insert(NodePtr& start, int value)
// Parameters: Pointer to start of List,value of record to be inserted
// Returns   : None.                                                        
// Calls     : None.

{
NodePtr previous, current, newptr;

previous = current = start;

newptr = new Node;
newptr->data = value;

while ( current != NULL && value > current->data )
{
previous = current;
current = current->next;
}

if (current != start)
{
previous->next = newptr;
newptr->next = current;
}
else
{
newptr->next = start;
start = newptr;
}

}

void insert_at_head(NodePtr& start, int value)
// Parameters: Pointer to start of List,value of record to be added
// Returns   : None.                                                        
// Calls     : None.

{
NodePtr  newptr;

newptr = new Node;

newptr->data = value;
newptr->next = start;
start = newptr;
}

int delete_node(NodePtr& start, int target)
// Parameters: Pointer to start of List,value of record to be deleted
// Returns   : True if Successfully deleted                                                        
// Calls     : None.

{
NodePtr  current, previous;

current = start;
previous = start;

while (current->data != target && current != NULL)
{
previous = current;
current = current->next;
}

if (current->data == target)
{
if (current == previous) // Delete Head of list
start = current->next;
else
previous->next = current->next;
delete current;
return true;
}
else
return false;


}

 
void append(NodePtr& start, int value)
// Parameters: Pointer to start of List,value of record to be added at end of list
// Returns   : None.                                                        
// Calls     : None.
{  NodePtr    new_node = NULL; // Pointer to new record to be added
NodePtr    last       = NULL; // Pointer to last record in list

new_node = new Node;       // Allocate space for new record
if (new_node == NULL)
{   cout << "\aCan not allocate memory!";
exit(1);
}

new_node->data = value;              // Set value in allocated record
new_node->next = NULL;            // Set next field to NULL

if (start == NULL)                // If list is empty, add as 1st record
{   start = new_node;
}
else                                // Otherwise find end of list and add record there
{   last = start;                 // Find last record in list
while ( last->next != NULL)     // Last record's next field would be NULL
{   last = last->next;          // Move to next record,until reach last one
}
// Set next field of last record to  
last->next = new_node;        // point to new_record.
}
} // End of append()
