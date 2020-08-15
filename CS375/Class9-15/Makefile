all: main

main: Main.cpp List.hpp Iterator.hpp Stack.o Node.o
	g++ -o main Main.cpp  Stack.o Node.o

Stack.o: Stack.cpp Stack.hpp Container.hpp
	g++ -c Stack.cpp

Node.o: Node.hpp Node.cpp
	g++ -c Node.cpp

run: main
	./main 

clean:
	rm main Stack.o Node.o
