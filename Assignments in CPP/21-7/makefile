#
#  Patrick Morrissey pmorriss morrisseypd369@gmail.com
#  makefile - Assignment 07 (Binary Search Tree)
#

p7: main.o BinarySearchTree.o
	g++ -o p7 main.o BinarySearchTree.o

main.o: main.cpp
	g++ -g -Wall -c main.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -g -Wall -c BinarySearchTree.cpp

clean:
	rm p7 *.o
