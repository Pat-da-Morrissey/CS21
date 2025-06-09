#My makefile for the 3 different files and their header files




p1: main.o LinkedList.o stack.o
	g++ -o p1 main.o LinkedList.o stack.o


main.o: main.cpp
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Stack.o: stack.cpp stack.h
	g++ -c stack.cpp


clean:
	rm -f foo p1 *.o *~
