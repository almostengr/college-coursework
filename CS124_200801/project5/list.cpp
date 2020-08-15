#include "list.h"
#include "treenode.h"
#include "tree.h"

	bool List::findbooktitle(string title) {
		bool thing = false;
		for (list<string>::iterator i = strung.begin(); i != strung.end(); i++) {
			if (*i == title) {
				thing = true;
				return thing;
			}
		}
		return thing;
	}
	void List::print() {
		for (list<string>::iterator i = strung.begin(); i != strung.end(); i++) {
			cout << *i << endl;
		}
	}
	void List::removebooktitle(string title) {
		strung.remove(title);
	}
	bool bigger(string a, string b) {
		bool grand = false;
		int length_of_a, length_of_b;
		length_of_a = a.length();
		length_of_b = b.length();
		for (int n = 0; n < length_of_a && n < length_of_b; n++) {
			if (a.at(n) > b.at(n)) {
				grand = true;
				return grand;
			}
			if (a.at(n) < b.at(n)) return grand;
		}
		return a.length() < b.length();
	}
	void List::add(string title, string publisher, string year, string pages) {
		for (list<string>::iterator i = strung.begin(); i != strung.end(); i++) {
			if (bigger(*i, title)) {
				strung.insert(i, title);
				return;
			}
		}
		strung.push_front(title);
	}
