#include "tree.h"
#include "treenode.h"
#include "list.h"

bool BinaryTree::doInsert(string author, string title, string publisher, string year, string pages, TreeNode *ptr) {
		if (ptr->data == author) {
			ptr->addBook(title, publisher, year, pages);
			return false;
		}
		if (bigger(author, ptr->data) == true) {
			if (ptr->right) {
				return doInsert(author, title, publisher, year, pages, ptr->right);
			}
			else {
				ptr->right = new TreeNode(author);
				ptr->right->addBook(title, publisher, year, pages);
			}
		}
		else {
			if (ptr->left) {
				return doInsert(author, title, publisher, year, pages, ptr->left);
			}
			else {
				ptr->left = new TreeNode(author);
				ptr->left->addBook(title, publisher, year, pages);
			}
		}
		return true;
	}
bool BinaryTree::doinsertAuthor(string name, TreeNode *ptr) {
		if (ptr->data == name) {
			return false;
		}
		if (bigger(name, ptr->data) == true) {
			if (ptr->right) {
				return doinsertAuthor(name, ptr->right);
			}
			else {
				ptr->right = new TreeNode(name);
			}
		}
		else {
			if (ptr->left) {
				return doinsertAuthor(name, ptr->left);
			}
			else {
				ptr->left = new TreeNode(name);
			}
		}
		return true;
	}
bool BinaryTree::doRemove (string name, TreeNode*& ptr) {
		if (ptr == 0) return false;
		if (bigger(ptr->data, name)) return doRemove(name, ptr->left);
		else {
            if (bigger(name, ptr->data)) return doRemove(name, ptr->right);
			else {
				if (ptr->left == 0) {
					TreeNode *temp = ptr;
					ptr = ptr->right;
					delete temp;
					return true;
				}
				else {
                    if (ptr->right == 0) {
						TreeNode *temp = ptr;
						ptr = ptr->left;
						delete temp;
						return true;
					}
					else {
						TreeNode *temp = ptr->left;
						while (temp->right != 0) {
							temp = temp->right;
						}
                        ptr->data = temp->data;
						return doRemove(temp->data, ptr->left);
					}
				}
			}
		}
	}
	BinaryTree::BinaryTree( ) : root(0) { }
	void BinaryTree::loadTree() {
		string author, title, publisher, year, pages;
		ifstream read;
		read.open("data.txt");
		while (!read.eof()) {	
			getline(read, title);	
			getline(read, author);
			getline(read, publisher);
			getline(read, year);
			getline(read, pages);
			insert(author, title, publisher, year, pages);
		}
		read.close();
	}
	bool BinaryTree::insert(string author, string title, string publisher, string year, string pages) {
		if (root == 0) {
			root = new TreeNode(author);
			root->addBook(title, publisher, year, pages);
			return true;
		}
		else {
			return doInsert(author, title, publisher, year, pages, root);
		}
	}
	bool BinaryTree::insertAuthor(string name) {
		if (root == 0) {
			root = new TreeNode(name);
			return true;
		}
		else {
			return doinsertAuthor(name, root);
		}
	}
	bool BinaryTree::remove(string author) {
		if (root == 0) {
			return false;
		}
			else return doRemove(author, root);
	}
	void BinaryTree::printLibrary() {
		doPrintLibrary(root);
	}
	void BinaryTree::doPrintLibrary(TreeNode* n) {
		//cout << "[" << endl;
		if (n->left) doPrintLibrary(n->left);
		cout << endl << n->data << ":" << endl;
		n->printbooktitles();
		if (n->right) doPrintLibrary(n->right);
		//cout << "]" << endl;
	}
	void BinaryTree::searchLibrary(string booktitle) {
		doSearchLibrary(root, booktitle);
	}
	void BinaryTree::doSearchLibrary(TreeNode* n, string booktitle) {
		if (n->left) doSearchLibrary(n->left, booktitle);
		if (n->booktitles.findbooktitle(booktitle)) {
			cout << n->data << endl;
		}
		if (n->right) doSearchLibrary(n->right, booktitle);
	}
	void BinaryTree::printAuthor(string author) {
		findPrint(author);
	}
	void BinaryTree::printAuthor2(ifstream data){
		cout << data;
	}

ostream& operator <<(ostream& os, const BinaryTree& t) {
	os << "[" << endl;
	if (t.root) os << *(t.root);
	os << "]" << endl;
	return os;
}

	bool BinaryTree::doFind(string author, TreeNode* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == author) {
			return true;}
		else if (bigger(author, ptr->data) == true) return doFind(author, ptr->right);
		else return doFind(author, ptr->left);
	}
	bool BinaryTree::doFindAbooktitle(string author, string booktitle, TreeNode* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == author) {
			if (ptr->booktitles.findbooktitle(booktitle)) return true;
			else return false;
		}
		else if (bigger(author, ptr->data) == true) return doFindAbooktitle(author, booktitle, ptr->right);
		else return doFindAbooktitle(author, booktitle, ptr->left);
	}
	bool BinaryTree::doFindPrint(string author, TreeNode* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == author) {
			ptr->printbooktitles();
			return true;}
		else if (bigger(author, ptr->data) == true) return doFindPrint(author, ptr->right);
		else return doFindPrint(author, ptr->left);
	}
	bool BinaryTree::doFindRemovebooktitle(string author, string booktitle, TreeNode* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == author) {
			ptr->booktitles.removebooktitle(booktitle);
			return true;}
		else if (bigger(author, ptr->data) == true) return doFindRemovebooktitle(author, booktitle, ptr->right);
		else return doFindRemovebooktitle(author, booktitle, ptr->left);
	}
	bool BinaryTree::find(string author) {
        TreeNode* temp = root;
		if (temp == 0) return false;
		else return doFind(author, temp);
	}
	bool BinaryTree::findAbooktitle(string author, string booktitle) {
        TreeNode* temp = root;
		if (temp == 0) return false;
		else return doFindAbooktitle(author, booktitle, temp);
	}
	bool BinaryTree::findPrint(string author) {
        TreeNode* temp = root;
		if (temp == 0) return false;
		else return doFindPrint(author, temp);
	}
	bool BinaryTree::findRemovebooktitle(string author, string booktitle) {
        TreeNode* temp = root;
		if (temp == 0) return false;
		else return doFindRemovebooktitle(author, booktitle, temp);
	}
