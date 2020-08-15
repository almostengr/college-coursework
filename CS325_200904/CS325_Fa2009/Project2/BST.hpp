#ifndef __BST_HPP__
#define __BST_HPP__

// This is just a stub for the class BST.  Notice that it's templated.
template <class T>
class BST;


// BSTNode is templated so that we can use varying types of data (int, string,
// etc.)  Since it's a node for a binary search tree it has pointers to the two
// children -- left and right -- and also to its parent.  

template <class T>
class BSTNode {
    // The data that this node holds.  Templated to that it can be many types.
    T data;
    
    // Note this is templated.  We want our tree to be homogeneous.  That is we
    // want all of the nodes in the tree to have data of the same time (int,
    // string, etc.)
    BSTNode<T> *left, 
               *right, 
               *parent;
public:
    // You may ignore this if you want.  This is just used to count how many
    // objects of class BSTNode are currently extant.  I use it to detect memory
    // leaks.
    static int _number_of_instances;

    // This constructor takes a value of type T.  It doesn't really make sense
    // to create a node without a value, so it's safe to only include this
    // constructor.
    BSTNode(T d) {
        this->data = d;
        this->left = this->right = this->parent = 0;
         
        // We've created a new instance of the node, so go ahead and add one to
        // the counter.
        _number_of_instances ++;
    }

    // The destructor gets called whenever the someone explicitly calls delete
    // or when the node is freed from the stack.
    ~BSTNode() {
        // Since we're in the destructor, it means that we're done with our
        // object.  Thus, since the object is no longer in use, let's decrement
        // the counter by one. 
        _number_of_instances --;
    }


    // This method has the return type T and just returns the data which is in
    // the node.  We could have omitted all of the accessors if we made all of
    // our member variables public, but that's not good practice.
    T getData() {
        return data;
    }

    // Note that the return type is BSTNode<T>*.  We're returning a pointer to
    // not just a BSTNode, but to a very specific one -- one of type T.
    BSTNode<T> *getLeftChild() {
        return left;
    }
    
    // Same as above.
    BSTNode<T> *getRightChild() {
        return right;
    }

    // Same as above.
    BSTNode<T> *getParent() {
        return parent;
    }

    // Since BSTNodes are used primarily by a BST, we might as well allow the
    // BST to have access to our private member variables.  Note that BST is
    // templated here.  This is because we want to grant friendship to the
    // specific BST which is of type T
    friend class BST<T>;
};

// This is how you initialize a static variable.  You cannot do it in the
// constructor because that would set the value of the counter to zero every
// time a new object of type BSTNode was created.  So, we can do it anywhere
// outside of the class.  Note that this is templated as well.  Thus there will
// be a counter for each and every type of BSTNode that we create.
template <class T>
int BSTNode<T>::_number_of_instances = 0;




// This is the definition of the class BST (Binary Search Tree).  Note that it
// is templated.  This is because we want to be able to create trees which
// contain ints, or strings, etc.
template <class T>
class BST {
    // A BST must contain a pointer to the root of the tree.  Note that this
    // BSTNode it of type T.  Since out tree is specialized to only hold values
    // of type T, we need only point to nodes of type T.
    BSTNode<T> *root;

    // This holds how many elements are in the tree.
    int size;

    // This helper is used when inserting elements.  Recall that a binary search
    // tree has the very specific property that given some node N, all of the
    // elements in the left subtree of N have value less than N, and all of the
    // elements in the right subtree of N have values greater than or equal to
    // N.  insertHelper is used to ensure that this property is upheld.
    //
    // Note that first we take in a pointer to a templated BSTNode.  This
    // pointer is of the subtree in which we should look for the appropriate
    // place to put the value 'v' which is of type T.
    void insertHelper(BSTNode<T> *n, T v) {
        T value = n->data;
        BSTNode<T> *subtree;

        // If the 'v' (the value we're trying to add to the tree) is less than
        // 'value' which is the value of the current node, then we know based on
        // the BST property that we must insert our new node somewhere to the
        // left of this node.
        if(v < value) {

            // If there was no left child of this node, then we can just insert
            // our new value here.
            if(n->left == 0) {

                // This creates a new BSTNode (note the templated type).
                BSTNode<T> *newNode = new BSTNode<T>(v);

                // We add the pointer to this new node.
                n->left = newNode;

                // We update the parent pointer of the new node.  Parent
                // pointers are used almost exclusively to aid in the removal
                // process.
                newNode->parent = n;

                // Since we've added a new node, our tree is larger, so
                // increment its size by one.
                size++;
                return;
            }

            // If we get here then we know that our new node should go somewhere
            // to the left of the current node.  So, we say that the subtree
            // we're going to look in next is the left of this node.
            subtree = n->left;
        } else {
            // If we get here it must be the case that our new value is either
            // greater than or equal to the value of the node we're looking at
            // right now.

            // If our current node has no right children, then let's put the new
            // node here. 
            if(n->right == 0) {
                // Same as for the left case, but we change the right pointer
                // inststead.
                BSTNode<T> *newNode = new BSTNode<T>(v);
                n->right = newNode;
                newNode->parent = n;
                
                size++;
                return;
            }    

            // Just as with the left case, if we get here it means that out new
            // node should go somewhere to the right of this node.  So we're
            // going to look in its right subtree.
            subtree = n->right;
        }

        // Since we got here, it means that we didn't successfully add our
        // element yet, so we need to keep looking.  'subtree' has the correct
        // place to start looking for a place to put the new value, so let's
        // just recurse.
        insertHelper(subtree, v);
    }

