#include <iostream>
#include <string>

using namespace std;

class Node {
	int data;
	Node *left;
	Node *right;
public:
	Node( ) : data(0), left(0), right(0) { }
	Node(int e) : data(e), left(0), right(0) { }
	friend class Tree;
	friend ostream& operator<<(ostream&, const Node&);
};

ostream& operator<<(ostream& os, const Node& n) {
	//post-order
	if (n.left)
		os << *(n.left);
	if (n.right)
		os << *(n.right);

	return os;
}

class Tree {
	Node *root;
	bool doInsert(int e, Node *ptr) {
		if (ptr->data == e) {
			cout << "\tNode " << e << " already exists in the tree" << endl;
			return false;
		}
		cout << "\tChecking to see if we should insert to the left or right of the current node " << ptr->data << endl;
		if (ptr->data < e) {
			cout << "\t\tLooking to the right side, " << e << " is greater than " << ptr->data << endl;
			if (ptr->right) {
				cout << "\t\t\tRecursively calling routine with right node " << (ptr->right)->data << endl;
				return doInsert(e, ptr->right);
			}
			else {
				cout << "\t\t\tNeed to insert to the right, nothing there, add new leaf node " << e << endl;
				ptr->right = new Node(e);
			}
		}
		else {
			cout << "\t\tLooking to the left side, " << e << " is less than " << ptr->data << endl;
			if (ptr->left) {
				cout << "\t\t\tRecursively calling routine with left node " << (ptr->left)->data << endl;
				return doInsert(e, ptr->left);
			}
			else {
				cout << "\t\t\tNeed to insert to the left, nothing there, add a new leaf node " << e << endl;
				ptr->left = new Node(e);
			}
		}
		return true;
	}
public:
	Tree( ) : root(0) { }
	bool insert(int e) {
		if (root == 0) {
			cout << "Inserting " << e << " into an empty tree" << endl;
			root = new Node(e);
			return true;
		}
		else {
			cout << "Inserting " << e << " into an existing tree with root " << root->data << endl;
			return doInsert(e, root);
		}
	}
	friend ostream& operator<<(ostream&, const Tree&);
};

ostream& operator<<(ostream& os, const Tree& t) {
	os << "[ ";
	if (t.root) os << *(t.root);
	os << "]";
	return os;
}




int main( ) {
	Tree t;
	cout << t << endl;
	t.insert(30);
	t.insert(20);
	t.insert(40);
	t.insert(10);
	t.insert(50);
	cout << t << endl;
	return 0;
}


/*	NOTES
shows how numbers are being entered into a tree. at the end it outputs the values within the tree.
it doesn't put 30 into the tree twice because it is already in it.  it uses an "in-order traversal"
*/

/*OUTPUT 
[ ]
Inserting 30 into an empty tree
Inserting 20 into an existing tree with root 30
Checking to see if we should insert to the left or right of the current
node 30
Looking to the left side, 20 is less than 30
Need to insert to the left, nothing there, add a new lea
f node 20
Inserting 40 into an existing tree with root 30
Checking to see if we should insert to the left or right of the current
node 30
Looking to the right side, 40 is greater than 30
Need to insert to the right, nothing there, add new leaf
node 40
Inserting 10 into an existing tree with root 30
Checking to see if we should insert to the left or right of the current
node 30
Looking to the left side, 10 is less than 30
Recursively calling routine with left node 20
Checking to see if we should insert to the left or right of the current
node 20
Looking to the left side, 10 is less than 20
Need to insert to the left, nothing there, add a new lea
f node 10
Inserting 50 into an existing tree with root 30
Checking to see if we should insert to the left or right of the current
node 30
Looking to the right side, 50 is greater than 30
Recursively calling routine with right node 40
Checking to see if we should insert to the left or right of the current
node 40
Looking to the right side, 50 is greater than 40
Need to insert to the right, nothing there, add new leaf
node 50
[ 10 20 30 40 50 ]
Press any key to continue . . .
*/