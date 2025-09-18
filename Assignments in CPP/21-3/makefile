# My makefile for Assignment 03 (Quicksort)

p3: main.o quicksort.o
	g++ -o p3 main.o quicksort.o

main.o: main.cpp
	g++ -c main.cpp

quicksort.o: quicksort.cpp quicksort.h
	g++ -c quicksort.cpp

clean:
	rm -f foo p3 *.o *~
