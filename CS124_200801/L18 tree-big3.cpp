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
	bool doRemove(int, Node*&);
	int doHeight(Node*);
	void doConstructor(Node*);
	void doDestructor(Node*);
	bool doFind(int, Node*);
public:
	Tree();
	Tree(const Tree&);
	~Tree();
	Tree& operator=(const Tree&);
	bool insert(int);
	bool remove(int);
	int height(void);
	bool find(int);
	friend ostream& operator<<(ostream&, const Tree&);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tree& Tree::operator =(const Tree& t){
if (this == &t)
	return *this;
if (root != 0)
	doDestructor(root);
root = 0;
if(t.root != 0)
	doConstructor(t.root);
return *this;
}
Tree::Tree( ) : root(0) { }

Tree::Tree(const Tree& t) {
	root = 0;
	if (t.root != 0)
		doConstructor(t.root);
}
void Tree::doConstructor(Node *ptr) {
	insert(ptr->data);
	if (ptr->left)
		doConstructor(ptr->left);
	if (ptr->right)
		doConstructor(ptr->right);
}

Tree::~Tree( ) {
	if (root != 0) doDestructor(root);
}
void Tree::doDestructor(Node *ptr) {
	if (ptr->left) doDestructor(ptr->left);
	if (ptr->right) doDestructor(ptr->right);
	delete ptr;
}
/*
Tree& Tree::operator=(const Tree& t) {
	Node *ptr;
	// make sure the user is not doing "t1 = t1;"


	// destroy the original tree (if root is not null)
	ptr = root;

	// initialize our tree to an empty tree (root is null)
	root = 0;
	// copy over the new tree (if there is something in it)
	ptr = t.root;


	// return the newly copied tree
	return *this;
}
*/
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

bool Tree::remove(int e) {
	if (root == 0)
		return false;
	else
		return doRemove(e, root);
}
bool Tree::doRemove(int e, Node*& ptr) {
	if (ptr == 0) return false;
	if (e < ptr->data)
		return doRemove(e, ptr->left);
	else
		if (e > ptr->data)
			return doRemove(e, ptr->right);
		else
			if (ptr->left == 0) { // only has a right child (at most), just update to right child (which might be NULL
				Node *temp = ptr;
				ptr = ptr->right;
				delete temp;
				return true;
			}
			else
				if (ptr->right == 0) { // only has a left child, just update to right child
					Node *temp = ptr;
					ptr = ptr->left;
					delete temp;
					return true;
				}
				else {
					Node *temp = ptr->left;
					while (temp->right != 0)
						temp = temp->right;
					ptr->data = temp->data;
					return doRemove(temp->data, ptr->left);
				}

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
	if (root == 0) 
		return 0;
	else
		return doFind(e, root);
}
bool Tree::doFind(int e, Node *ptr) {
	if (ptr->data == e) return true;
	if (ptr->data > e)
		if (ptr->left != 0) return doFind(e, ptr->left);
		else return false;
	else
		if (ptr->right != 0) return doFind(e, ptr->right);
		else return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const Node& n) {
	if (n.left) os << *(n.left);
	os << n.data << "(" << &n << ") ";
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
	t.insert(30);
	t.insert(20);
	t.insert(10);
	t.insert(50);
	t.insert(40);
	t.insert(60);
	t.insert(5);
	cout << t << endl;
	t.remove(5);
	t.remove(20);
	t.remove(50);
	cout << t << endl;
	cout << "testing assignmnt operator" << endl;
	Tree t2;
	t2.insert(100);
	t2 = t;
	cout << t2 << endl;
	t2.remove(60);
	cout << t2 << endl;
	return 0;
}


/*OUTPUT 

[ 5(00334468) 10(00332EA0) 20(00332E88) 30(00332E70) 40(00332ED0) 50(00332EB8) 6
0(00334450) ]
[ 10(00332EA0) 30(00332E70) 40(00332EB8) 60(00334450) ]
testing assignmnt operator
[ 10(00332E88) 30(00332ED0) 40(00334468) 60(00334508) ]
[ 10(00332E88) 30(00332ED0) 40(00334468) ]
Press any key to continue . . .

*/