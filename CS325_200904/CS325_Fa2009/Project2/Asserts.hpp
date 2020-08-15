#include <iostream>
#include <cstdlib>

#define AssertEquals(b,v) do { \
		if(!((b)==(v))) {\
			std::cerr << __FILE__ << ":" << __LINE__ << ": ERROR: expected "\
					  <<v<< " in " << #b << " but got " << b << std::endl;\
			exit(1);\
		}\
	}while(0)

#define AssertTrue(b) AssertEquals(b,true)

#define AssertFalse(b) AssertEquals(b,false)


