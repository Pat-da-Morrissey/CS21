#
#  Patrick Morrissey pmorriss morrisseypd369@gmail.com
#  makefile - Assignment 05 (Hash Table)
#

p5: main.o hash.o
	g++ -o p5 main.o hash.o

main.o: main.cpp
	g++ -c main.cpp

hash.o: hash.cpp hash.h
	g++ -c hash.cpp

clean:
	rm -f p5 *.o 
