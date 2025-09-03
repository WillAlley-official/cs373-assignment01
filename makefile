CC = g++
CFLAGS = -Wall -Wextra -g -std=c++20
TARGET = turingSim

all: turingSim

turingSim: turingSim.o
	$(CC) $(CFLAGS) -o turingSim turingSim.o

turingSim.o: turingSim.cpp
	$(CC) $(CFLAGS) -c turingSim.cpp 

clean:
	rm -f turingSim *.o
