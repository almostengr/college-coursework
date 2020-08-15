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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Tree {
	Node *root;
	
	bool doInsert(int, Node*);
	int doHeight(Node*);
	bool doFind(int, Node*);
public:
	Tree();
	bool insert(int);
	int height(void);
	bool find(int);
	friend ostream& operator<<(ostream&, const Tree&);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Tree::Tree( ) : root(0) { }

bool Tree::insert(int e) {
	if (root == 0) {
		root = new Node(e);
		return true;
	}
	else
		return doInsert(e, root);
}
bool Tree::doInsert(int e, Node *ptr) {
	if (ptr->data == e)
		return false;
	if (ptr->data < e)
		if (ptr->right)
			return doInsert(e, ptr->right);
		else
			ptr->right = new Node(e);
	else
		if (ptr->left)
			return doInsert(e, ptr->left);
		else
			ptr->left = new Node(e);
	return true;
}

int Tree::height(void) {
	if (root == 0)
		return 0;
	else
		return doHeight(root);
}
int Tree::doHeight(Node *ptr) {
	if (ptr == 0) return 0;
	int leftHeight = doHeight(ptr->left);
	int rightHeight = doHeight(ptr->right);
	return 1 + max(leftHeight, rightHeight);
}

bool Tree::find(int e) {
	if(root==0)
		return 0;
	else 
		return doFind(e,root);
	//return true;
}
bool Tree::doFind(int e, Node *ptr) {
	if(ptr->data == e)
		return true;
	if(ptr ->data > e)
		if (ptr ->left != 0)
			return doFind (e, ptr->left);
		else
			return false;
	else
		if(ptr->right != 0)
			return doFind (e, ptr->right);
		else return false;
		//return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const Node& n) {
	if (n.left) os << *(n.left);
	os << n.data << " ";
	if (n.right) os << *(n.right);
	return os;
}

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
	t.insert(25);
	t.insert(10);
	t.insert(35);
	t.insert(40);
	t.insert(5);
	t.insert(20);
	t.insert(15);
	t.insert(50);
	t.insert(60);
	t.insert(55);
	t.insert(45);
	cout << t << endl << "\theight is : " << t.height() << endl;
	cout << "\t" << "First=" << t.find(45) << " Second=" << t.find(25) <<
		" Third=" << t.find(30) << " Forth=" << t.find(90) << endl;
	return 0;
}

/*	OUTPUTS

[ ]
[ 5 10 15 20 25 30 35 40 45 50 55 60 ]
        height is : 6
        First=1 Second=1 Third=1 Forth=0
Press any key to continue . . .

*/