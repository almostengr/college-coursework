#include "tree2.h"
#include "node.h"
#include "text.h"

bool Tree::doInsert(string name, string title, Tree *ptr) {
		if (ptr->data == name) {
			ptr->addSong(title);
			return false;
		}
		if (bigger(name, ptr->data) == true) {
			if (ptr->right) {
				return doInsert(name, title, ptr->right);
			}
			else {
				ptr->right = new Tree(name);
				ptr->right->addSong(title);
			}
		}
		else {
			if (ptr->left) {
				return doInsert(name, title, ptr->left);
			}
			else {
				ptr->left = new Tree(name);
				ptr->left->addSong(title);
			}
		}
		return true;
	}
bool Tree::doInsertArtist(string name, Tree *ptr) {
		if (ptr->data == name) {
			return false;
		}
		if (bigger(name, ptr->data) == true) {
			if (ptr->right) {
				return doInsertArtist(name, ptr->right);
			}
			else {
				ptr->right = new Tree(name);
			}
		}
		else {
			if (ptr->left) {
				return doInsertArtist(name, ptr->left);
			}
			else {
				ptr->left = new Tree(name);
			}
		}
		return true;
	}
bool Tree::doRemove (string name, Tree*& ptr) {
		if (ptr == 0) return false;
		if (bigger(ptr->data, name)) return doRemove(name, ptr->left);
		else {
            if (bigger(name, ptr->data)) return doRemove(name, ptr->right);
			else {
				if (ptr->left == 0) {
					Tree *temp = ptr;
					ptr = ptr->right;
					delete temp;
					return true;
				}
				else {
                    if (ptr->right == 0) {
						Tree *temp = ptr;
						ptr = ptr->left;
						delete temp;
						return true;
					}
					else {
						Tree *temp = ptr->left;
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
	Tree::Tree( ) : root(0) { }
	void Tree::loadTree() {
		string artist;
		string title;
		ifstream read;
		read.open("data.txt");
		while (!read.eof()) {		
			getline(read, artist);
			getline(read, title);
			insert(artist, title);
		}
		read.close();
	}
	bool Tree::insert(string name, string title) {
		if (root == 0) {
			root = new Tree(name);
			root->addSong(title);
			return true;
		}
		else {
			return doInsert(name, title, root);
		}
	}
	bool Tree::insertArtist(string name) {
		if (root == 0) {
			root = new Tree(name);
			return true;
		}
		else {
			return doInsertArtist(name, root);
		}
	}
	bool Tree::remove(string name) {
		if (root == 0) {
			return false;
		}
			else return doRemove(name, root);
	}
	void Tree::printLibrary() {
		doPrintLibrary(root);
	}
	void Tree::doPrintLibrary(Tree* n) {
		cout << "[" << endl;
		if (n->left) doPrintLibrary(n->left);
		cout << endl << n->data << ":" << endl << endl;
		n->printSongs();
		if (n->right) doPrintLibrary(n->right);
		cout << "]" << endl;
	}
	void Tree::searchLibrary(string song) {
		doSearchLibrary(root, song);
	}
	void Tree::doSearchLibrary(Tree* n, string song) {
		if (n->left) doSearchLibrary(n->left, song);
		if (n->songs.findSong(song)) {
			cout << n->data << endl;
		}
		if (n->right) doSearchLibrary(n->right, song);
	}
	void Tree::printArtist(string dude) {
		findPrint(dude);
	}

ostream& operator <<(ostream& os, const Tree& t) {
	os << "[" << endl;
	if (t.root) os << *(t.root);
	os << "]" << endl;
	return os;
}

	bool Tree::doFind(string dude, Tree* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == dude) {
			return true;}
		else if (bigger(dude, ptr->data) == true) return doFind(dude, ptr->right);
		else return doFind(dude, ptr->left);
	}
	bool Tree::doFindASong(string dude, string song, Tree* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == dude) {
			if (ptr->songs.findSong(song)) return true;
			else return false;
		}
		else if (bigger(dude, ptr->data) == true) return doFindASong(dude, song, ptr->right);
		else return doFindASong(dude, song, ptr->left);
	}
	bool Tree::doFindPrint(string dude, Tree* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == dude) {
			ptr->printSongs();
			return true;}
		else if (bigger(dude, ptr->data) == true) return doFindPrint(dude, ptr->right);
		else return doFindPrint(dude, ptr->left);
	}
	bool Tree::doFindRemoveSong(string dude, string song, Tree* ptr) {
		if (ptr == 0) {
			return false;}
		else if (ptr->data == dude) {
			ptr->songs.removeSong(song);
			return true;}
		else if (bigger(dude, ptr->data) == true) return doFindRemoveSong(dude, song, ptr->right);
		else return doFindRemoveSong(dude, song, ptr->left);
	}
	bool Tree::find(Tree dude) {
        Tree* temp = root;
		if (temp == 0) return false;
		else return doFind(dude, temp);
	}
	bool Tree::findASong(string dude, string song) {
        Tree* temp = root;
		if (temp == 0) return false;
		else return doFindASong(dude, song, temp);
	}
	bool Tree::findPrint(string dude) {
        Tree* temp = root;
		if (temp == 0) return false;
		else return doFindPrint(dude, temp);
	}
	bool Tree::findRemoveSong(string dude, string song) {
        Tree* temp = root;
		if (temp == 0) return false;
		else return doFindRemoveSong(dude, song, temp);
	}


	int Tree::height(void) {	//gets height of tree
	if (root == 0)
		return 0;
	else
		return doHeight(root);
}
int Tree::doHeight(Node *ptr) {	//returns height of tree
	if (ptr == 0)
		return 0;
	int leftHeight = doHeight(ptr->left);
	int rightHeight = doHeight(ptr->right);
	return 1 + max(leftHeight, rightHeight);
}
