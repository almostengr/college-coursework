/*START HELP SECTION*/
#include <iostream>
using namespace std;

struct ListNode
{
	string item;				//item in list
	int count;				//item in list
	ListNode *link;			//points to next list item
}

typedef ListNode* ListNodePtr;		//definition type for struct
typedef name_of_struct* pointer_variable;

pointer_variable->member_name

/*END HELP SECTION*/

/*START DISPLAY OF ITEMS IN LINKED LIST - PAGE 745*/
/* 	displaying a linked list 
	to output the data in all the nodes in a linked  list*/
//
#include <iostream>
using namespace std;

struct ListNode					//start of linked list
{
	int data;						//item in linked list
	ListNode *link;				//points to next node in list
};								//end of linked list 

typedef ListNode* ListNodePtr;		//definition of type

void main()
{
	ListNodePtr mylist;		//equivalent to: Node *mylist;
	
	for (mylist = head; mylist != NULL; mylist = mylist->Link)
		cout << (mylist->data);			//displays all data in linked list
		
	system("pause");				//hold screen until key pressed
}//end of main()
/*END DISPLAY OF ITEMS IN LINKED LIST*/


/* START SEARCHING LINKED LIST - PAGE 743*/
NodePtr search(NodePtr head, int target);
{
here = head;
while (here->data != target && here -> != NULL)
	here = here -> link;
	
if(here->data == target)
	return here;
else
	return NULL;
}
/*END SEARCHING LINKED LIST */


/*START ADDING TO HEAD OF LINKED LIST - PAGE 739 */
void head_insert(NodePtr& head, int the_number);
{
	NodePtr temp_ptr;
	temp_ptr = new Node;
	
	temp_ptr->data = the_number;
	
	temp_ptr->link = head;
	head = temp_ptr;
}
/*END ADDING TO HEAD OF LINKED LIST */


/*START ADDING TO MIDDLE OF LINKED LIST - PAGE 747*/
void insert(NodePtr after_me, int the_number)
{
	NodePtr temp_ptr;
	temp_ptr = new Node;
	
	temp_ptr->data = the_number;
	
	temp_ptr->link = after_me->link;
	after_me->link = temp_ptr;
}
/*END ADDING TO MIDDLE OF LINKED LIST */