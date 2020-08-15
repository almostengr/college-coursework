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
	bool insert(int);
	bool remove(int);
	int height(void);
	bool find(int);
	friend ostream& operator<<(ostream&, const Tree&);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Tree::Tree( ) : root(0) { }

Tree::Tree(const Tree& t) {
	root = 0;
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
	cout << "Removing " << e << " from " << *this << endl;
	if (root == 0)
		return false;
	else
		return doRemove(e, root);
}
bool Tree::doRemove(int e, Node*& ptr) {
	cout << "\tin doRemove, value to remove is " << e << ", current pointer is " << ptr;
	if (ptr != 0) cout << ", value is " << ptr->data << endl; else cout << endl;
	if (ptr == 0) return false;
	if (e < ptr->data)
		return doRemove(e, ptr->left);
	else
		if (e > ptr->data)
			return doRemove(e, ptr->right);
		else
			if (ptr->left == 0) { // only has a right child (at most), just update to right child (which might be NULL
				cout << "\t\tremoving a node with no left child" << endl;
				Node *temp = ptr;
				ptr = ptr->right;
				delete temp;
				cout << "\t\tleaving doRemove, ptr is now " << ptr << endl;
				return true;
			}
			else
				if (ptr->right == 0) { // only has a left child, just update to right child
					cout << "\t\tremoving a node with only a left child" << endl;
					Node *temp = ptr;
					ptr = ptr->left;
					delete temp;
					cout << "\t\tleaving doRemove, ptr is now " << ptr << endl;
					return true;
				}
				else {
					cout <<"\t\tremoving a node with two children" << endl;
					Node *temp = ptr->left;
					while (temp->right != 0)
						temp = temp->right;
					ptr->data = temp->data;
					cout << "\t\tleaving doRemove, ptr is now " << ptr << endl;
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
	return 0;
}
/*	INITIAL TREE
				30
			   /   \
			20		50 - 60
			/		|
		   10		40		
		   /
		  5


	TREE AFTER RUN
				
				30
			   /  \
			  10   40 - 60
*/

/*OUTPUT 

[ 5(00334468) 10(00332EA0) 20(00332E88) 30(00332E70) 40(00332ED0) 50(00332EB8) 6
0(00334450) ]
Removing 5 from [ 5(00334468) 10(00332EA0) 20(00332E88) 30(00332E70) 40(00332ED0
) 50(00332EB8) 60(00334450) ]
        in doRemove, value to remove is 5, current pointer is 00332E70, value is
 30
        in doRemove, value to remove is 5, current pointer is 00332E88, value is
 20
        in doRemove, value to remove is 5, current pointer is 00332EA0, value is
 10
        in doRemove, value to remove is 5, current pointer is 00334468, value is
 5
                removing a node with no left child
                leaving doRemove, ptr is now 00000000
Removing 20 from [ 10(00332EA0) 20(00332E88) 30(00332E70) 40(00332ED0) 50(00332E
B8) 60(00334450) ]
        in doRemove, value to remove is 20, current pointer is 00332E70, value i
s 30
        in doRemove, value to remove is 20, current pointer is 00332E88, value i
s 20
                removing a node with only a left child
                leaving doRemove, ptr is now 00332EA0
Removing 50 from [ 10(00332EA0) 30(00332E70) 40(00332ED0) 50(00332EB8) 60(003344
50) ]
        in doRemove, value to remove is 50, current pointer is 00332E70, value i
s 30
        in doRemove, value to remove is 50, current pointer is 00332EB8, value i
s 50
                removing a node with two children
                leaving doRemove, ptr is now 00332EB8
        in doRemove, value to remove is 40, current pointer is 00332ED0, value i
s 40
                removing a node with no left child
                leaving doRemove, ptr is now 00000000
[ 10(00332EA0) 30(00332E70) 40(00332EB8) 60(00334450) ]
Press any key to continue . . .

*/