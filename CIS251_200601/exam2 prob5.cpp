//
#include <iostream>
using namespace std;

struct ListNode					//start of NodePtred list
{
	int data;						//item in NodePtred list
	ListNode *NodePtr;				//points to next node in list
};								//end of NodePtred list 

typedef ListNode* NodePtr;		//definition of type
void Display_List(NodePtr head);

void main()
{
	Display_List(NodePtr head);
		
	system("pause");				//hold screen until key pressed
}//end of main()

void Display_List(NodePtr head)
{
		NodePtr mylist;		//equivalent to: Node *mylist;
for (mylist = head; mylist != NULL; mylist = mylist->NodePtr)
		cout << (mylist->data);			//displays all data in NodePtred list
}