#ifndef __ITERATOR__
#define __ITERATOR__


// This is an interface to all iterators.  Every class that inherrits from this
// is contractually obligated to define the three methods defined here-in.  Note
// that this iterator is templated.  That is so that we can use it to iterate
// over collections with differing types.
template <class T>
class Iterator {
public:
    // Note that each of the following methods are virtual and =0. The virtual
    // means that we'll allow the later definitions of the methods to replace
    // these and the =0 says that we're deferring the definitions of these to
    // those classes which inherrit from us.  It's not really necessary to do
    // both, but it doesn't hurt.
    
    // hasMoreElements will return true as long as the iterator has more
    // elements to consume.
	virtual bool hasMoreElements()=0;
    
    // next() will move the iterator to the next value in the collection
	virtual void next() = 0;

    // getValue has return type T.  This is the value of the thing the iterator
    // is currently pointing at.
	virtual T getValue()=0;
};

#endif
