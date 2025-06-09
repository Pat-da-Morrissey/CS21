#
# Patrick Morrissey pmorriss morrisseypd369@gmail.com
# Breadth-FirstSearch.cpp - Assignment 8 (Breadth-First Search)
#

p8: main.o Breadth-FirstSearch.o
	g++ -o p8 main.o Breadth-FirstSearch.o

main.o: main.cpp
	g++ -c main.cpp

Breadth-FirstSearch.o: Breadth-FirstSearch.cpp Breadth-FirstSearch.h
	g++ -c Breadth-FirstSearch.cpp

clean:
	rm p8 *.o
