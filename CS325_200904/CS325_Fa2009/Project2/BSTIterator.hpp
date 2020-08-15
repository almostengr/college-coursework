#include <iostream>
#include <stack>
#include <queue>
#include "Iterator.hpp"
#include "BST.hpp"
using namespace std;

template <class T>
class BST_PreOrder_Iterator: public Iterator <T> {

	stack<BSTNode<T>* > theStack;
	
	public:
		BST_PreOrder_Iterator(BST<T> *tree){
			theStack.push(tree -> getRoot());
			//get the root of the stack
		}


		bool hasMoreElements(){
			return !(theStack.empty());
			//continue if the stack is not empty
		}


		void next(){
			BSTNode<T> *temp = theStack.top();
			theStack.pop();

			if(temp -> getRightChild() != NULL){
			//get right item
				theStack.push(temp -> getRightChild());
			}

			if(temp -> getLeftChild() != NULL){
			//get left item
				theStack.push(temp -> getLeftChild());
			}
		}


		T getValue(){
			return theStack.top() -> getData();
		}

};



template <class T>
class BST_LevelOrder_Iterator: public Iterator <T> {

	queue<BSTNode<T>* > theQueue;


	public:
		BST_LevelOrder_Iterator(BST<T> *tree){
		//get the root of the queue
			theQueue.push(tree -> getRoot());
		}


		bool hasMoreElements(){
		//checks to see if the queue is empty
			return !(theQueue.empty());				
		}


		void next(){
			BSTNode<T> *temp = theQueue.front();
			theQueue.pop();

			if(temp -> getLeftChild() != NULL){
			//get the left item
				theQueue.push(temp -> getLeftChild());
			}

			if(temp -> getRightChild() != NULL){
			//get the right item
				theQueue.push(temp -> getRightChild());
			}
		}


		T getValue(){
			return theQueue.front() -> getData();
		}
};
