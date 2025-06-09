#
#  Patrick Morrissey pmorriss morrisseypd369@gmail.com
#  makefile - Assignment 6 (Maze Generation with Union Sets)
#

p6: main.o disjoint_set.o maze.o
	g++ -o p6 main.o disjoint_set.o maze.o

main.o: main.cpp
	g++ -g -Wall -c main.cpp

disjoint_set.o: disjoint_set.cpp disjoint_set.h
	g++ -g -Wall -c disjoint_set.cpp

maze.o: maze.cpp maze.h
	g++ -g -Wall -c maze.cpp

clean:
	rm p6 *.o
