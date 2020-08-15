#include "Asserts.hpp"
#include "BST.hpp"
#include <iostream>

using namespace std;

// The following is just code that I used to fairly thoroughly test the binary
// tree that I've provided you.  You might consider testing your iterators in a
// similar fashion.
void testBST1() {
    BST<int> *tree = new BST<int>();
    AssertEquals(tree->getSize(), 0);
    
    tree->insert(5);
    AssertEquals(tree->getSize(), 1);
    AssertEquals(tree->root->getData(), 5);

    tree->insert(3);
    AssertEquals(tree->getSize(), 2);
    AssertEquals(tree->root->getData(), 5);
    AssertEquals(tree->root->getLeftChild()->getData(), 3);

    tree->insert(2);
    tree->insert(4);
    tree->insert(7);
    tree->insert(6);
    tree->insert(8);

    AssertEquals(tree->getSize(), 7);
    AssertEquals(tree->root->getData(), 5);
    AssertEquals(tree->root->getLeftChild()->getData(), 3);
    AssertEquals(tree->root->getLeftChild()->getRightChild()->getData(), 4);
    AssertEquals(tree->root->getRightChild()->getData(), 7);
    AssertEquals(tree->root->getRightChild()->getLeftChild()->getData(), 6);
    AssertEquals(tree->root->getRightChild()->getRightChild()->getData(), 8);

    AssertEquals(BSTNode<int>::_number_of_instances, 7);
    delete tree;
    AssertEquals(BSTNode<int>::_number_of_instances, 0);

    tree = new BST<int>(); 
    tree->insert(5);
    tree->insert(3);
    tree->insert(2);
    tree->insert(4);
    tree->insert(7);
    tree->insert(6);
    tree->insert(8);

    AssertEquals(BSTNode<int>::_number_of_instances, 7);

    AssertEquals(tree->root->getLeftChild()->getParent()->getData(), 5); 
    AssertEquals(tree->root->getLeftChild()->getLeftChild()->getParent()->getData(), 3); 
    AssertEquals(tree->root->getLeftChild()->getRightChild()->getParent()->getData(), 3); 

    tree->remove(8);
    tree->remove(6);

    AssertEquals(BSTNode<int>::_number_of_instances, 5);

    AssertEquals(tree->getSize(), 5);
    AssertEquals(tree->root->getRightChild()->getData(),7);

    tree->remove(7);

    tree->remove(5);

    AssertEquals(tree->root->getData(), 3);
    tree->remove(3);

    AssertEquals(tree->root->getData(), 4); 
    AssertEquals(tree->getSize(), 2); 
    AssertEquals(BSTNode<int>::_number_of_instances, 2); 
    delete tree;
    AssertEquals(BSTNode<int>::_number_of_instances, 0); 

}

int main() {	
    testBST1();
    cout << "Tests succeeded" << endl;    
    return 0;
}