    // This function is used to help the destructor recursively delete the tree.
    // Note that it takes a single BSTNode pointer as a paramter.  This is the
    // root of the current subtree we're deleting.
    void destructorHelper(BSTNode<T> *n) {
        // If the pointer is null, then there's no point in deleting anything.
        if(n) {

            // If the node we're looking at has a left subtree, then recursively
            // delete that before proceeding.
            if(n->left) destructorHelper(n->left);

            // Similarly, for the right.
            if(n->right) destructorHelper(n->right);
            
            // When we get here we know that all of the left and right subtrees
            // have been deleted, so we may remove our pointers to them.
            n->left = n->right = n->parent = 0;

            // Since there is no need for our current node any longer, then
            // delete it.
            delete n;
        }
    }

    // removeNode is a helper function for the remove(T v) method.  Its
    // responsibility is to just prune the node from the tree.  Tree reordering
    // takes place inside of the remove(T v) function.
    void removeNode(BSTNode<T>* n) {
        
        // Since this method is private we know that it's only being called by
        // remove(T v).  So, we know that 'n' is not null.  Otherwise it would
        // be unsafe to proceed without checking.

        // We're make the tree smaller, so decrement it's size by one.
        size --;

        // If the current node has a parent, the we need to remove the pointers
        // that the parent has to this node.  The only case where a node
        // shouldn't have a parent is the case where we're removing the root.
        if(n->parent) { 
                // Since we know the BST property we can deduce easily which
                // child (left or right) we are by comparing our value to that
                // of our parent's.  If our parent's value is greater than ours
                // then we must be the left child.
                if(n->parent->data > n->data) {
                    // Remove our parent's pointer to us.
                    n->parent->left = 0;
                } else {
                    // Remove our parent's pointer to us.
                    n->parent->right = 0;
                }
        }
        // The followin four lines are responsible for removing the links that
        // our children hold to us.  We check to see if we have children if so,
        // we remove the parent links of each.
        if(n->left)
            n->left->parent = 0;
        if(n->right)
            n->right->parent = 0;

        // Next, we tidy up by nulling all links that we have out.  This is
        // just to safe so that no one tries to manipulate our tree via what
        // should be dead links.
        n->left=n->right=n->parent = 0;
        
        // Finally, since this node is no longer in use, then delete it.
        delete n;
    }


