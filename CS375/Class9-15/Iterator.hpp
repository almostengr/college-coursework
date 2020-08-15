#ifndef __ITERATOR__
#define __ITERATOR__

template <class T>
class Iterator {
	//ITERATOR IS A WAY OF GOING OVER A COLLECTION OF THINGS
public:
	virtual bool hasMoreElements()=0;
	virtual void next() = 0;
	virtual int getValue()=0;;
};

#endif
