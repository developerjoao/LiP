
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q1 build/main.o build/mb.o 


bin/q1: build/mb.o build/main.o
	$(CC) $^ -o $@


build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/mb.o : src/mb.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

clean:
	rm build/*.o

run:
	bin/q1
