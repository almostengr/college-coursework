all: test main
	
main: Main.cpp BST.hpp Iterator.hpp BSTIterator.hpp
	g++ -g -o $@ $<

test: testbst
	./testbst

testbst: TestBST.cpp BST.hpp
	g++ -g -o $@ $<

run: all 
	./main

clean: 
	clear
	rm main testbst
