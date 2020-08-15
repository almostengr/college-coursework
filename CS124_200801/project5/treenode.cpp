#include "treenode.h"
#include "tree.h"
#include "list.h"

	TreeNode::TreeNode( ) : data("Unknown Artist"), booktitles(List()), left(0), right(0) { }
	TreeNode::TreeNode(string author) : data(author), booktitles(List()), left(0), right(0) { }
	void TreeNode::addBook(string title, string publisher, string year, string pages) {
		booktitles.add(title, publisher, year, pages);
	}
	void TreeNode::printbooktitles() {
		booktitles.print();
	}

ostream& operator <<(ostream& os, const TreeNode& n) {
	if (n.left) os << *(n.left);
	os << endl << n.data << endl;
	if (n.right) os << *(n.right);
	return os;
}