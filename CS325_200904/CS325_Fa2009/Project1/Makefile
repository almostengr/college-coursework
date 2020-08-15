all: project1

project1: main.cpp csv.o
	g++ -g -o project1 main.cpp csv.o

csv.o: csv.cpp csv.hpp
	g++ -g -c csv.cpp

run: project1
	./project1

clean:
	rm -rf *.o project1