    // Removing a node from a BST must be done carefully.  It's broken into
    // three cases. 
    //
    // Case 1: The node is a leaf node (it has no children).  To do this,
    // simply remove the node and delete the parent's reference to it.
    //
    // Case 2: The node has only one child.  In this case, simply remove
    // yourself from the tree and have your parent point to your child and vice
    // versa.
    //
    // Case 3: You have two children.  There are several ways to address this, I
    // did so in one of the laziest.  Simply replace my value with that of my
    // right child.  Now, call removeHelper with my right child. This will
    // recursively move values up the tree until the point at which we're in
    // either case 1 or case 2 from above, at which case we just delete the
    // node.
    //
    // This function returns true if it successfully removed the node and false
    // otherwise.
    bool removeHelper(BSTNode<T> *candidate) {
        // First we check the sanity of our input.  If we were called with a
        // null pointer then we can't do anything, so return false.
        if(candidate == 0) 
            return false;

        // Now, we check to see if this is case 1.  Are we a leaf node?
        if(candidate->left == 0 && candidate->right == 0) {
            // If I am a leaf node, there's one special case.  The case where
            // I'm the root of the tree.
            if(candidate == root) {
                // If I'm the root and also a leif it means that we're removing
                // the last element in the tree and it should now be empty.
                // Thus we can delete the current root and make the root  
                // pointer be null.
                delete root;
                root = 0;

                // our tree is now empty, so we could say size=0, but this
                // should yield the same result.
                size --;
                
                // We've successfully removed the last element in the tree.
                return true;
            }
            
            // If we get here and we are a leif node but we're not the root then
            // something fishy has happened.  Wave your hands, look the other
            // way, and pretend that you couldn't delete the element.
            if(candidate->parent == 0)  {
                return false;
            }

            // If you got here then we know that we're just a normal leif node.
            // Remove all pointers to us and then delete this node.  This is all
            // done by the removeNode function.
            removeNode(candidate);
            return true;
        }

        // This test to see that we have exactly one child.  Recall that the ^
        // operator means exclusive or (XOR).  That is that only one, not both
        // are true.
        if((candidate->left == 0) ^ (candidate->right == 0)) {
            
            // This will point to our one child. 
            BSTNode<T> *child;

            // This will point to our parent.
            BSTNode<T> *par = candidate->parent;
            
            // We now set 'child' to point to our one child.
            if(candidate->left) {
                child = candidate->left;
            } else {
                child = candidate->right;
            }

            // Having found our one child we remove ourselves from the tree.
            removeNode(candidate);

            // Check to see if we were the root.
            if(candidate == root) {

                // If we were, then we just make our one child be the new root.
                root = child;
                return true;
            }  
            
            // If we get here this means that we're not the root and that we've
            // already removed ourselves from the tree.  So, link our child and
            // our parent together.
            child -> parent = par; 

            // This figures out which child we were of the parent and repoints
            // that link to the new child.
            if(child->data < par->data) {
                par->left = child;
            } else {
                par->right = child;
            }
            return true;
        }
        
        // Getting here means that we must have two children (case 3). So, we
        // set our value to be that of our right child, then try to recursively
        // remove the right child.
        candidate->data = candidate->right->data;

        return removeHelper(candidate->right); 
    }


public:

    // The BST constructor just initialized the root pointer to null and sets
    // the size to 0 since there's nothing in the tree yet.
    BST() {
        root = 0;
        size = 0;
    }

    // The destructor just calls destructorHelp.  Recall that destructorHelp
    // will recursively delte a subtree. So, we call it initially with root.
    ~BST() {
        destructorHelper(root);
    }

    // This is just an accessor function that returns the root of the tree.
    // Note that this returns a templated BSTNode.  Once again this is because
    // we want to be sure that our tree is homogenous -- that our nodes have
    // values of all the same type.
    BSTNode<T> *getRoot() {
        return root;
    }

    // Inserting a value into the tree.  This value is of type T.
    void insert(T v) {
        // First we check to see if we currently have a root.  
        if(!root) {
            // If we do not yet have a root (the tree was empty) then we make a
            // new node with this value and then make it be the root of our
            // tree.
            root = new BSTNode<T>(v);

            // Our tree now has a bigger size, so add 1.
            size++;
            return;
        } 

        // Getting here means that the tree is not empty, so we call the
        // insertHelper function with the root and the new value so that it can
        // insert the new node into the correct place in the tree.
        insertHelper(root, v);
    }


    // Find takes a value and an optional subtree in which to search for the
    // value.  It then returns the node which contains that value.  
    //
    // You may have not seen default parameters before.  Basically you can call
    // call this function in one of two ways:
    //      find(someValue);
    // or
    //      find(someValue, someSubTree);
    // If you omit the second parameter, it defaults the value of that parameter
    // to 0.  
    BSTNode<T> *find(T v, BSTNode<T> *n = 0) {
        // If our second parameter was 0 then we default it to be root instead.
        if(n == 0)  
            n = root;

        // Now, we check the current node to see if it has the value we're
        // looking for.
        if(n->data == v) 
            // if it does, then return this node.            
            return n;
        
        // If the value we're looking for is less than the value of this node
        // then by the BST property we know that it must be in the left subtree. 
        if(v < n->data) {
            // We make sure that there is a left subtree
            if(n->left)
                // If there is, then we recurse, checking this subtree for the
                // value and returning that node back to the caller.
                return find(v, n->left);
            else
                // If there is no left child that means that the element we're
                // looking for is not in the tree.  Return null.
                return 0;
        } else {
            // Similarly, we do all of the above but on the right subtree.
            if(n->right)
                return find(v, n->right);
            else
                return 0;
        } 

        // In the event we get here it means that the element must not be in the
        // tree. So, we'll return null to indicate this.
        return 0;
    }

    // remove is a public function that removes the node containing the value
    // 'v'.  
    bool remove(T v) {
        // First we find the pointer to this value.  Recall that removeHelper
        // can correctly deal with the case where you're trying to remove a null
        // pointer.  So if we can't find the value it will call removeHelper
        // with a null pointer. But this shouldn't be a problem. 
        return removeHelper(find(v));
    }

    // Get size is a public facing method that returns the size of our binary
    // tree.
    int getSize() {
        return size;
    }

    // We just want to allow our unit test special access to this class.
    friend void testBST1();
};

#endif
