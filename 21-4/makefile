# makefile for assignment 4

p4: main.o radixbucketsort.o
	g++ -o p4 main.o radixbucketsort.o

main.o: main.cpp
	g++ -c main.cpp

radixbucketsort.o: radixbucketsort.cpp radixbucketsort.h
	g++ -c radixbucketsort.cpp

clean:
	rm -f foo p4 *.o *~
