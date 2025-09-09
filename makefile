CC = g++
CFLAGS = -Wall -Wextra -g -std=c++20
TARGET = alley_p1

all: alley_p1 test

test: alley_p1
	./alley_p1 sample_1.txt 0110 100 
	./alley_p1 sample_1.txt 0110 9 
	./alley_p1 sample_1.txt 021 20 
	./alley_p1 sample_2.txt 00001111 100
	./alley_p1 sample_2.txt 0001111 100
	./alley_p1 sample_2.txt 0000111 100
	./alley_p1 sample_2.txt 00001111 10

alley_p1: alley_p1.o
	$(CC) $(CFLAGS) -o alley_p1 alley_p1.o

alley_p1.o: alley_p1.cpp
	$(CC) $(CFLAGS) -c alley_p1.cpp

clean:
	rm -f alley_p1 *.o
