# My makefile for the main and heap

p2: main.o heap.o
	g++ -o p2 main.o heap.o

main.o: main.cpp
	g++ -c main.cpp

heap.o: heap.cpp heap.h
	g++ -c heap.cpp

clean:
	rm -f foo p2 *.o *~
